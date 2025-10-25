#ifndef _BMP280_H
#define _BMP280_H
#include "stm32f1xx_hal.h"
#include "BMP280_RegAdd.h"
// BMP工作模式 
typedef enum {
    BMP280_SLEEP_MODE = 0x0,
    BMP280_FORCED_MODE = 0x1, // 可以说0x2
    BMP280_NORMAL_MODE = 0x3
} BMP280_WORK_MODE;

// BMP压力过采样因子
typedef enum
{
    BMP280_P_MODE_SKIP = 0x0, /*skipped*/
    BMP280_P_MODE_1,          /*x1*/
    BMP280_P_MODE_2,          /*x2*/
    BMP280_P_MODE_3,          /*x4*/
    BMP280_P_MODE_4,          /*x8*/
    BMP280_P_MODE_5           /*x16*/
} BMP280_P_OVERSAMPLING;

// BMP温度过采样因子
typedef enum
{
    BMP280_T_MODE_SKIP = 0x0, /*skipped*/
    BMP280_T_MODE_1,          /*x1*/
    BMP280_T_MODE_2,          /*x2*/
    BMP280_T_MODE_3,          /*x4*/
    BMP280_T_MODE_4,          /*x8*/
    BMP280_T_MODE_5           /*x16*/
} BMP280_T_OVERSAMPLING;

// IIR滤波器时间常数
typedef enum
{
    BMP280_FILTER_OFF = 0x0, /*filter off*/
    BMP280_FILTER_MODE_1,
    /*0.223*ODR*/ /*x2*/
    BMP280_FILTER_MODE_2,
    /*0.092*ODR*/ /*x4*/
    BMP280_FILTER_MODE_3,
    /*0.042*ODR*/                      /*x8*/
    BMP280_FILTER_MODE_4 /*0.021*ODR*/ /*x16*/
} BMP280_FILTER_COEFFICIENT;

// 保持时间
typedef enum
{
    BMP280_T_SB1 = 0x0, /*0.5ms*/
    BMP280_T_SB2,       /*62.5ms*/
    BMP280_T_SB3,       /*125ms*/
    BMP280_T_SB4,       /*250ms*/
    BMP280_T_SB5,       /*500ms*/
    BMP280_T_SB6,       /*1000ms*/
    BMP280_T_SB7,       /*2000ms*/
    BMP280_T_SB8,       /*4000ms*/
} BMP280_T_SB;

typedef struct
{
    /* T1~P9 为补偿系数 */
    uint16_t T1;
    int16_t T2;
    int16_t T3;
    uint16_t P1;
    int16_t P2;
    int16_t P3;
    int16_t P4;
    int16_t P5;
    int16_t P6;
    int16_t P7;
    int16_t P8;
    int16_t P9;
} BMP280;

typedef struct
{
    BMP280_P_OVERSAMPLING P_Osample;
    BMP280_T_OVERSAMPLING T_Osample;
    BMP280_WORK_MODE WORKMODE;
} BMP_OVERSAMPLE_MODE;

typedef struct
{
    BMP280_T_SB T_SB;
    BMP280_FILTER_COEFFICIENT FILTER_COEFFICIENT;
    FunctionalState SPI_EN;
} BMP_CONFIG;

/*******************************下面是用来计算补偿值相关**********************************/
typedef long signed int BMP280_S32_t;   // 有符号 64位！
typedef long unsigned int BMP280_U32_t; // 无符号 32位！
typedef long long signed int BMP280_S64_t;

#define dig_T1 bmp280->T1
#define dig_T2 bmp280->T2
#define dig_T3 bmp280->T3

#define dig_P1 bmp280->P1
#define dig_P2 bmp280->P2
#define dig_P3 bmp280->P3
#define dig_P4 bmp280->P4
#define dig_P5 bmp280->P5
#define dig_P6 bmp280->P6
#define dig_P7 bmp280->P7
#define dig_P8 bmp280->P8
#define dig_P9 bmp280->P9
/************************************************CUT****************************************/

extern BMP280 *bmp280;

void BMP280_Init(void);
uint8_t BMP280_GetStatus(uint8_t status_flag);
// 大气压值-Pa
double BMP280_Get_Pressure(void);
// 温度值-℃
double BMP280_Get_Temperature(void);
uint8_t BMP280_GetID(void);

#endif 
