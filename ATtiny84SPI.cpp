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

#include "ATtiny84SPI.h"

uint8_t ATtiny84SPI::transfer(uint8_t data)
{
    USIDR = data;
    USISR = _BV(USIOIF);
    while((USISR & _BV(USIOIF)) == 0) 
        USICR = _BV(USIWM0) | _BV(USICS1) | _BV(USICLK) | _BV(USITC);
    return USIDR;
}

void ATtiny84SPI::begin(void)
{
   // Set SCK and DO pins as output
   DDRA |= _BV(PA4) | _BV(PA5);
   PORTA &= ~(_BV(PA4) | _BV(PA5));

   // Set DI pin as input
   DDRA &= ~_BV(PA6);
   PORTA |= _BV(PA6);
}

void ATtiny84SPI::end(void)
{
   // Set DI, DO and SCK as inputs
   DDRA &= ~(_BV(PA4) | _BV(PA5) | _BV(PA6));
}
