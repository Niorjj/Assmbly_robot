#ifndef __CONTROL_H__
#define __CONTROL_H__

#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif
void MOTOR1_Angle(uint16_t Angle);
void MOTOR2_Angle(uint16_t Angle);
void MOTOR3_Angle(uint16_t Angle);
void MOTOR4_Angle(uint16_t Angle);
void TRANSE_Control(uint8_t State);
void PLANT_Angle(uint16_t Angle);
void Servo1_Angle(uint16_t angle);
void Servo2_Angle(uint16_t angle);
#endif
