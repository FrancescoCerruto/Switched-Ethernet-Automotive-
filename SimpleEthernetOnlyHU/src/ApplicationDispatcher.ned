package simpleethernet;

//ci sono AppCount porte verso sopra ed 1 sola verso giu 
simple ApplicationDispatcher
{
    @display("i=block/dispatch");
    gates:
        output upperLayerOut[];
        input upperLayerIn[];
        output lowerLayerOut;
        input lowerLayerIn;
}
