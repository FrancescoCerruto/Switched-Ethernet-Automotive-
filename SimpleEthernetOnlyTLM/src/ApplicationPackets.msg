//messaggio applicativo
packet DataPacket {
    //mi serve per il calcolo dell'end to end delay
    simtime_t genTime;
    uint64_t seqno;
    bool lastBurstPacket = false;
};

//informazioni necessarie per il rooting del livello fisico
message DataControlInfo {
    string destination;	//destinazione flusso
};
