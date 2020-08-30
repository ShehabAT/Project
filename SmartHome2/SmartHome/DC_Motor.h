/*
 * DC_Motor.h
 *
 * Created: 23/07/2020 11:39:24 ص
 *  Author: Ali
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "DIO.h"



typedef enum
{
	CLOCK_WISE_DIR,
	UNTI_CLOCK_WISE_DIR
	
}DC_MOTOR_DIR;

void DcMotor_Init(void);

void DcMotor_SetDir(DC_MOTOR_DIR dir);

void DcMotor_SetSpeed(uint8 speed);

void DcMotor_Start(void);

void DcMotor_Stop(void);





#endif /* DC_MOTOR_H_ */