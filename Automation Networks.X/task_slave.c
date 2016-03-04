/* 
 * File:   task_slave.c
 * Author: mgradob
 *
 * Created on March 3, 2016, 12:36 AM
 */

#include "task_slave.h"
#include "uart.h"

void run_slave(unsigned long tick){
    static unsigned long tickAux = 0;
    
    if(tick-tickAux >= PERIOD_SLAVE){
        tickAux = tick;
        
        PORTBbits.RB7 ^= 1;
        
        if(readBuffer() != '\0'){
            if(strcmp(getBuffer(), CMD_ON) == 0) PORTBbits.RB0 = 1;
            else if(strcmp(getBuffer(), CMD_OFF) == 0) PORTBbits.RB0 = 0;
        }
        
        clearBuffer();
    }
}