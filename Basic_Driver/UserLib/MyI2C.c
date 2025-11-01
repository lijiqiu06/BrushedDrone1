#include "MyI2C.h"                  // Device header
#include "Delay.h"


void MyI2C_W_SCL(uint8_t BitVal)
{
	
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,(GPIO_PinState)BitVal);
	Delay_us(10);
}

void MyI2C_W_SDA(uint8_t BitVal)
{
	
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,(GPIO_PinState)BitVal);
	Delay_us(10);
}

uint8_t MyI2C_R_SDA(void)
{
	Delay_us(10);
	
	return HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_11);
}




void MyI2C_Init(void)
{

	
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(1);
}

void MyI2C_Start(void)
{
	MyI2C_W_SDA(1);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(0);
}

void MyI2C_End(void)
{
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(1);
}

void MyI2C_SendByte(uint8_t Byte)
{
	for(uint8_t i=0;i<8;i++)
	{
		MyI2C_W_SDA(!!(Byte & (0x80>>i)));
		MyI2C_W_SCL(1);
		MyI2C_W_SCL(0);
	}
}

uint8_t MyI2C_RecieveByte(void)
{
	uint8_t Byte=0x00;
	MyI2C_W_SDA(1);
	for(uint8_t i=0;i<8;i++)
	{
		MyI2C_W_SCL(1);
		if(MyI2C_R_SDA()==1){ Byte|=(0x80>>i);}
		MyI2C_W_SCL(0);
	}
	
	return Byte;
}

void MyI2C_SendACK(uint8_t ACKByte)
{
	MyI2C_W_SDA(ACKByte);
	MyI2C_W_SCL(1);
	MyI2C_W_SCL(0);
}

uint8_t MyI2C_RecieveACK(void)
{
	uint8_t ACKByte=0x00;
	MyI2C_W_SDA(1);

	MyI2C_W_SCL(1);
	ACKByte = (MyI2C_R_SDA() == 0) ? 1 : 0; // 反转：0→1（ACK），1→0（NACK）
	MyI2C_W_SCL(0);
	
	return ACKByte;
}
