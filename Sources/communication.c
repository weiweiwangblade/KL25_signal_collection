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
	data_received_flag = 1;
	if(data_index >= MESSAGE_LENGTH){
		message_recv_success = 0;
		data_index = 0;
	}
	Uart_RecvChar(&data);
	data_buffer[data_index++] = data;
	if(data_index == 7){
		message_recv_success = 1;
	}
}

unsigned char counter;
void On_message_send()
{
	if((counter++)%5==0){									//500ms
		message_send_enable = 1;
	}
}
