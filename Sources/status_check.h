/*
 * status_check.h
 *
 *  Created on: Jul 11, 2015
 *      Author: wangweiwei
 */

#ifndef STATUS_CHECK_H_
#define STATUS_CHECK_H_

#include "global_vars.h"
#include "gpio.h"
#include "adc.h"
#include "communication.h"

void PH_value_check(void);
void PRE_value_check(void);
void ELEC_value_check(void);
void FLOW_value_check(void);
void options_check(void);

#endif /* STATUS_CHECK_H_ */
