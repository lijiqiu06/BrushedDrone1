#include "QMC5883P.h"
#include <math.h>
#include "MyI2C.h"
#include "QMC5883P_RegAdd.h"

#define QMC5883P_Address 0x58
float MX, MY, MZ;

void QMC5883P_WriteReg(uint8_t RegAddress, uint8_t data)
{
    MyI2C_Start();
    MyI2C_SendByte(QMC5883P_Address);
    MyI2C_RecieveACK();
    MyI2C_SendByte(RegAddress);
    MyI2C_RecieveACK();
    MyI2C_SendByte(data);
    MyI2C_RecieveACK();
    MyI2C_End();
}

uint8_t QMC5883P_ReadReg(uint8_t RegAddress)
{
    uint8_t data;
    MyI2C_Start();
    MyI2C_SendByte(QMC5883P_Address);
    MyI2C_RecieveACK();
    MyI2C_SendByte(RegAddress);
    MyI2C_RecieveACK();
    MyI2C_Start();
    MyI2C_SendByte(QMC5883P_Address | 0x01);
    MyI2C_RecieveACK();
    data = MyI2C_RecieveByte();
    MyI2C_SendACK(1); // 不在接收
    MyI2C_End();
    return data;
}

void QMC5883P_Init(void)
{
    MyI2C_Init();
    //QMC5883P_WriteReg(0x29,0x06);
    QMC5883P_WriteReg(QMC5883_CFG_REG_A, 0xFF); 
    QMC5883P_WriteReg(QMC5883_CFG_REG_B, 0x01); 
}

void QMC5883P_GetData(void)
{
    uint16_t DataH, DataL;
    DataH = QMC5883P_ReadReg(QMC5883_MAG_XOUT_H);
    DataL = QMC5883P_ReadReg(QMC5883_MAG_XOUT_L);
    int16_t raw_MX = DataH << 8 | DataL;

    DataH = QMC5883P_ReadReg(QMC5883_MAG_YOUT_H);
    DataL = QMC5883P_ReadReg(QMC5883_MAG_YOUT_L);
    int16_t raw_MY = DataH << 8 | DataL;

    DataH = QMC5883P_ReadReg(QMC5883_MAG_ZOUT_H);
    DataL = QMC5883P_ReadReg(QMC5883_MAG_ZOUT_L);
    int16_t raw_MZ = DataH << 8 | DataL;

    MX = raw_MX;
    MY = raw_MY;
    MZ = raw_MZ;
}

int16_t QMC5883P_ReturnMX(void)
{
    return MX;
}

int16_t QMC5883P_ReturnMY(void)
{
    return MY;
}

int16_t QMC5883P_ReturnMZ(void)
{
    return MZ;
}

uint8_t QMC5883P_GetID(void)
{
    return QMC5883P_ReadReg(QMC5883_CHIPID);
}
