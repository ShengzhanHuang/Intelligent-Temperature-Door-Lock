
#ifndef _MLX90614_H_
#define _MLX90614_H_

#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define MLX90614_ADDRESS    (0x5a)              //The I2C address on the Raspberry Pi, can be viewed by the command i2cdetect -y 1
#define MLX90614_REG_BODYDATA    (0x07)         //Body temperature register
#define MLX90614_REG_ENVIRONMENTDATA    (0x06)  //Ambient temperature register

#define MLX90614_REVISE_ADDR    (0x04)          //MLAX90614 emissivity modification register
#define MLX90614_REVISE_EMISSIVITY  (0xF332)    //Emissivity value, calculation method (65535 *? = Value to be written to the register) For example: the emissivity is 0.95, then the written value is 65535*0.95=0xF332

#endif /*_MLX90614_H_*/
void MLAX90614_ReadTempture (int);
int sensor();
