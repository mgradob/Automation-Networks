/* 
 * File:   task_supertask.h
 * Author: mgradob
 *
 * Created on February 19, 2016, 6:56 PM
 */

#ifndef TASK_SUPERTASK_H
#define	TASK_SUPERTASK_H

#include "config.h"

#define PERIOD_SLAVE   250    // task periodicity (ms)

#define CMD_ON      "AT+ID=1,LED=1\r\n"
#define CMD_OFF     "AT+ID=1,LED=0\r\n"

/**
 * Main method of the task
 * @param tick time track in ms.
 */
void run_slave(unsigned long tick);

#endif	/* TASK_SUPERTASK_H */

