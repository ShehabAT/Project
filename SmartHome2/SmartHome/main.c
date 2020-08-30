



//#include "LCD.h"
#include "BT.h"
#define  F_CPU   8000000
#include <util/delay.h>






int main(void)
{
	uint8 R=0;
	uint8 T=0;
	
	BT_Init();
	SPI_Master_Init();
	SPI_Master_InitTrans();
	_delay_ms(1000);
	
	BT_SendString("press 0 : measure temperature\n  ");
	BT_SendString("press 1 : for turning light on/off\n  ");
	BT_SendString("press 2 : open the carpet by dc motor\n ");
	BT_SendString("press 3 : close the carpet by dc motor\n ");
	BT_SendString("press 4 : stop the dc motor\n");
	BT_SendString("press 5 : open the door\n");
	BT_SendString("press 6 : close the door\n");
	uint32 password =0;
	uint8 PassFlag=0;
    while (1) 
    {
		
		T=BT_ReceiveChar();
		R=SPI_TranSiver(T);
		
		
	
	    
		
		
    }
}

