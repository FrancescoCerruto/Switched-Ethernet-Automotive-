package simpleethernet;

//si occupa di creare/scompattare le frame
simple EthernetDatalink
{
    @display("i=block/layer");
    gates:
        output lowerLayerOut;
        input lowerLayerIn;
        output upperLayerOut;
        input upperLayerIn;
}
