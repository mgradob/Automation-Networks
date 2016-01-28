/* 
 * File:   main.c
 * Author: mgradob
 *
 * Created on January 27, 2016, 11:24 PM
 */

#include "config.h"

unsigned long msCount = 0; 

/**
 * ISR for the project.
 */
void interrupt mIsr(void){
    if(INTCONbits.T0IE && INTCONbits.T0IF){
        INTCONbits.T0IF = 0;
        
        msCount++;
    }
}

/**
 * Main function.
 */
void main(void){
    configMcu();
    
    while(1){
        
    }
}

void configMcu(void){
    // Configure Timer0
    timer0_config();
    
    INTCONbits.GIE = 1;
}