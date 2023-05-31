#include "EthernetPhy.h"
#include "EthernetFrames_m.h"

Define_Module(EthernetPhy);

void EthernetPhy::initialize()
{
    datarate = par("datarate");
    txState = TX_IDLE_STATE;
    upperLayerIn = gate("upperLayerIn");
    sigQueueLen = registerSignal("QueueSize");
}

void EthernetPhy::handleMessage(cMessage *msg) {
    //frame contiene control info e pacchetto dati
    EthernetFrame *frame;

    //e il timer di trasmissione?
    if(msg->isSelfMessage()) {
        if(strcmp(msg->getName(), "TxTimer") == 0) {
            //rimuovo le control info di rooting ed invio al datalink (la destinazione ce dentro la frame campo dst)
            frame = check_and_cast<EthernetFrame *>(msg->removeControlInfo());
            delete msg;
            send(frame, "channelOut");

            //interframe gap (12 byte --> 96 bit)
            cMessage *ifgTimer = new cMessage("IFGTimer");
            scheduleAt(simTime()+SimTime(96.0/datarate), ifgTimer);
            txState = TX_IFG_STATE;
            return;

        } else {
            //e il timer di inter frame gap?
            if(strcmp(msg->getName(), "IFGTimer") == 0) {
                //tento trasmissione di nuova frame
                delete msg;
                checkAndTransmit();
                return;
            }
        }
    }

    //Sono a livello fisico - Se mi arriva una frame dal livello data link devo limitarmi ad inviarla
    frame = check_and_cast<EthernetFrame *>(msg);
    if(frame->getArrivalGate() == upperLayerIn) {
        //coda di trasmissione
        txQueue.insert(frame);
        emit(sigQueueLen, txQueue.getLength());
        if(txState==TX_IDLE_STATE) {
            checkAndTransmit();
            return;
        }
        return;
    }

    //Frame arrivata dalla rete -> la invio al data link
    if(frame->hasBitError() == false) {
        send(frame, "upperLayerOut");
    } else {
        delete frame;
    }
}

void EthernetPhy::checkAndTransmit() {
    if(!txQueue.isEmpty()) {
        //estraggo frame dalla coda (control info applicative + frame eth)
        EthernetFrame *frame = check_and_cast<EthernetFrame *>(txQueue.pop());

        emit(sigQueueLen, txQueue.getLength());

        //schedulo il timer di trasmissione
        cMessage *txtimer = new cMessage("TxTimer");
        double txt = (double)frame->getBitLength()/datarate;

        //aggancio come control info la frame da spedire così la posso recuperare
        txtimer->setControlInfo(frame);

        EV_DEBUG << "Trasmission time: " << txt << " - Byte: " << frame->getByteLength() << endl;

        scheduleAt(simTime()+SimTime(txt), txtimer);
        txState = TX_TX_STATE;
    } else {
        txState = TX_IDLE_STATE;
    }
}
