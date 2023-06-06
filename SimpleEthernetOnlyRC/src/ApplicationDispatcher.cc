#include "ApplicationDispatcher.h"

Define_Module(ApplicationDispatcher);

void ApplicationDispatcher::initialize() {

}

void ApplicationDispatcher::handleMessage(cMessage *msg) {
    //sono a livello applicativo - se mi arriva un messagio da sopra (TrafficGen) lo mando al livello fisico
    if(strcmp(msg->getArrivalGate()->getBaseName(), "upperLayerIn")==0) {
        send(msg, "lowerLayerOut");
    } else {
        //sono a livello applicativo - se mi arriva un messagio da sotto (EthInterface) lo mando a livello applicativo
        for(int i=0; i < gateSize("upperLayerOut"); i++) {
            send(msg->dup(), "upperLayerOut", i);
        }
        delete msg;
    }
}
