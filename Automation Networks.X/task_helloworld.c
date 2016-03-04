/* 
 * File:   task_helloworld.c
 * Author: mgradob
 *
 * Created on February 3, 2016, 12:36 AM
 */

#include "task_helloworld.h"
#include "uart.h"

//extern unsigned char RX_BUF[RX_BUF_SIZE];

STATES taskState = SEND_TO_SLV_1;
CMD_STATE cmdStateSlv1 = SEND_OFF;
CMD_STATE cmdStateSlv2 = SEND_OFF;

void run_helloworld(unsigned long tick){
    static unsigned long tickAux = 0;
    
    if(tick-tickAux >= PERIOD_HELLOWORLD){
        tickAux = tick;
        
//        send(RX_BUF[0]);
        
        switch(taskState){
            case SEND_TO_SLV_1:
                if(cmdStateSlv1 == SEND_OFF){
                    sendstr(SLV1_OFF);
                    cmdStateSlv1 = SEND_ON;
                } else {
                    sendstr(SLV1_ON);
                    cmdStateSlv1 = SEND_OFF;
                }
                
                taskState = SEND_TO_SLV_2;
                break;
            case SEND_TO_SLV_2:
                if(cmdStateSlv2 == SEND_OFF){
                    sendstr(SLV2_OFF);
                    cmdStateSlv2 = SEND_ON;
                } else {
                    sendstr(SLV2_ON);
                    cmdStateSlv2 = SEND_OFF;
                }
                
                taskState = SEND_TO_SLV_1;
                break;
            default: break;
        }
        
        PORTBbits.RB0 ^= 1;
    }
}