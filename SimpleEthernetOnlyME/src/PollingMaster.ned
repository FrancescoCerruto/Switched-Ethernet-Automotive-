package simpleethernet;

//nodo polling
simple PollingMaster
{
    parameters:
        //memoria dei flussi e dei relativi parametri
        object flowTable = default(FlowTableParameters { flows: [] });
        //politica di scheduling
        string schedPolicy @enum("EDF","DM","FIFO") = default("DM");
        //tempo di transazione (tempo di andata e ritorno di una frame)
        double trxTimer @unit(s) = default(1ms);
        
        @display("i=block/cogwheel");
        
        @signal[TrxTime];
        @statistic[TrxTime](record=vector);
    gates:
        output lowerLayerOut;
        input lowerLayerIn;
}
