#ifndef _MYI2C_H
#define _MYI2C_H
#include "stm32f1xx_hal.h"
void MyI2C_W_SCL(uint8_t BitVal);
void MyI2C_W_SDA(uint8_t BitVal);
uint8_t MyI2C_R_SDA(void);
void MyI2C_Init(void);
void MyI2C_Start(void);
void MyI2C_End(void);
void MyI2C_SendByte(uint8_t Byte);
uint8_t MyI2C_RecieveByte(void);
void MyI2C_SendACK(uint8_t ACKByte);
uint8_t MyI2C_RecieveACK(void);
#endif
