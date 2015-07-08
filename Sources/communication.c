/*
 * communication.c
 *
 *  Created on: Jul 8, 2015
 *      Author: wangweiwei
 */

#include "communication.h"
#include "global_vars.h"

void send_message(unsigned char length, unsigned char* data_buffer)
{
	unsigned char i;
	for(i=0;i<length;){
		if(message_send_over_flag == 0){
			message_send_over_flag = 1;
			Uart_SendChar(data_buffer[i++]);
		}
	}
}

unsigned char data_index;
void recv_message(unsigned char* data_buffer)
{
	unsigned char data;
	if(data_index >= MESSAGE_LENGTH){
		data_index = 0;
	}
	Uart_RecvChar(&data);
	data_buffer[data_index++] = data;
}
