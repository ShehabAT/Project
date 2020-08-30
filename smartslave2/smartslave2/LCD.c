


#include "LCD.h"
#define F_CPU 8000000
#include <util/delay.h>
#define  LCD_MODE               4


uint8 GetLength(sint32 val)
{
	uint8 i=1;
	
	while(val/=10)
	{
		i++;
	}
	return i;
}
sint32 GetDiv(uint8 len)
{
	len--;
	sint32 i=1;
	while (len)
	{
		i*=10;
		len--;
	}
	return i;
}
void LCD_Init(void)
{
	#if LCD_MODE == 8
	
	DIO_SetPinDir(LCD_8BIT_CMD_PORT ,LCD_RS_PIN , DIO_PIN_OUTPUT);
    DIO_SetPinDir(LCD_8BIT_CMD_PORT ,LCD_RW_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_CMD_PORT ,LCD_E_PIN , DIO_PIN_OUTPUT);
	
	DIO_SetPortDir(LCD_8BIT_DATA_PORT , DIO_PORT_OUTPUT);
	
	_delay_ms(100);
	
	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0E);
	LCD_WriteCommand(0x01);
	
	_delay_ms(20);
	
	LCD_WriteCommand(0x06);
	
	_delay_ms(5);
	
	#elif LCD_MODE == 4
	
		DIO_SetPinDir(LCD_4BIT_CMD_PORT ,LCD_RS_PIN , DIO_PIN_OUTPUT);
		DIO_SetPinDir(LCD_4BIT_CMD_PORT ,LCD_RW_PIN , DIO_PIN_OUTPUT);
		DIO_SetPinDir(LCD_4BIT_CMD_PORT ,LCD_E_PIN , DIO_PIN_OUTPUT);
		
		DIO_SetPinDir(LCD_4BIT_DATA_PORT ,LCD_D4 , DIO_PIN_OUTPUT);
		DIO_SetPinDir(LCD_4BIT_DATA_PORT ,LCD_D5 , DIO_PIN_OUTPUT);
		DIO_SetPinDir(LCD_4BIT_DATA_PORT ,LCD_D6 , DIO_PIN_OUTPUT);
		DIO_SetPinDir(LCD_4BIT_DATA_PORT ,LCD_D7 , DIO_PIN_OUTPUT);
		
		_delay_ms(100);
		
		LCD_WriteCommand(0x33);
		LCD_WriteCommand(0x32);
		LCD_WriteCommand(0x28);
		LCD_WriteCommand(0x0C);
        LCD_WriteCommand(0x01);
		//LCD_WriteCommand(0x06);
		//LCD_WriteCommand(0x02);
		

		
	
#endif
	
}

void LCD_WriteCommand(uint8 cmd)
{
	DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_RS_PIN, DIO_PIN_LOW);
	DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_RW_PIN, DIO_PIN_LOW);
	DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_LOW);
	
	PORTA = (cmd & 0xF0);
	
	DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_LOW);
	
	PORTA = (cmd << 4);
	
	DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_LOW);
	
	_delay_ms(5);
	
}


void LCD_WriteChar(uint8 data)
{
	DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_RS_PIN, DIO_PIN_HIGH);
	DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_RW_PIN, DIO_PIN_LOW);
	DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_LOW);
	
	PORTA = (data & 0xF0) ;
	
	DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_LOW);
	
	PORTA = (data << 4) ;
	
	DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_WritePin(LCD_4BIT_CMD_PORT ,LCD_E_PIN, DIO_PIN_LOW);
	
	_delay_ms(5);
}

void LCD_WriteString(uint8* str)
{
	uint8 i = 0;
	
	while(str[i] != '\0')
	{
		LCD_WriteChar(str[i]);
		i++;
	}
}

void LCD_WriteInteger(sint32 val)
{

	

	if(val < 0)
	{
		LCD_WriteChar('-');
		val *= -1;
	}
	
	uint8  len=GetLength(val); //length of the integer
	
	sint32 div=GetDiv(len);    //divider 
	/*uint8 len=3;
	sint32 div=100;*/
	
	while (len)
	{
		LCD_WriteChar(((val/div)+48));
		val %=div;
		div/=10;
		len--;
	}
}

void LCD_GoTo(uint8 row, uint8 col)
{
	uint8 pos[2] = {0x80 , 0xC0};
		
	LCD_WriteCommand(pos[row]+col);
		
}



void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}
