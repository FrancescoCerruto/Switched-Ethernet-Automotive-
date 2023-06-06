#ifndef __SIMPLEETHERNET_TRAFFICGEN_H_
#define __SIMPLEETHERNET_TRAFFICGEN_H_

#include <omnetpp.h>

using namespace omnetpp;

class TrafficGen : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

    //invia il burst di frame
    virtual void generate();

    //periodo di trasmissione
    cMessage *txTimer;

    simsignal_t sigE2eDelay;
    simsignal_t sigBurstE2eDelay;
    simsignal_t sigThroughput;
    simsignal_t sigFLR;

    uint64_t totBit;
    //sequence number di trasmissione
    uint64_t TxSeqno;
    //sequence number di ricezione (ultimo arrivato)
    uint64_t RxSeqno;
    //numero di pacchetti persi rispetto ultimo arrivato
    uint64_t rxLost;
    //numero di pacchetti totali ricevuti
    uint64_t rxTot;
};

#endif
