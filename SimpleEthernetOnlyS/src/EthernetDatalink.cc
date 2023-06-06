#include "EthernetDatalink.h"
#include "EthernetFrames_m.h"
#include "ApplicationPackets_m.h"

Define_Module(EthernetDatalink);

void EthernetDatalink::initialize()
{
    lowerLayerIn = gate("lowerLayerIn");
    upperLayerIn = gate("upperLayerIn");

    //prendo il compund module
    srcName = getParentModule()->getFullPath();
}

void EthernetDatalink::handleMessage(cMessage *msg)
{
    //sono a livello datalink - mi viene un pacchetto da sopra (ApplicationDispatcher) -> lo giro al livello fisico
    if(msg->getArrivalGate() == upperLayerIn) {

        //cast per il send
        cPacket *pkt = check_and_cast<cPacket*>(msg);

        //prendo le control info perché devo sapere a chi devo destinare il messaggio applicativo
        DataControlInfo *ci = dynamic_cast<DataControlInfo*>(msg->removeControlInfo());
        if(ci == nullptr) {
            //termino la simulazione
            error("Mancano le control info");
        }

        //compongo la frame
        EthernetFrame *frame = new EthernetFrame("EthernetFrame");
        frame->setDst(ci->getDestination());
        frame->setSrc(srcName.c_str());

        if(pkt->getByteLength() < 46) {
            int pad = 46-pkt->getByteLength();
            pad += frame->getByteLength();
            frame->setByteLength(pad);
        }

        //in automatico somma bytelegth specificata con i byte di payload
        frame->encapsulate(pkt);

        //invio al livello fisico
        send(frame, "lowerLayerOut");
        delete ci;
        return;
    }

    //sono a livello datalink - mi viene un pacchetto da sotto (EthPhy) -> lo giro al livello applicativo
    EthernetFrame *et = check_and_cast<EthernetFrame*>(msg);

    //frame non destinata a me (unicast oppure broadcast)
    if(strcmp(et->getDst(), srcName.c_str()) != 0 && strcmp(et->getDst(), "broadcast") != 0) {
        delete et;
        return;
    }

    EV_DEBUG << "Ricevuta frame da: " << et->getSrc() << " di dim: " << et->getByteLength() << " bytes" << endl;

    //recupero i dati applicativi
    cPacket *rxpkt = et->decapsulate();
    send(rxpkt, "upperLayerOut");
    delete et;
}
