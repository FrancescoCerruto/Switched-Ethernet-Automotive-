#include "PollingMaster.h"
#include "ApplicationPackets_m.h"

Define_Module(PollingMaster);

void PollingMaster::initialize() {
    pollQueue = cPacketQueue(0, poll_queue_comp);
    flowTable = check_and_cast<FlowTableParameters *>(par("flowTable").objectValue());
    ongoingTransaction = false;

    trxTimer = new cMessage("TrxTimer");
    trxno = 0;

    sigTrxTime = registerSignal("TrxTime");

    //creo poll di timer per l'interrogazione
    for(int i=0; i < flowTable->getFlowsArraySize(); i++) {
        cMessage *tmr = new cMessage("PollTimer");
        //il kind del timer mi indica l'entry della flow table da considerare
        tmr->setKind(i);
        scheduleAt(flowTable->getFlows(i).period, tmr);
    }
}

/**
 * il polling master si vede arrivare o timer  di schedulazione (risposta) oppure polling data
 */
void PollingMaster::handleMessage(cMessage *msg) {
    if(msg->isSelfMessage()) {
        //o e il timer di trasmissione oppure quello di ricezione
        if(strcmp(msg->getName(), "PollTimer") == 0) {
            //e il timer di trasmissione --> invio una poll request

            //recupero dati di configurazione del flusso
            int i = msg->getKind();
            FlowTableEntry f = flowTable->getFlows(i);

            //creo la poll request
            PollingRequest *pr = new PollingRequest("PollingRequest");
            //nome flow
            pr->setFlow(f.flow.c_str());
            //burst size
            pr->setRequestedFrames(f.burst);
            //priorità
            if(strcmp(par("schedPolicy").stringValue(), "DM") == 0) {
                pr->setPriority(f.deadline.inUnit(SimTimeUnit::SIMTIME_US));
            } else {
                if(strcmp(par("schedPolicy").stringValue(), "EDF") == 0) {
                    long d = (f.deadline+simTime()).inUnit(SimTimeUnit::SIMTIME_US);
                    pr->setPriority(d);
                } else {
                    pr->setPriority(0);
                }
            }
            //informazioni di rooting
            DataControlInfo *ci = new DataControlInfo();
            ci->setDestination(f.addr.c_str());
            pr->setControlInfo(ci);

            //push poll request
            pollQueue.insert(pr);

            //rischedulo il timer
            scheduleAt(simTime()+f.period, msg);

            sendNextPollRequest();

            return;
        } else {
            if(strcmp(msg->getName(), "TrxTimer") == 0) {
                //e il timer di ricezione

                EV_INFO << "Transazione non completata in tempo" << endl;
                ongoingTransaction = false;
                sendNextPollRequest();
                return;
            }
        }
    }

    PollingData *pd = dynamic_cast<PollingData *>(msg);
    if(pd != nullptr) {
        if(pd->getTrxno() != trxno) {
            error("Pacchetto arrivato fuori tempo massimo!");
        }
        emit(sigTrxTime, simTime()-txTime);

        //invio il pacchetto al nodo destinatario
        //recupero l'application packet con control info
        cPacket *to_send = pd->decapsulate();
        //informazioni di rooting verso nodo destinazione
        DataControlInfo *ci = new DataControlInfo();
        ci->setDestination(pd->getDestination());
        to_send->setControlInfo(ci);
        //check burst size
        if(pd->getLast()) {
            ongoingTransaction = false;
            cancelEvent(trxTimer);
        }
        delete pd;
        send(to_send, "lowerLayerOut");
        sendNextPollRequest();
        return;
    }

    delete msg;
}

void PollingMaster::sendNextPollRequest() {
    if(!ongoingTransaction && !pollQueue.isEmpty()) {
        ongoingTransaction = true;
        PollingRequest *pr = check_and_cast<PollingRequest *>(pollQueue.pop());
        trxno++;
        pr->setTrxno(trxno);
        txTime = simTime();
        send(pr, "lowerLayerOut");
        scheduleAt(simTime()+par("trxTimer"), trxTimer);
    }
}

int PollingMaster::poll_queue_comp(cObject *a, cObject *b) {
    PollingRequest *ta = check_and_cast<PollingRequest *>(a);
    PollingRequest *tb = check_and_cast<PollingRequest *>(b);

    return (tb->getPriority()-ta->getPriority());
}
