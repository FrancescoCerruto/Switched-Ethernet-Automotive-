#ifndef __SIMPLEETHERNET_POLLINGMASTER_H_
#define __SIMPLEETHERNET_POLLINGMASTER_H_

#include <omnetpp.h>
#include "PollingPackets_m.h"

using namespace omnetpp;

class PollingMaster : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

    virtual void sendNextPollRequest();

    static int poll_queue_comp(cObject *a, cObject *b);

  protected:
    FlowTableParameters *flowTable;
    //buffer di polling
    cPacketQueue pollQueue;
    //canale occupato
    bool ongoingTransaction;
    //timer ricezione polling data
    cMessage *trxTimer;
    //identificativo frame attesa
    uint64_t trxno;
    //istante di trasmissione
    simtime_t txTime;

    simsignal_t sigTrxTime;
};

#endif
