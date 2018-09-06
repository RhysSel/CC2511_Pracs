/* ###################################################################
**     Filename    : main.c
**     Project     : Lab6
**     Processor   : MK20DX128VLH5
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-09-15, 11:42, # CodeGen: 0
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
#include "Term1.h"
#include "Inhr1.h"
#include "ASerialLdd1.h"
#include "Red.h"
#include "PwmLdd1.h"
#include "TU1.h"
#include "Green.h"
#include "PwmLdd2.h"
#include "Blue.h"
#include "PwmLdd3.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdbool.h>

extern volatile char buffer [100];
extern volatile unsigned int index ;
extern volatile bool enterFlag;

//initialise a value for each LED
int pwmR;
int pwmG;
int pwmB;

// Set initial PWM values


/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */

// Setting up interface
// Heading
Term1_Cls();
Term1_MoveTo(1,1);
Term1_SetColor(clMagenta,clBlack);
Term1_SendStr("CC2511 Lab 7");
// PWM STATUS AND HOW TO USE Headings
Term1_MoveTo(1,3);
Term1_SetColor(clBlack,clGreen);
Term1_SendStr("+----[ PWM STATUS ]----+");
Term1_MoveTo(26,3);
Term1_SendStr("+------------[ HOW TO USE ]------------+");
// Border
int y;
y = 4;
while (y < 12){
	Term1_MoveTo(1,y);
	Term1_SendStr(" ");
	Term1_MoveTo(24,y);
	Term1_SendStr(" ");
	Term1_MoveTo(26,y);
	Term1_SendStr(" ");
	Term1_MoveTo(65,y);
	Term1_SendStr(" ");
	y = y + 1;
}
// Bottom Border
Term1_MoveTo(1,12);
Term1_SendStr("                        ");
Term1_MoveTo(26,12);
Term1_SendStr("                                        ");
// Writing in First Box
Term1_MoveTo(4,5);
Term1_SetColor(clWhite,clBlack);
Term1_SendStr("Red:   0");
Term1_MoveTo(4,7);
Term1_SendStr("Green: 0");
Term1_MoveTo(4,9);
Term1_SendStr("Blue:  0");
// Writing in Second Box
Term1_MoveTo(27,5);
Term1_SendStr("Type the following command:");
Term1_MoveTo(27,6);
Term1_SendStr("> red n   Set the red PWM ratio to n");
Term1_MoveTo(27,7);
Term1_SendStr("> green n Set the green PWM ratio to n");
Term1_MoveTo(27,8);
Term1_SendStr("> blue n  Set the blue PWM ratio to n");
Term1_MoveTo(27,9);
Term1_SendStr("> off     Turn all LEDs off");
// Command Prompt
Term1_MoveTo(1,16);
Term1_SendStr("Command Prompt:");
Term1_MoveTo(1,17);
Term1_SendStr(">  ");
//Term1_SendStr("Red: ");
//Term1_SendNum();

// look at writing a function that prints the static screen elements

// update PWM ratio values

// then another that prints the changing values
char strToSend[255];

for(;;){

	if (enterFlag == true){
		if (sscanf(buffer, "red %i", &pwmR)==1){
			if (pwmR > 255){
				pwmR = 255;
			}
			else if (pwmR < 0) {
				pwmR = 0;
			}
			sprintf(strToSend, "%i", pwmR);
			Red_SetRatio8(pwmR);
			Term1_MoveTo (11,5);
			Term1_SendStr("     ");
			Term1_MoveTo (11,5);
			Term1_SendStr(strToSend);
			Term1_MoveTo (3,17);
			enterFlag = false;
		}
		else if (sscanf(buffer, "green %i", &pwmG)==1){
			if (pwmG > 255){
				pwmG = 255;
			}
			else if (pwmG < 0){
				pwmG = 0;
			}
			sprintf(strToSend, "%i", pwmG);
			Green_SetRatio8(pwmG);
			Term1_MoveTo (11,7);
			Term1_SendStr("     ");
			Term1_MoveTo (11,7);
			Term1_SendStr(strToSend);
			Term1_MoveTo (3,17);
			enterFlag = false;
		}
		else if (sscanf(buffer, "blue %i", &pwmB)==1){
					if (pwmB > 255){
						pwmB = 255;
					}
					else if (pwmB < 0){
						pwmB = 0;
					}
					sprintf(strToSend, "%i", pwmB);
					Blue_SetRatio8(pwmB);
					Term1_MoveTo (11,9);
					Term1_SendStr("     ");
					Term1_MoveTo (11,9);
					Term1_SendStr(strToSend);
					Term1_MoveTo (3,17);
					enterFlag = false;
		}
		else if (strcmp(buffer, "off")==0){
			Red_SetRatio8(0);
			Term1_MoveTo (11,5);
			Term1_SendStr("0    ");
			Green_SetRatio8(0);
			Term1_MoveTo (11,7);
			Term1_SendStr("0    ");
			Blue_SetRatio8(0);
			Term1_MoveTo (11,9);
			Term1_SendStr("0    ");
			Term1_MoveTo (3,17);
			enterFlag = false;
		}

		else {
			Term1_MoveTo (1,18);
			Term1_EraseLine();
			Term1_SendStr("Incorrect Input");
			Term1_MoveTo (3,17);
			enterFlag = false;
		}
	}



// if buffer is ready
	// scan buffer for information about each LED
		// i.e. Red 255 will set PWM ratio for red LED to 255
		// if (sscanf(str, "red %i", val) == 1){
		// else if (same thing for each color)
		// else if
	// update PWM ratio values
	// reset buffer ready flag (enterFlag = false;)

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
