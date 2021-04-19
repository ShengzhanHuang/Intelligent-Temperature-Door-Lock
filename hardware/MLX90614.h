
#ifndef _MLX90614_H_
#define _MLX90614_H_

#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define MLX90614_ADDRESS    (0x5a)              //挂在树莓派上的I2C地址，可通过命令i2cdetect -y 1查看
#define MLX90614_REG_BODYDATA    (0x07)         //物体温度寄存器
#define MLX90614_REG_ENVIRONMENTDATA    (0x06)  //环境温度寄存器

#define MLX90614_REVISE_ADDR    (0x04)          //MLAX90614 发射率修改寄存器
#define MLX90614_REVISE_EMISSIVITY  (0xF332)    //发射率值，计算方法    （65535 * ? =需向寄存器写入的值）例如：发射率为0.95，则写入值为65535*0.95=0xF332

#endif /*_MLX90614_H_*/
void MLAX90614_ReadTempture (int);
int sensor();
