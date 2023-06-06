package simpleethernet;

//buffer dati applicativi
simple PollingLayer {
    parameters:
    	@display("i=block/timer");
    	int burstSize;
    	string flow;
    	//indirizzo polling master
    	string controllerAddress;
    	
    	@signal[PollingQueueSize];
    	@statistic[PollingQueueSize](record=vector);
    gates:
        input lowerLayerIn;
        output lowerLayerOut;
        input upperLayerIn;
        output upperLayerOut;
}
