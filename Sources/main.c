/* ###################################################################
**     Filename    : main.c
**     Project     : signal_collection
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-07-07, 22:07, # CodeGen: 0
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
#include "Input_status.h"
#include "Output_ctrl.h"
#include "AD1.h"
#include "AdcLdd1.h"
#include "Uart.h"
#include "ASerialLdd1.h"
#include "Rs485_RE.h"
#include "BitIoLdd1.h"
#include "Input_status_1.h"
#include "TI1_100ms.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "gpio.h"
#include "global_vars.h"
#include "communication.h"
#include "adc.h"
#include "status_check.h"

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
  /* For example: for(;;) { } */
  pump_protect_value = 1000;
  gpio_init();
  message_send_over_flag = 0;
  adc_measure_end_flag = 1;
  set_output_ctrl(0xff,0x55);
  data_received_flag = 0;  
  auto_control = 1;
  for(;;)
  {
	  if(adc_measure_end_flag){
		  adc_measure_start();
	  }
	  if(message_send_enable){
		  message_send_enable = 0;
		  send_message(ADC_CHANNELS*2, (unsigned char*)current_values);
	  }
	  PH_value_check();
	  PRE_value_check();
	  ELEC_value_check();
	  options_check();
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
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
