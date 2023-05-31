package simpleethernet.simulations;

import simpleethernet.EthernetHost;
import simpleethernet.EthernetSwitch;
import simpleethernet.TrafficGen;

//Struttura di rete: n host - m switch
network SimpleEthernetNet
{
    parameters:
        @display("bgb=1402.7899,803.58496");
        //porte dello switch senza polling master
        **.portCount = 10;
        //settare porte diverse per switch
    submodules:
        SW1: EthernetSwitch {
            @display("p=474.95123,351.85873;is=vl");
            
        }
        SW2: EthernetSwitch {
            @display("p=805.9075,351.85873;is=vl");
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
        PollingMaster: EthernetHost {
            @display("p=618.9462,39.4825");
        }
    connections:
        //link SW1 to SW2 porta 0
        SW1.channelOut[0] --> SW2.channelIn[0];
        SW2.channelOut[0] --> SW1.channelIn[0];

        //link SW1 to  LD1 porta 1
        LD1.channelOut --> SW1.channelIn[1];
        SW1.channelOut[2] --> LD1.channelIn;
        //link SW1 to  LD2 porta 2
        LD2.channelOut --> SW1.channelIn[1];
        SW1.channelOut[2] --> LD2.channelIn;
        //link SW1 to  US1 porta 3
        US1.channelOut --> SW1.channelIn[1];
        SW1.channelOut[2] --> US1.channelIn;
        //link SW1 to  US2 porta 4
        US2.channelOut --> SW1.channelIn[1];
        SW1.channelOut[2] --> US2.channelIn;
        //link SW1 to  CM1 porta 5
        CM1.channelOut --> SW1.channelIn[1];
        SW1.channelOut[2] --> CM1.channelIn;
        //link SW1 to  HU porta 6
        HU.channelOut --> SW1.channelIn[1];
        SW1.channelOut[2] --> HU.channelIn;
        //link SW1 to  CU porta 7
        CU.channelOut --> SW1.channelIn[1];
        SW1.channelOut[2] --> CU.channelIn;
        //link SW1 to  S1 porta 8
        S1.channelOut --> SW1.channelIn[1];
        SW1.channelOut[2] --> S1.channelIn;
        //link SW1 to  S2 porta 9
        S2.channelOut --> SW1.channelIn[1];
        SW1.channelOut[2] --> S2.channelIn;


        //link SW2 to  RS1 porta 1
        RS1.channelOut --> SW2.channelIn[1];
        SW2.channelOut[2] --> RS1.channelIn;
        //link SW2 to  RS2 porta 2
        RS2.channelOut --> SW2.channelIn[1];
        SW2.channelOut[2] --> RS2.channelIn;
        //link SW2 to  US3 porta 3
        US3.channelOut --> SW2.channelIn[1];
        SW2.channelOut[2] --> US3.channelIn;
        //link SW2 to  US4 porta 4
        US4.channelOut --> SW2.channelIn[1];
        SW2.channelOut[2] --> US4.channelIn;
        //link SW2 to  RC porta 5
        RC.channelOut --> SW2.channelIn[1];
        SW2.channelOut[2] --> RC.channelIn;
        //link SW2 to  TLM porta 6
        TLM.channelOut --> SW2.channelIn[1];
        SW2.channelOut[2] --> TLM.channelIn;
        //link SW2 to  ME porta 7
        ME.channelOut --> SW2.channelIn[1];
        SW2.channelOut[2] --> ME.channelIn;
        //link SW2 to  S3 porta 8
        S3.channelOut --> SW2.channelIn[1];
        SW2.channelOut[2] --> S3.channelIn;
        //link SW2 to  S4 porta 9
        S4.channelOut --> SW2.channelIn[1];
        SW2.channelOut[2] --> S4.channelIn;

}
