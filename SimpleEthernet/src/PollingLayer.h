#ifndef __SIMPLEETHERNET_POLLINGLAYER_H_
#define __SIMPLEETHERNET_POLLINGLAYER_H_

#include <omnetpp.h>

using namespace omnetpp;

class PollingLayer : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

  protected:
    //buffer dati applicativi
    cPacketQueue appTxQueue;
    //n messaggi da inviare
    int burstSize;
    simsignal_t sigQueueLen;
};

#endif
