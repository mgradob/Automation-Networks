/* 
 * File:   timer.c
 * Author: mgradob
 *
 * Created on January 28, 2016, 12:08 AM
 */

#include "timer0.h"

void timer0_config(){
    //Timer0 Registers Prescaler= 8 - TMR0 Preset = 6 - Freq = 1000.00 Hz - Period = 0.001000 seconds
    OPTION_REGbits.T0CS = 0;  // bit 5  TMR0 Clock Source Select bit...0 = Internal Clock (CLKO) 1 = Transition on T0CKI pin
    OPTION_REGbits.T0SE = 0;  // bit 4 TMR0 Source Edge Select bit 0 = low/high 1 = high/low
    OPTION_REGbits.PSA = 0;   // bit 3  Prescaler Assignment bit...0 = Prescaler is assigned to the Timer0
    OPTION_REGbits.PS2 = 0;   // bits 2-0  PS2:PS0: Prescaler Rate Select bits
    OPTION_REGbits.PS1 = 1;
    OPTION_REGbits.PS0 = 0;
    TMR0 = 6;             // preset for timer register

    INTCONbits.T0IF = 0;
    INTCONbits.T0IE = 1;
}