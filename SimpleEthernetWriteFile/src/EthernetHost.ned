package simpleethernet;

//n (AppCount) flussi applicativi
module EthernetHost
{
    parameters:
        @display("bgb=745,448;i=device/device");
        int AppCount = default(1);
        bool isPollingMaster = default(false);
    gates:
        output channelOut;
        input channelIn;
    submodules:
        eth: EthernetInterface {
            @display("p=344,350");
        }
        dispatcher: ApplicationDispatcher {
            @display("p=135,350");
        }
        app[AppCount]: TrafficGen {
            @display("p=135,63,r,70");
        }
        pollingLayer[AppCount]: PollingLayer {
            @display("p=135,152,r,70");
        }
        pollingMaster: PollingMaster if isPollingMaster == true {
            @display("p=344,63");
        }
    connections:
        dispatcher.lowerLayerOut --> eth.upperLayerIn;
        eth.upperLayerOut --> dispatcher.lowerLayerIn;
        eth.channelOut --> channelOut;
        channelIn --> eth.channelIn;
        for i=0..AppCount-1 {
            pollingLayer[i].lowerLayerOut --> dispatcher.upperLayerIn++;
            pollingLayer[i].lowerLayerIn <-- dispatcher.upperLayerOut++;
            app[i].lowerLayerOut --> pollingLayer[i].upperLayerIn;
            app[i].lowerLayerIn <-- pollingLayer[i].upperLayerOut;
        }
        pollingMaster.lowerLayerOut --> dispatcher.upperLayerIn++ if isPollingMaster == true;
        dispatcher.upperLayerOut++ --> pollingMaster.lowerLayerIn if isPollingMaster == true;
}
