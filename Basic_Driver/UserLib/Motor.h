	#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "stm32f1xx_hal.h"

#define MOTOR_FL 0
#define MOTOR_RL 1
#define MOTOR_RR 2
#define MOTOR_FR 3

void Motor_Init(void);
void Motor_SetSpeed(uint8_t motor, uint8_t speed);

#endif
