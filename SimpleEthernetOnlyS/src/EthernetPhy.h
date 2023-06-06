#ifndef __SIMPLEETHERNET_ETHERNETPHY_H_
#define __SIMPLEETHERNET_ETHERNETPHY_H_

#include <omnetpp.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class EthernetPhy : public cSimpleModule
{
  protected:
    //stato livello fisico
    typedef enum {
        TX_IDLE_STATE,  //non ho nulla da trasmettere
        TX_TX_STATE,    //sto trasmettendo
        TX_IFG_STATE    //inter frame gap
    } tx_state_t;

    double ber;


    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

    virtual void checkAndTransmit();

  protected:
    //bitrate
    double datarate;
    //stato livello fisico
    tx_state_t txState;
    //coda di trasmissione
    cPacketQueue txQueue;
    //porta di comunicazione con data link
    cGate *upperLayerIn;


    simsignal_t sigQueueLen;

};

#endif
