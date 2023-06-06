package simpleethernet;

//tabella di routing
simple RelayUnit
{
    parameters:
        @display("i=block/switch");
        //numero di porte dello switch
        int relayPortCount;
        //tabella di rooting
        object staticEntries = default(StaticRelayEntries { entries: [] });
    gates:
        input lowerLayerIn[relayPortCount];
        output lowerLayerOut[relayPortCount];
}
