#include "PollingLayer.h"
#include "PollingPackets_m.h"
#include "ApplicationPackets_m.h"

Define_Module(PollingLayer);

void PollingLayer::initialize() {
    burstSize = par("burstSize");
    sigQueueLen = registerSignal("PollingQueueSize");
}

void PollingLayer::handleMessage(cMessage *msg) {
    //e un messaggio da TrafficGen
    if(msg->getArrivalGate() == gate("upperLayerIn")) {
        //pkt contiene application data e control info (control info contiene indirizzo destinazione)
        cPacket *pkt = check_and_cast<cPacket *>(msg);

        //creo pacchetto di polling
        PollingData *pdata = new PollingData("PollingDataPacket");
        //????????????
        pdata->setByteLength(6);
        pdata->encapsulate(pkt);

        //informazioni di rooting verso il polling master
        DataControlInfo *ci = dynamic_cast<DataControlInfo *>(pkt->removeControlInfo());
        pdata->setDestination(ci->getDestination());

        //cambio informazioni di rooting verso polling master
        ci->setDestination(par("controllerAddress").stringValue());
        pdata->setControlInfo(ci);

        appTxQueue.insert(pdata);
        emit(sigQueueLen, appTxQueue.getLength());

        return;
    }

    //e un messaggio dal dispatcher -> o è una polling request oppure è un messaggio rivolto a me
    PollingRequest *req = dynamic_cast<PollingRequest *>(msg);
    if(req != nullptr) {
        //e una polling request

        //e una polling request sul flusso da me prodotto?
        if(strcmp(par("flow").stringValue(), req->getFlow()) != 0) {
            delete req;
            return;
        }

        int numframe;
        if(req->getRequestedFrames() > 0) {
            numframe = req->getRequestedFrames();
        } else {
            numframe = burstSize;
        }

        //invio il numero di frame richiesto
        for(int i = 0; i < numframe && (!appTxQueue.isEmpty()); i++) {
            //estraggo il pacchetto dal buffer
            PollingData *pkt = check_and_cast<PollingData *>(appTxQueue.pop());
            //sequence number
            pkt->setTrxno(req->getTrxno());
            //check last frame di un burst
            if (i == (numframe-1)) {
                pkt->setLast(true);
            }

            emit(sigQueueLen, appTxQueue.getLength());

            EV_INFO << "Invio frame da polling layer per il flusso " <<  req->getFlow() << endl;

            send(pkt, "lowerLayerOut");
        }

        delete req;
        return;
    }

    //e un messaggio rivolto a me
    send(msg, "upperLayerOut");
}
