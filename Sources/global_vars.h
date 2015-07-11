/*
 * global_vars.h
 *
 *  Created on: Jul 8, 2015
 *      Author: wangweiwei
 */

#ifndef GLOBAL_VARS_H_
#define GLOBAL_VARS_H_

#define MESSAGE_LENGTH	8
#define ADC_CHANNELS	12
#define PRE_SENSOR		0
#define PH_SENSOR		1
#define ELEC_SENSOR		2
#define RELAY1_MASK		0x01
#define RELAY2_MASK		0x02
#define RELAY3_MASK		0x04
#define RELAY4_MASK		0x08
#define RELAY5_MASK		0x10
#define RELAY6_MASK		0x20
#define RELAY7_MASK		0x40
#define RELAY8_MASK		0x80
#define ON				0x01
#define OFF				0x00

unsigned short PH_high;
unsigned short PH_low;
unsigned short PRE_high;
unsigned short PRE_low;
unsigned short ELEC_high;
unsigned short ELEC_low;
unsigned char auto_control;

unsigned short pump_protect_value;

unsigned char message_send_over_flag;
unsigned char recv_message_data[MESSAGE_LENGTH];
unsigned char data_received_flag;
unsigned char message_send_enable;
unsigned char message_recv_success;

unsigned char adc_measure_end_flag;
unsigned short adc_values[ADC_CHANNELS];
unsigned char adc_values_to_send[ADC_CHANNELS*2];

unsigned short voltage_values[ADC_CHANNELS];
unsigned short current_values[ADC_CHANNELS];


#endif /* GLOBAL_VARS_H_ */
