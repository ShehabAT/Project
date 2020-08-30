/*
 * BT.c
 *
 * Created: 8/30/2020 7:29:01 PM
 *  Author: SAT
 */ 

#include "UART.h"
void BT_Init()
{
	UART_Init();
}

void BT_SendChar(uint8 data)
{
	UART_SendChar(data);
}

void BT_SendString(uint8* str)
{
	UART_SendString(str);
}

uint8 BT_ReceiveChar(void)
{
	return  UART_ReceiveChar();
}