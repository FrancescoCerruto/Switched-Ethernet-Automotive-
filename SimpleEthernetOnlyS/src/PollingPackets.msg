packet PollingRequest {
    string flow;	//6 byte
    int requestedFrames;	//4 byte
    long priority;	//4 byte
    uint64_t trxno;	//8 byte
    byteLength = 22;
};

packet PollingData {
    string destination;	//6 byte
    uint64_t trxno;	//8 byte
    bool last = false;	//1 byte
    byteLength = 15;
};

struct FlowTableEntry {
    string flow;	//nome del flusso
    string addr;	//indirizzo sorgente flusso
    int burst;
    simtime_t period;	//periodo traffic gen
    simtime_t deadline;
};

class FlowTableParameters extends cOwnedObject {
    FlowTableEntry flows[];
};