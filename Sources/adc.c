/*
 * adc.c
 *
 *  Created on: Jul 10, 2015
 *      Author: wangweiwei
 */

#include "adc.h"

void adc_measure_start(void)
{
	adc_measure_end_flag = 0;
	AD1_Measure(TRUE);
}

void On_get_cur_value(unsigned short* data_buffer)
{
	AD1_GetValue16(data_buffer);
	adc_measure_end_flag = 1;
}

unsigned short adc_to_current(unsigned short adc_data)
{
	return ((((float)adc_data*3.3)/65535)/18)*10000;	//(0.004~0.020A)*100000
}

unsigned short adc_to_voltage(unsigned short adc_data)
{
	return ((((float)adc_data*3.3)/65535)*7.5)*1000;	//U*1000
}

void On_100ms_adc_sample(void)
{
	int i=0;
	for(i=0;i<12;i++)
	{
		current_values[i] = adc_to_current(adc_values[i]);
	}
}
