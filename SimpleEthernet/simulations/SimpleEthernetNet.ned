package simpleethernet.simulations;

import simpleethernet.EthernetHost;
import simpleethernet.EthernetSwitch;
import simpleethernet.TrafficGen;

network SimpleEthernetNet
{
    parameters:
        @display("bgb=1692.4724,975.4125");
    submodules:
        SW1: EthernetSwitch {
            @display("p=643.245,407.74;is=vl");
            portCount = 11;
        }
        SW2: EthernetSwitch {
            @display("p=1065.045,407.74;is=vl");
            portCount = 10;
        }
        LD2: EthernetHost {
            @display("p=217.93,84.36");
        }
        US2: EthernetHost {
            @display("p=73.815,407.74");
        }
        CM1: EthernetHost {
            @display("p=73.815,578.21747");
        }
        LD1: EthernetHost {
            @display("p=397.195,84.36");
        }
        US1: EthernetHost {
            @display("p=73.815,214.415");
        }
        S2: EthernetHost {
            @display("p=643.245,833.055");
        }
        CU: EthernetHost {
            @display("p=217.93,833.055");
        }
        S1: EthernetHost {
            @display("p=397.195,833.055");
        }
        HU: EthernetHost {
            @display("p=93.1475,757.4825");
        }
        S4: EthernetHost {
            @display("p=1065.045,833.055");
        }
        S3: EthernetHost {
            @display("p=1302.3075,833.055");
        }
        US3: EthernetHost {
            @display("p=1500.905,214.415");
        }
        ME: EthernetHost {
            @display("p=1500.905,833.055");
        }
        RC: EthernetHost {
            @display("p=1609.87,560.6425");
        }
        TLM: EthernetHost {
            @display("p=1609.87,757.4825");
        }
        RS2: EthernetHost {
            @display("p=1302.3075,100.1775");
        }
        RS1: EthernetHost {
            @display("p=1065.045,100.1775");
        }
        US4: EthernetHost {
            @display("p=1578.235,351.5");
        }
        PollingMaster: EthernetHost {
            @display("p=643.245,128.2975");
        }
    connections:
        //link SW1 to SW2 porta 0
        SW1.channelOut[0] --> SW2.channelIn[0];
        SW2.channelOut[0] --> SW1.channelIn[0];

        //link SW1 to  LD1 porta 1
        LD1.channelOut --> SW1.channelIn[1];
        SW1.channelOut[1] --> LD1.channelIn;
        //link SW1 to  LD2 porta 2
        LD2.channelOut --> SW1.channelIn[2];
        SW1.channelOut[2] --> LD2.channelIn;
        //link SW1 to  US1 porta 3
        US1.channelOut --> SW1.channelIn[3];
        SW1.channelOut[3] --> US1.channelIn;
        //link SW1 to  US2 porta 4
        US2.channelOut --> SW1.channelIn[4];
        SW1.channelOut[4] --> US2.channelIn;
        //link SW1 to  CM1 porta 5
        CM1.channelOut --> SW1.channelIn[5];
        SW1.channelOut[5] --> CM1.channelIn;
        //link SW1 to  HU porta 6
        HU.channelOut --> SW1.channelIn[6];
        SW1.channelOut[6] --> HU.channelIn;
        //link SW1 to  CU porta 7
        CU.channelOut --> SW1.channelIn[7];
        SW1.channelOut[7] --> CU.channelIn;
        //link SW1 to  S1 porta 8
        S1.channelOut --> SW1.channelIn[8];
        SW1.channelOut[8] --> S1.channelIn;
        //link SW1 to  S2 porta 9
        S2.channelOut --> SW1.channelIn[9];
        SW1.channelOut[9] --> S2.channelIn;


        //link SW2 to  RS1 porta 1
        RS1.channelOut --> SW2.channelIn[1];
        SW2.channelOut[1] --> RS1.channelIn;
        //link SW2 to  RS2 porta 2
        RS2.channelOut --> SW2.channelIn[2];
        SW2.channelOut[2] --> RS2.channelIn;
        //link SW2 to  US3 porta 3
        US3.channelOut --> SW2.channelIn[3];
        SW2.channelOut[3] --> US3.channelIn;
        //link SW2 to  US4 porta 4
        US4.channelOut --> SW2.channelIn[4];
        SW2.channelOut[4] --> US4.channelIn;
        //link SW2 to  RC porta 5
        RC.channelOut --> SW2.channelIn[5];
        SW2.channelOut[5] --> RC.channelIn;
        //link SW2 to  TLM porta 6
        TLM.channelOut --> SW2.channelIn[6];
        SW2.channelOut[6] --> TLM.channelIn;
        //link SW2 to  ME porta 7
        ME.channelOut --> SW2.channelIn[7];
        SW2.channelOut[7] --> ME.channelIn;
        //link SW2 to  S3 porta 8
        S3.channelOut --> SW2.channelIn[8];
        SW2.channelOut[8] --> S3.channelIn;
        //link SW2 to  S4 porta 9
        S4.channelOut --> SW2.channelIn[9];
        SW2.channelOut[9] --> S4.channelIn;

        //link SW1 to PollingMaster porta 10
        PollingMaster.channelOut --> SW1.channelIn[10];
        SW1.channelOut[10] --> PollingMaster.channelIn;
}
