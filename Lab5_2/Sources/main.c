/* ###################################################################
**     Filename    : main.c
**     Project     : Lab5_2
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-08-25, 16:12, # CodeGen: 0
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
#include "PwmLdd1.h"
#include "Green.h"
#include "PwmLdd2.h"
#include "Blue.h"
#include "PwmLdd3.h"
#include "AS1.h"
#include "ASerialLdd1.h"
#include "TU1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  int x;
  int y;
  int z;
  char c;
  byte err;

  x = 0;
  y = 0;
  z = 0;

  Red_SetRatio8(x);
  Green_SetRatio8(y);
  Blue_SetRatio8(z);

  for(;;){
	  do {
		  err = AS1_RecvChar(&c);
	  } while(err != ERR_OK);

	 if (c == 'R'){
		 AS1_SendChar(c);
		 if (x >= 255){
			 x = 255;
		 }
		 else {
			 x = x + 5;
			 Red_SetRatio8(x);
		 }
	 }
	 else if (c == 'r'){
		 AS1_SendChar(c);
		 if (x <= 0){
			 x = 0;
		 }
		 else {
			 x = x - 5;
			 Red_SetRatio8(x);
		 }
	 }
	 else if (c == 'G'){
		 AS1_SendChar(c);
		 if (y >= 255)
			 y = 255;
		 else {
			 y = y + 5;
			 Green_SetRatio8(y);
		 }
	 }
	 else if (c == 'g'){
		 AS1_SendChar(c);
		 if (y <= 0){
			 y = 0;
		 }
		 else {
			 y = y - 5;
			 Green_SetRatio8(y);
		 }
	 }
	 else if (c == 'B'){
		 AS1_SendChar(c);
		 if (z >= 255){
			 z = 255;
		 }
		 else{
			 z = z + 5;
			 Blue_SetRatio8(z);
		 }
	 }
	 else if (c == 'b'){
		 AS1_SendChar(c);
		 if (z <= 0){
			 z = 0;
		 }
		 else {
			 z = z - 5;
			 Blue_SetRatio8(z);
		 }
	 }
  }
  /* For example: for(;;) { } */

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
