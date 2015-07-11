/*
 * gpio.h
 *
 *  Created on: Jul 7, 2015
 *      Author: wangweiwei
 */

#ifndef GPIO_H_
#define GPIO_H_

typedef unsigned char OutputChMask;
typedef unsigned char OutputStatusMask;
typedef unsigned char InputStatusMask;
typedef unsigned char InputChMask;

#include "Input_status.h"
#include "Output_ctrl.h"
#include "Input_status_1.h"

void gpio_init();
void set_output_ctrl(OutputChMask channels, OutputStatusMask value);
void get_output_status(OutputChMask channels, OutputStatusMask* status);
void get_input_status(InputChMask channels, InputStatusMask* value);

#endif /* GPIO_H_ */
