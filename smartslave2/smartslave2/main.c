/*
 * smartslave.c
 *
 * Created: 8/29/2020 2:18:43 AM
 * Author : SAT
 */ 


#include "LCD.h"
#include "Temp_Sensor.h"
#include "LED.h"
#include "DC_Motor.h"
#include "Servo.h"
#define  F_CPU   8000000
#include <util/delay.h>


int main(void)
{
   
	LCD_Init();
	
	LED0_Init();
	
	TempSensor_Init();
	
	  DcMotor_Init();
	 
	 ServoMotor_Init();

	SPI_Slave_Init();
	
	 uint8 RX=0;
	 
	 uint8 TX=20;

	 uint16 Temp = 0;
	 
	 uint8 counter =0;
	 
	 uint8 deg=0;
	 
	
	
    while (1) 
    {
		
	
		
	RX = SPI_TranSiver(TX);
		switch(RX)
		{
			case '0' :
			TempSensor_Read(&Temp);
			
			//_delay_ms(10);
			LCD_Clear();
			
			LCD_WriteInteger(Temp);
			_delay_ms(100);
			break;
			
			
			case '1' :
			LED0_Toggle();
			break;
			
			
			
			case '2':
			
			 DcMotor_SetDir(CLOCK_WISE_DIR);
			 DcMotor_SetSpeed(10);
			DcMotor_Start();
			break;
			
			case '3':
			DcMotor_Stop();
			DcMotor_SetDir(UNTI_CLOCK_WISE_DIR);
			DcMotor_SetSpeed(10);
			DcMotor_Start();
			break;
			
			case '4' :
			DcMotor_Stop();
			break;
			
			case '5':
		     
			 ServoMotor_Move(180);
			 
			break;
			
			case '6':
			
			ServoMotor_Move(0);
			
			break;
			
			
		}
		 
		//_delay_ms(1000);
    }
	
}

