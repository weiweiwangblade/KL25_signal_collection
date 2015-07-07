/*
 * gpio.c
 *
 *  Created on: Jul 7, 2015
 *      Author: wangweiwei
 */

#include "gpio.h"

LDD_TDeviceData* p_input_status = NULL;
LDD_TDeviceData* p_output_control = NULL;
LDD_TDeviceData* p_input_status_1 = NULL;

void gpio_init()
{
	p_input_status = Input_status_Init(NULL);
	p_output_control = Output_ctrl_Init(NULL);
	p_input_status_1 = Input_status_1_Init(NULL);
}

void set_output_ctrl(OutputChMask channels, OutputStatusMask value)
{
	if(channels & 0x01){
		Output_ctrl_SetFieldValue(p_output_control,output_ctrl0,value&0x01);
	}
	if((channels>>1) & 0x01){
		Output_ctrl_SetFieldValue(p_output_control,output_ctrl1,(value>>1)&0x01);
	}
	if((channels>>2) & 0x01)
	{
		Output_ctrl_SetFieldValue(p_output_control,output_ctrl2,(value>>2)&0x01);
	}
	if((channels>>3) & 0x01)
	{
		Output_ctrl_SetFieldValue(p_output_control,output_ctrl3,(value>>3)&0x01);
	}
	if((channels>>4) & 0x01)
	{
		Output_ctrl_SetFieldValue(p_output_control,output_ctrl4,(value>>4)&0x01);
	}
	if((channels>>5) & 0x01)
	{
		Output_ctrl_SetFieldValue(p_output_control,output_ctrl5,(value>>5)&0x01);
	}
	if((channels>>6) & 0x01)
	{
		Output_ctrl_SetFieldValue(p_output_control,output_ctrl6,(value>>6)&0x01);
	}
	if((channels>>7) & 0x01)
	{
		Output_ctrl_SetFieldValue(p_output_control,output_ctrl7,(value>>7)&0x01);
	}
}

void get_output_status(OutputChMask channels, OutputStatusMask* status)
{
	if(channels & 0x01)
	{
		
	}
}

void get_input_status(InputChMask channels, InputStatusMask* value)
{
	
}
