package simpleethernet;

//punto di comunicazione tra livello fisico e livello applicativo
module EthernetInterface
{
    @display("bgb=307,401;i=block/ifcard");
    gates:
        //punto di contatto tra livelli fisici
        input channelIn;
        output channelOut;
        
        //punto di contatto tra livello applicativo e fisico
        input upperLayerIn;
        output upperLayerOut;
    submodules:
        dll: EthernetDatalink {
            @display("p=140,92");
        }
        phy: EthernetPhy {
            @display("p=140,304");
        }
    connections:
        dll.lowerLayerOut --> phy.upperLayerIn;
        phy.upperLayerOut --> dll.lowerLayerIn;
        phy.channelOut --> channelOut;
        channelIn --> phy.channelIn;
        dll.upperLayerOut --> upperLayerOut;
        upperLayerIn --> dll.upperLayerIn;
}
