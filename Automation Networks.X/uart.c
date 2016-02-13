/* 
 * File:   uart.c
 * Author: mgradob
 *
 * Created on January 29, 2016, 10:21 PM
 */

#include "uart.h"

static unsigned char RX_BUF[RX_BUF_SIZE];   // Buffer that contains the data 
                                            // received from the UART ISR.
static unsigned char rx_index = 0;      // Index for the buffer.

void uart_config(){
    TRISC = 0b1000000;
    SPBRG = 12;
    TXSTA = 0b00100000;
    RCSTA = 0b10010000;
    PIE1bits.RCIE = 1;
    PIR1bits.RCIF = 0;
}

void send(unsigned char data){
    while(!TXIF);
    
    TXREG = data;
}

void sendstr(unsigned char *string){
    while(*string != '\0') send(*string++);
}

void saveByte(unsigned char byte){
    unsigned char x = 0;
    while(RX_BUF[x] != '\0') x++;
    RX_BUF[x] = byte;
}

unsigned char readBuffer(void){
    return RX_BUF[rx_index];
}

void nextByte(void){
    rx_index++;
}

void clearBuffer(void){
    unsigned char x = 0;
    for(x; RX_BUF[x] != '\0'; x++) RX_BUF[x] = '\0';
    
    rx_index = 0;
}