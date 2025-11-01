/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define POWER_ADC_Pin GPIO_PIN_1
#define POWER_ADC_GPIO_Port GPIOA
#define SERVO_ADC_Pin GPIO_PIN_4
#define SERVO_ADC_GPIO_Port GPIOA
#define LED_POWER_Pin GPIO_PIN_6
#define LED_POWER_GPIO_Port GPIOA
#define LED_USER_Pin GPIO_PIN_7
#define LED_USER_GPIO_Port GPIOA
#define AXIS_SCL_Pin GPIO_PIN_10
#define AXIS_SCL_GPIO_Port GPIOB
#define AXIS_SDA_Pin GPIO_PIN_11
#define AXIS_SDA_GPIO_Port GPIOB
#define MOTOR_FL_Pin GPIO_PIN_8
#define MOTOR_FL_GPIO_Port GPIOA
#define MOTOR_RL_Pin GPIO_PIN_9
#define MOTOR_RL_GPIO_Port GPIOA
#define MOTOR_FR_Pin GPIO_PIN_10
#define MOTOR_FR_GPIO_Port GPIOA
#define MOTOR_RR_Pin GPIO_PIN_11
#define MOTOR_RR_GPIO_Port GPIOA
#define OLED_SCL_Pin GPIO_PIN_8
#define OLED_SCL_GPIO_Port GPIOB
#define OLED_SDA_Pin GPIO_PIN_9
#define OLED_SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
