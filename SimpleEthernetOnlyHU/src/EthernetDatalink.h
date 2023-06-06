#ifndef __SIMPLEETHERNET_ETHERNETDATALINK_H_
#define __SIMPLEETHERNET_ETHERNETDATALINK_H_

#include <omnetpp.h>

using namespace omnetpp;

class EthernetDatalink : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

  protected:
    cGate *lowerLayerIn;
    cGate *upperLayerIn;
    //uso il mio nome come indirizzo MAC sorgente
    std::string srcName;
};

#endif
