/* 
 * File:   uart.h
 * Author: mgradob
 *
 * Created on January 29, 2016, 10:20 PM
 */

#ifndef UART_H
#define	UART_H

#include "config.h"

/**
 * Configure Serial Comm.
 */
void uart_config(void);

/**
 * Sends a byte.
 * @param data - byte to send.
 */
void send(unsigned char data);

/**
 * Sends a series of bytes.
 * @param string - the string to send.
 */
void sendstr(unsigned char *string);

#endif	/* UART_H */

