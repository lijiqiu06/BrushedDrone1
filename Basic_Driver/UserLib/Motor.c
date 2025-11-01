#include "Motor.h"
#include "tim.h"
void Motor_Init(void)
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1); // 启动定时器1的通道1
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2); // 启动定时器1的通道2
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3); // 启动定时器1的通道3
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4); // 启动定时器1的通道4

    // 设置初始占空比为0
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 0);
}

void Motor_SetSpeed(uint8_t motor, uint8_t speed)
{
    // Placeholder function to set motor speed
    // In a real implementation, this would interface with PWM hardware
    switch(motor)
    {
        case MOTOR_FL:
            // Set front-left motor speed
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, speed);
            break;
        case MOTOR_RL:
            // Set rear-left motor speed
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, speed);
            break;
        case MOTOR_RR:
            // Set rear-right motor speed
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, speed);
            break;
        case MOTOR_FR:
            // Set front-right motor speed
            
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, speed);
            break;
        default:
            // Invalid motor index
            // 设置占空比为0
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
            __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 0);
            break;
    }
}