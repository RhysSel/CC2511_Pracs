/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "MK20D5.h"
#include "MK20D5_simple.h"
#include <stdbool.h>
static int i = 0;

int main(void)
{
	//Enable the clock for the port control module
	SIM_SCGC5 |= 0x3e00;

	//Set LED Pins to GPIO mode
	PORTC_PCR3 = 0x100;
	PORTD_PCR4 = 0x100;
	PORTA_PCR2 = 0x100;

	//Set pins as outputs
	GPIOC_PDDR = 0b1000;
	GPIOD_PDDR = 0b10000;
	GPIOA_PDDR = 0b100;

    /* This for loop should be replaced. By default this loop allows a single stepping. */
    for (;;) {
    	//Red
        	//Turn Red on
    		GPIOC_PDOR = 0B0111;
    		//Turn Green off
    		GPIOD_PDOR = 0B10000;
    		//Turn Blue off
    		GPIOA_PDOR = 0B100;
    	for(int i = 0; i < 1000000; i++)
    	{}
    	//Green
    		//Turn Red off
    		GPIOC_PDOR = 0B1000;
    		//Turn Green on
    		GPIOD_PDOR = 0B01111;
    		//Turn Blue off
    		GPIOA_PDOR = 0B100;
    	for(int i = 0; i < 1000000; i++)
    	{}
    	//Blue
    		//Turn Red off
    		GPIOC_PDOR = 0B1000;
    		//Turn Green off
    		GPIOD_PDOR = 0B10000;
    		//Turn Blue on
    		GPIOA_PDOR = 0B011;
    	for (int i = 0; i < 1000000; i++)
    	{}
    	//Yellow
    		//Turn Red on
    		GPIOC_PDOR = 0B0111;
    		//Turn Green on
    		GPIOD_PDOR = 0B01111;
    		//Turn Blue off
    		GPIOA_PDOR = 0B100;
    	for (int i = 0; i < 1000000; i++)
    	{}
    	//Purple
    		//Turn Red on
    	   	GPIOC_PDOR = 0B0111;
    	   	//Turn Green off
    	   	GPIOD_PDOR = 0B10000;
    	   	//Turn Blue on
    	   	GPIOA_PDOR = 0B011;
    	for (int i = 0; i < 1000000; i++)
    	{}
    	//Cyan
    		//Turn Red Off
    		GPIOC_PDOR = 0B1000;
    		//Turn Green on
    		GPIOD_PDOR = 0B01111;
    		//Turn Blue on
    		GPIOA_PDOR = 0B011;
    	for (int i = 0; i < 1000000; i++)
    	{}
    	//White
    		//Turn Red on
    		GPIOC_PDOR = 0B0111;
    		//Turn Green on
    		GPIOD_PDOR = 0B01111;
    		//Turn Blue on
    		GPIOA_PDOR = 0B011;
    	for (int i = 0; i < 1000000; i++)
    	{}
    }
    /* Never leave main */
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
