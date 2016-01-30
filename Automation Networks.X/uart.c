/* 
 * File:   uart.c
 * Author: mgradob
 *
 * Created on January 29, 2016, 10:21 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "uart.h"

void uart_config(){
    // Configure Baud Rate to 8Mhz.
    SPBRG = 12;
    BRGH = 0;
    SYNC = 0;
    
    SPEN = 1; // Enable UART Asynchronous.
    
    TXEN = 1; // Enable transmissions.
}

void send(unsigned char data){
    while(!TXIF);
    
    TXREG = data;
}

void sendstr(unsigned char *string){
    while(*string != '\0') send(*string++);
}