/* ###################################################################
**     Filename    : Events.c
**     Project     : Lab6
**     Processor   : MK20DX128VLH5
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-09-15, 11:42, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
#include <stdbool.h>

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MK20DX128EX5]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}


/*
** ===================================================================
**     Event       :  Inhr1_OnRxChar (module Events)
**
**     Component   :  Inhr1 [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
volatile char buffer [100];
volatile unsigned int index = 0;
volatile bool enterFlag = false;

void Inhr1_OnRxChar(void)
{
//int z;
char c;
// get char from serial
// = is setting; == comparing

// if char is a special character ('\r' || '\n'):
	// place null character ('\0')
	// set index back to zero
	// signal that the buffer is full (enterFlag = true)

// else if char is a normal character
	//put the character in the current buffer position 	buffer[index] = c;
	// increase the index by one   						index++;

	Term1_ReadChar(&c);
	if (c == '\r'){
		c= '\0';
		buffer[index] = c;
		Term1_MoveTo(1,18);
		Term1_EraseLine();
		Term1_SendStr(buffer);
		index = 0;
		Term1_MoveTo(1,17);
		Term1_EraseLine();
		Term1_SendStr(">  ");
		enterFlag = true;

	}
	else {
		buffer[index] = c;
		index++;
		Term1_SendChar(c);
	}

//	Term1_SendChar(c);

//	if (c=='\r'){
//		Term1_EraseLine();
//		Term1_MoveTo(1,17);
//		Term1_SendStr(">  ");
//	}

/* Take the input values and put into box aswell as adjust the LEDs brightness accordingly
 * If an invalid input is used, give an error message below "Invalid input(1)"
 * counting up when consecutive errors are made
 * when a valid input is made, use erase line, to clear the error message.
 */


//	\r
//	str = "red 7856786786"
//	red entered, 458458945
//	int val;
//	if sscanf(str, "red %i", val) == 1

}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
