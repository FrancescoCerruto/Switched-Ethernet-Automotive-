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
            portCount = 4;
        }
        SW2: EthernetSwitch {
            @display("p=1065.045,407.74;is=vl");
            portCount = 6;
        }
        S2: EthernetHost {
            @display("p=643.245,833.055");
        }
        S1: EthernetHost {
            @display("p=397.195,833.055");
        }
        S4: EthernetHost {
            @display("p=1065.045,833.055");
        }
        S3: EthernetHost {
            @display("p=1302.3075,833.055");
        }
        ME: EthernetHost {
            @display("p=1500.905,833.055");
        }
        RS2: EthernetHost {
            @display("p=1302.3075,100.1775");
        }
        RS1: EthernetHost {
            @display("p=1065.045,100.1775");
        }
        PollingMaster: EthernetHost {
            @display("p=643.245,128.2975");
        }
    connections:
        //link SW1 to SW2 porta 0
        SW1.channelOut[0] --> SW2.channelIn[0];
        SW2.channelOut[0] --> SW1.channelIn[0];

        //link SW1 to  S1 porta 8
        S1.channelOut --> SW1.channelIn[1];
        SW1.channelOut[1] --> S1.channelIn;
        //link SW1 to  S2 porta 9
        S2.channelOut --> SW1.channelIn[2];
        SW1.channelOut[2] --> S2.channelIn;


        //link SW2 to  RS1 porta 1
        RS1.channelOut --> SW2.channelIn[1];
        SW2.channelOut[1] --> RS1.channelIn;
        //link SW2 to  RS2 porta 2
        RS2.channelOut --> SW2.channelIn[2];
        SW2.channelOut[2] --> RS2.channelIn;
        //link SW2 to  ME porta 7
        ME.channelOut --> SW2.channelIn[3];
        SW2.channelOut[3] --> ME.channelIn;
        //link SW2 to  S3 porta 8
        S3.channelOut --> SW2.channelIn[4];
        SW2.channelOut[4] --> S3.channelIn;
        //link SW2 to  S4 porta 9
        S4.channelOut --> SW2.channelIn[5];
        SW2.channelOut[5] --> S4.channelIn;

        //link SW1 to PollingMaster porta 10
        PollingMaster.channelOut --> SW1.channelIn[3];
        SW1.channelOut[3] --> PollingMaster.channelIn;
}
