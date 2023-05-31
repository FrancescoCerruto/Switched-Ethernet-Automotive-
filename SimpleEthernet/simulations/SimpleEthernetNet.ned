package simpleethernet.simulations;

import simpleethernet.EthernetHost;
import simpleethernet.EthernetSwitch;
import simpleethernet.TrafficGen;

//Struttura di rete: n host - m switch
network SimpleEthernetNet
{
    parameters:
        @display("bgb=925.275,498.225");
        //porte dello switch
        **.portCount = 3;
    submodules:
        switch0: EthernetSwitch {
            @display("p=279.225,217.905");
        }
        switch1: EthernetSwitch {
            @display("p=568.305,217.905");
        }
        host0: EthernetHost {
            @display("p=129.21,105.12");
        }
        host1: EthernetHost {
            @display("p=129.21,307.695");
        }
        host2: EthernetHost {
            @display("p=739.125,307.695");
        }
        host3: EthernetHost {
            @display("p=739.125,105.12");
        }
    connections:
        switch0.channelOut[0] --> switch1.channelIn[0];
        switch1.channelOut[0] --> switch0.channelIn[0];
        switch0.channelOut[1] --> host0.channelIn;
        host0.channelOut --> switch0.channelIn[1];
        switch0.channelOut[2] --> host1.channelIn;
        host1.channelOut --> switch0.channelIn[2];
        switch1.channelOut[1] --> host2.channelIn;
        host2.channelOut --> switch1.channelIn[1];
        host3.channelOut --> switch1.channelIn[2];
        switch1.channelOut[2] --> host3.channelIn;
}
