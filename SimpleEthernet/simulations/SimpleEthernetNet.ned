package simpleethernet.simulations;

import simpleethernet.EthernetHost;
import simpleethernet.EthernetSwitch;
import simpleethernet.TrafficGen;

//Struttura di rete: n host - m switch
network SimpleEthernetNet
{
    parameters:
        @display("bgb=1402.7899,803.58496");
        //porte dello switch
        **.portCount = 3;
    submodules:
        switch0: EthernetSwitch {
            @display("p=474.95123,351.85873");
        }
        switch1: EthernetSwitch {
            @display("p=805.9075,351.85873");
        }
        LD2: EthernetHost {
            @display("p=88.255,126.57625");
        }
        US2: EthernetHost {
            @display("p=88.255,308.8925");
        }
        CM1: EthernetHost {
            @display("p=88.255,397.1475");
        }
        LD1: EthernetHost {
            @display("p=88.255,41.805");
        }
        US1: EthernetHost {
            @display("p=88.255,224.12125");
        }
        S2: EthernetHost {
            @display("p=88.255,745.52246");
        }
        CU: EthernetHost {
            @display("p=88.255,579.46375");
        }
        S1: EthernetHost {
            @display("p=88.255,671.2025");
        }
        HU: EthernetHost {
            @display("p=88.255,487.725");
        }
        S4: EthernetHost {
            @display("p=1213.5062,745.52246");
        }
        S3: EthernetHost {
            @display("p=1213.5062,671.2025");
        }
        US3: EthernetHost {
            @display("p=1221.635,224.12125");
        }
        ME: EthernetHost {
            @display("p=1213.5062,579.46375");
        }
        RC: EthernetHost {
            @display("p=1213.5062,397.1475");
        }
        TLM: EthernetHost {
            @display("p=1213.5062,487.725");
        }
        RS2: EthernetHost {
            @display("p=1221.635,126.57625");
        }
        RS1: EthernetHost {
            @display("p=1221.635,41.805");
        }
        US4: EthernetHost {
            @display("p=1221.635,308.8925");
        }
    connections:
        switch0.channelOut[0] --> switch1.channelIn[0];
        switch1.channelOut[0] --> switch0.channelIn[0];
}
