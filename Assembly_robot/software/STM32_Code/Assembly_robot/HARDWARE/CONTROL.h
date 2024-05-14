#ifndef __CONTROL_H  
#define __CONTROL_H 

#include "sys.h"
#include "stm32f10x_tim.h"
#include "main.h"
//#include "GPIO.h"

void MOTOR_Control(uint8_t Angle);
void SERVO_Control1(uint16_t Angle);
void SERVO_Control2(uint16_t Angle);
void SERVO_Control3(uint16_t Angle);
void SERVO_Control4(uint16_t state);
void SERVO_Control5(uint16_t Angle);
void PLANT_Control(uint8_t Angle);
void TRANSE_Control(uint8_t State);


#endif 
