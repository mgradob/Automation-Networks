/* 
 * File:   uart.h
 * Author: mgradob
 *
 * Created on January 29, 2016, 10:20 PM
 */

#ifndef UART_H
#define	UART_H

#include "config.h"

#define RX_BUF_SIZE     50

/**
 * Configures the serial Comm.
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

/**
 * Saves a byte to the receive buffer.
 * @param byte
 */
void saveByte(unsigned char byte);

/**
 * Reads a byte from the buffer.
 * @return 
 */
unsigned char readBuffer(void);

/**
 * Moves to the next byte in the buffer.
 */
void nextByte(void);

/**
 * Clears the buffer and resets the index to the first position of the buffer.
 */
void clearBuffer(void);

#endif	/* UART_H */