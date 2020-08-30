/*
 * Servo.c
 *
 * Created: 23/07/2020 01:39:41 م
 *  Author: Ali
 */ 


#include "Servo.h"


void ServoMotor_Init(void)
{
	DIO_SetPinDir(DIO_PORTD ,DIO_PIN5, DIO_PIN_OUTPUT);
	PWM1_Init();
	PWM1_Start();
}

void ServoMotor_Move(uint8 degree)
{
	
	uint32 duty_cycle = 0;
	
	
	duty_cycle = 5 + (degree * .3) ;
	
	PWM1_Generate(duty_cycle);
	
}