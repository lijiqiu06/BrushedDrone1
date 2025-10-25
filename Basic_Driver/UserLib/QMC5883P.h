#ifndef _QMC5883P_H
#define _QMC5883P_H
#include "stm32f1xx_hal.h"
void QMC5883P_Init(void);
void QMC5883P_GetData(void);
int16_t QMC5883P_ReturnMX(void);
int16_t QMC5883P_ReturnMY(void);
int16_t QMC5883P_ReturnMZ(void);
uint8_t QMC5883P_GetID(void);
#endif 
