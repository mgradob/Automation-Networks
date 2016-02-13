/* 
 * File:   main.c
 * Author: mgradob
 *
 * Created on January 27, 2016, 11:24 PM
 */

#include "config.h"

#include "timer0.h"
#include "uart.h"

#include "task_helloworld.h"

unsigned long msCount = 0; 

/**
 * ISR for the project.
 */
void interrupt mIsr(void){
    if(T0IF){
        T0IF = 0;
        
        msCount++;
    }
    
    if(RCIF){
        saveByte(RCREG);
    }
}

/**
 * Main function.
 */
void main(void){
    configMcu();
    
    while(1){
        run_helloworld(msCount);
    }
}

void configMcu(void){
    // Configure MCU
    OSCCON = 0b01110001;
    ANSEL = 0x00;
    TRISB = 0x00;
    
    // Configure modules
    timer0_config();
    uart_config();
    
    // Global & peripherial interrupts
    PEIE = 1;
    GIE = 1;
}