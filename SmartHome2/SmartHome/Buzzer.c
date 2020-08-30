



#include "Buzzer.h"


void Buzzer_init(void)
{
	DIO_SetPinDir(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
}

void Buzzer_on(void)
{
	DIO_WritePin(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
}

void Buzzer_off(void)
{
	DIO_WritePin(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
}
