#ifndef __CONTROL_H  
#define __CONTROL_H 

#include "sys.h"
#include "stm32f10x_tim.h"
#include "main.h"
//#include "GPIO.h"

void MOTOR_Control1(uint8_t Angle);
void SERVO_Control1(uint8_t Angle);
void SERVO_Control2(uint8_t Angle);
void SERVO_Control3(uint8_t Angle);
void SERVO_Control4(uint8_t Angle);
void SERVO_Control5(uint8_t Angle);
void PLANT_Control(uint8_t Angle);
void TRANSE_Control(uint8_t State);


#endif 
