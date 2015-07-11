/*
 * adc.h
 *
 *  Created on: Jul 10, 2015
 *      Author: wangweiwei
 */

#ifndef ADC_H_
#define ADC_H_

#include "global_vars.h"
#include "AD1.h"

void adc_measure_start(void);
void On_get_cur_value(unsigned short* data_buffer);
unsigned short adc_to_current(unsigned short adc_buffer);
unsigned short adc_to_voltage(unsigned short adc_buffer);
void On_100ms_adc_sample(void);

#endif /* ADC_H_ */
