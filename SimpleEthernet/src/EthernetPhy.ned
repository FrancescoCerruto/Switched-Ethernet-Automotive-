package simpleethernet;

//simulazione livello fisico
simple EthernetPhy
{
    parameters:
        double datarate @unit(bps) = default(1Gbps);
        //frequenza bit errati
        double netber = default(0);
        @display("i=block/mac");
        
        @signal[QueueSize];
        @statistic[QueueSize](record=vector,max);
    gates:
        input upperLayerIn;
        output upperLayerOut;
        input channelIn;
        output channelOut;
}
