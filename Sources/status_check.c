/*
 * status_check.c
 *
 *  Created on: Jul 11, 2015
 *      Author: wangweiwei
 */
#include "status_check.h"

void PH_value_check(void)
{
	  if(current_values[PH_SENSOR] > PH_high){
		  //todo: Output PH high message;
	  }
	  else if(current_values[PH_SENSOR] > PH_low){
		  //todo:normal;
	  }
	  else{
		  //todo:Output PH low message;
	  }
}

void PRE_value_check(void)
{
	  if(current_values[PRE_SENSOR] > PRE_high){
		  //todo: Output PH high message;
	  }
	  else if(current_values[PRE_SENSOR] > PRE_low){
		  if(auto_control)
			  set_output_ctrl(RELAY1_MASK,ON);
	  }
	  else{
		  if(auto_control)
			  set_output_ctrl(RELAY1_MASK,OFF);
	  }
}

void ELEC_value_check(void)
{
	  if(current_values[ELEC_SENSOR] > ELEC_high){
		  //todo: Output PH high message;
	  }
	  else if(current_values[PRE_SENSOR] > ELEC_low){
		  if(auto_control)
			  set_output_ctrl(RELAY1_MASK,ON);
	  }
	  else{
		  if(auto_control)
			  set_output_ctrl(RELAY1_MASK,OFF);
	  }
}

void FLOW_value_check(void)
{
	
}

void options_check(void)
{
	if(message_recv_success)
	{
		switch(recv_message_data[0])
		{
		case 0x00:
			auto_control = 0;
			set_output_ctrl(recv_message_data[1],recv_message_data[2]);
			break;
		case 0x01:
			PH_high = recv_message_data[1]<<8 | recv_message_data[2];
			PH_low = recv_message_data[3]<<8 | recv_message_data[4];
			break;
		case 0x02:
			PRE_high = recv_message_data[1]<<8 | recv_message_data[2];
			PRE_low = recv_message_data[3]<<8 | recv_message_data[4];
			break;
		case 0x03:
			ELEC_high = recv_message_data[1]<<8 | recv_message_data[2];
			ELEC_low = recv_message_data[3]<<8 | recv_message_data[4];
			break;
		case 0x04:
			auto_control = 1;
			break;
		}
	}
}
