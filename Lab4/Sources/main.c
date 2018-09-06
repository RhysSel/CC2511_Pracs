/* ###################################################################
**     Filename    : main.c
**     Project     : Lab4
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-08-18, 13:13, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Red.h"
#include "BitIoLdd1.h"
#include "Green.h"
#include "BitIoLdd2.h"
#include "Blue.h"
#include "BitIoLdd3.h"
#include "AS1.h"
#include "ASerialLdd1.h"
#include "Digital_Input.h"
#include "BitIoLdd4.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
void send_string(char*string){
	int string_length;

	string_length = strlen(string);
	for (int i = 0; i < string_length; i++){
		AS1_SendChar(string[i]);
	}
}
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
char c;
  for(;;) {
	  // While loop to ensure that only a new character will be taken, in order to prevent repeated characters
	  while(ERR_OK!=AS1_RecvChar(&c)){}
	  // Receiving character c from putty
	  AS1_RecvChar(&c);
	  //Toggle red LED and display the character R.
	  if (c == 'r'){
		  Red_NegVal();
		  send_string("Toggle Red\n\r");
	  }
	  //Toggle green LED and display the character G.
	  else if (c == 'g'){
		  Green_NegVal();
		  send_string("Toggle Green\n\r");
	  }
	  else if (c == 'b'){
		  Blue_NegVal();
		  send_string("Toggle Blue\n\r");
	  }
	  else if (c == 'q'){
		  Red_SetVal();
		  Green_SetVal();
		  Blue_SetVal();
		  send_string("Toggle Off\n\r");
	  }
	  else{
		  send_string("Incorrect Input\n\r");
	  }

  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
