/* 
 * File:   helloWorld.h
 * Author: mgradob
 *
 * Created on February 3, 2016, 12:34 AM
 */

#ifndef HELLOWORLD_H
#define	HELLOWORLD_H

#include "config.h"

#define PERIOD_HELLOWORLD   3000    // task periodicity (ms)

#define SLV1_ON         "AT+ID=1,LED=1\r\n"
#define SLV1_OFF        "AT+ID=1,LED=0\r\n"
#define SLV2_ON         "AT+ID=2,LED=1\r\n"
#define SLV2_OFF        "AT+ID=2,LED=0\r\n"

typedef enum {
    SEND_TO_SLV_1 = 1,
    SEND_TO_SLV_2
} STATES;

typedef enum {
    SEND_OFF = 0,
    SEND_ON
} CMD_STATE;

/**
 * Main method of the task
 * @param tick time track in ms.
 */
void run_helloworld(unsigned long tick);

#endif	/* HELLOWORLD_H */

