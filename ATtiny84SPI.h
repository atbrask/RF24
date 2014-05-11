/*
Simple USI-SPI master driver for the ATtiny84.
Copyright (c) 2014 A.T.Brask <atbrask@gmail.com>

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT 
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS 
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef _ATTINY84SPI_H_INCLUDED
#define _ATTINY84SPI_H_INCLUDED

#include <avr/io.h>

/**
 * Simple USI-SPI master driver for the ATtiny84.
 *
 * Based on the tutorial at:
 * http://playground.arduino.cc/Code/USI-SPI
 */
class ATtiny84SPI
{
public:
    /**
     * Transfers a single byte of data and returns the response.
     *
     * @param data The byte we want to transfer.
     * @return The response from the SPI slave.
     */
    static uint8_t transfer(uint8_t data);

    /**
     * Sets up PA4, PA5, and PA6 as SCK, DO, and DI.
     */
	static void begin(void);

    /**
     * Disables the USI-SPI hardware by setting the pins as input.
     */
	static void end(void);
};

#endif