package simpleethernet.simulations;

import simpleethernet.EthernetHost;
import simpleethernet.EthernetSwitch;
import simpleethernet.TrafficGen;

//Struttura di rete: n host - m switch
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
            @display("p=73.815,170.4775");
        }
        US2: EthernetHost {
            @display("p=73.815,351.5");
        }
        CM1: EthernetHost {
            @display("p=73.815,439.375");
        }
        LD1: EthernetHost {
            @display("p=73.815,84.36");
        }
        US1: EthernetHost {
            @display("p=73.815,267.13998");
        }
        S2: EthernetHost {
            @display("p=73.815,789.1175");
        }
        CU: EthernetHost {
            @display("p=73.815,622.15497");
        }
        S1: EthernetHost {
            @display("p=73.815,713.545");
        }
        HU: EthernetHost {
            @display("p=73.815,530.765");
        }
        S4: EthernetHost {
            @display("p=1569.4475,789.1175");
        }
        S3: EthernetHost {
            @display("p=1569.4475,713.545");
        }
        US3: EthernetHost {
            @display("p=1578.235,267.13998");
        }
        ME: EthernetHost {
            @display("p=1569.4475,622.15497");
        }
        RC: EthernetHost {
            @display("p=1569.4475,439.375");
        }
        TLM: EthernetHost {
            @display("p=1569.4475,530.765");
        }
        RS2: EthernetHost {
            @display("p=1578.235,170.4775");
        }
        RS1: EthernetHost {
            @display("p=1578.235,84.36");
        }
        US4: EthernetHost {
            @display("p=1578.235,351.5");
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
