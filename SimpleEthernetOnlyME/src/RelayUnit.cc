#include "RelayUnit.h"

Define_Module(RelayUnit);

void RelayUnit::initialize() {
    //recupero le informazioni di configurazione dello switch
    StaticRelayEntries *te = check_and_cast<StaticRelayEntries *>(par("staticEntries").objectValue());
    for(int i = 0; i < te->getEntriesArraySize(); i++) {
        //creo la mia tabella
        RelayTableEntry rte = te->getEntries(i);
        table_entry_t *te = new table_entry_t;
        te->addr = rte.addr.str();
        te->port = rte.port;    //identifico la porta con il gate di arrivo
        te->staticEntry = true;
        te->updateTime = simTime();
        relayTable.push_back(te);
    }
}

void RelayUnit::handleMessage(cMessage *msg) {
    //recupero porta dello switch
    int idx = msg->getArrivalGate()->getIndex();

    EV_INFO << "Sono il modulo " << getParentModule()->getFullPath() << " e mi e arrivata una frame." << endl;

    //recupero frame
    EthernetFrame *frame = check_and_cast<EthernetFrame *>(msg);

    EV_INFO << "Inviata da " << frame->getSrc() << " e diretta a " << frame->getDst() << endl;

    //aggiorno porta di ingresso switch
    updateTableEntry(idx, frame->getSrc());

    //recupero porta di destinazione
    int didx = getPortFromAddr(frame->getDst());

    if(didx < 0) {
        //se non c'è una porta di destinazione mando in broadcast
        for(int i=0; i< gateSize("lowerLayerOut"); i++) {
            if(i != idx) {
                send(frame->dup(), "lowerLayerOut", i);
            }
        }
        delete frame;
        return;
    }

    //mando al livello fisico
    send(frame, "lowerLayerOut", didx);
}

void RelayUnit::updateTableEntry(int port, const char *addr) {
    //recupero porta dello switch
    int p = getPortFromAddr(addr);

    if(p < 0) {
        //flusso inesistente
        table_entry_t *entry = new table_entry_t;
        entry->addr = std::string(addr);
        entry->port = port;
        entry->staticEntry = false;
        entry->updateTime = simTime();
        relayTable.push_back(entry);
        return;
    }

    //aggiorno l'update time flusso già previsto
    for(int i=0; i<relayTable.size(); i++) {
        if(strcmp(addr, relayTable[i]->addr.c_str()) == 0) {
            if(!relayTable[i]->staticEntry) {
                relayTable[i]->port = port;
                relayTable[i]->updateTime = simTime();
            }
        }
    }
}

int RelayUnit::getPortFromAddr(const char *addr) {
    for(int i=0; i<relayTable.size(); i++) {
        if(strcmp(addr, relayTable[i]->addr.c_str()) == 0) {
            return relayTable[i]->port;
        }
    }
    return -1;
}
