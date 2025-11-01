#include "LED.h"
#include "Delay.h"
void LED_Init(void)
{			
    
    LED_PowerWarningOff();  
    												
}

void LED_PowerWarningOn(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);						
}

void LED_PowerWarningOff(void)
{	
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);				
}

void LED_On(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);						
}

void LED_Off(void)
{	
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);					
}

void LED_Blink(void)
{
    LED_Off();
    Delay_ms(100);
    LED_On();
    // Delay_ms(100);
    // LED_PowerWarningOn();
    // Delay_ms(100);
    // LED_PowerWarningOff();
    
}