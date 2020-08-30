/*
 * DC_Motor.c
 *
 * Created: 23/07/2020 11:39:07 ص
 *  Author: Ali
 */ 

#include "DC_Motor.h"
#include "Timer.h"

void DcMotor_Init(void)
{
	
	DIO_SetPinDir(DIO_PORTC ,DIO_PIN3 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTC ,DIO_PIN4 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTD ,DIO_PIN4 , DIO_PIN_OUTPUT);
	
	//DIO_SetPinDir(DIO_PORTB ,DIO_PIN3 , DIO_PIN_OUTPUT);
	
	PWM0_Init();
	
}


void DcMotor_SetDir(DC_MOTOR_DIR dir)
{
	
	switch(dir)
	{
		
		case CLOCK_WISE_DIR :
		
		DIO_WritePin(DIO_PORTC ,DIO_PIN3,DIO_PIN_HIGH);
		DIO_WritePin(DIO_PORTC ,DIO_PIN4,DIO_PIN_LOW);
		
		break;
		
		case UNTI_CLOCK_WISE_DIR :
		
		DIO_WritePin(DIO_PORTC ,DIO_PIN3,DIO_PIN_LOW);
		DIO_WritePin(DIO_PORTC ,DIO_PIN4,DIO_PIN_HIGH);
		
		break;
		
		default:
		
		break;
	}
	
}


void DcMotor_SetSpeed(uint8 speed)
{
	speed *= 10;
	
	PWM0_Generate(speed);
}


void DcMotor_Start(void)
{
	
	PWM0_Start();
}


void DcMotor_Stop(void)
{
	
	DIO_WritePin(DIO_PORTC ,DIO_PIN3,DIO_PIN_LOW);
	DIO_WritePin(DIO_PORTC ,DIO_PIN4,DIO_PIN_LOW);
}