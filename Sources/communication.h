/*
 * communication.h
 *
 *  Created on: Jul 8, 2015
 *      Author: wangweiwei
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include "Uart.h"
#include "global_vars.h"

void send_message(unsigned char length, unsigned char* data_buffer);
void recv_message(unsigned char* data_buffer);
void On_message_send();

#endif /* COMMUNICATION_H_ */
