/*
 * BT.h
 *
 * Created: 8/30/2020 7:29:19 PM
 *  Author: SAT
 */ 


#ifndef BT_H_
#define BT_H_

#include "BIT_Math.h"
#include "DIO.h"
#include "ATMEGA32_Regs.h"
#include "SPI.h"



void BT_Init(void);

void BT_SendChar(uint8 data);

void BT_SendString(uint8* str);

uint8 BT_ReceiveChar(void);



#endif /* BT_H_ */