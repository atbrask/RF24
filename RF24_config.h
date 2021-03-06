/*
ATtiny84 / avr-libc compatibility macros for the RF24 library by maniacbug
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


#ifndef __RF24_CONFIG_H__
#define __RF24_CONFIG_H__

#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "ATtiny84SPI.h"

#define min(a,b) ((a) < (b) ? (a) : (b))

#define delayMicroseconds(x) _delay_us(x)
#define delay(x) _delay_ms(x)

#define LOW 0
#define HIGH 1
#define digitalWrite(pin,value) { if (value) PORTA |= _BV(pin); else PORTA &= ~_BV(pin); }

#define INPUT 0
#define OUTPUT 1
#define pinMode(pin, direction) { if (direction) DDRA |= _BV(pin); else DDRA &= ~_BV(pin); }

extern ATtiny84SPI SPI;

#endif
