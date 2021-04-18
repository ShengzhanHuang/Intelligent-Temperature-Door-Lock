
#ifndef _MLX90614_H_
#define _MLX90614_H_

#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define MLX90614_ADDRESS    (0x5a)              //������ݮ���ϵ�I2C��ַ����ͨ������i2cdetect -y 1�鿴
#define MLX90614_REG_BODYDATA    (0x07)         //�����¶ȼĴ���
#define MLX90614_REG_ENVIRONMENTDATA    (0x06)  //�����¶ȼĴ���

#define MLX90614_REVISE_ADDR    (0x04)          //MLAX90614 �������޸ļĴ���
#define MLX90614_REVISE_EMISSIVITY  (0xF332)    //������ֵ�����㷽��    ��65535 * ? =����Ĵ���д���ֵ�����磺������Ϊ0.95����д��ֵΪ65535*0.95=0xF332

#endif /*_MLX90614_H_*/
void MLAX90614_ReadTempture(int); #pragma once
