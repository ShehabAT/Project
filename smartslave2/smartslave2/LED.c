
#include "LED.h"

void LED0_Init(void) // initialize the direction reg to be o/p
{
	DIO_SetPinDir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
}

void LED0_ON(void)
{
	DIO_WritePin(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
}

void LED0_OFF(void)
{
	DIO_WritePin(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
}


void LED0_Toggle(void)
{
	DIO_TogglePin(DIO_PORTC,DIO_PIN2);
}