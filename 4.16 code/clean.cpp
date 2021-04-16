#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<assert.h>
#include<termios.h>
#include<string.h>
#include<sys/time.h>
#include<time.h>
#include<sys/types.h>
#include<errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <wiringPiI2C.h>
#include <unistd.h>

unsigned char i2cHand;
unsigned char DataBuffer[7][127];


void WriteCmd(int fd,unsigned char I2C_Command)//写命令
{
	wiringPiI2CWriteReg8(fd,0x00, I2C_Command);
}
 
 
void OLED_Init(int fd)
{
 
	WriteCmd(fd,0xAE); //display off
	WriteCmd(fd, 0x20);	//Set Memory Addressing Mode	
	WriteCmd(fd, 0x10);	//00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	WriteCmd(fd, 0xb0);	//Set Page Start Address for Page Addressing Mode,0-7
	WriteCmd(fd, 0xc8);	//Set COM Output Scan Direction
	WriteCmd(fd, 0x00); //---set low column address
	WriteCmd(fd, 0x10); //---set high column address
	WriteCmd(fd, 0x40); //--set start line address
	WriteCmd(fd, 0x81); //--set contrast control register
	WriteCmd(fd, 0xff); //亮度调节 0x00~0xff
	WriteCmd(fd, 0xa1); //--set segment re-map 0 to 127
	WriteCmd(fd, 0xa6); //--set normal display
	WriteCmd(fd, 0xa8); //--set multiplex ratio(1 to 64)
	WriteCmd(fd, 0x3F); //
	WriteCmd(fd, 0xa4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	WriteCmd(fd, 0xd3); //-set display offset
	WriteCmd(fd, 0x00); //-not offset
	WriteCmd(fd, 0xd5); //--set display clock divide ratio/oscillator frequency
	WriteCmd(fd, 0xf0); //--set divide ratio
	WriteCmd(fd, 0xd9); //--set pre-charge period
	WriteCmd(fd, 0x22); //
	WriteCmd(fd, 0xda); //--set com pins hardware configuration
	WriteCmd(fd, 0x12);
	WriteCmd(fd, 0xdb); //--set vcomh
	WriteCmd(fd, 0x20); //0x20,0.77xVcc
	WriteCmd(fd, 0x8d); //--set DC-DC enable
	WriteCmd(fd, 0x14); //
	WriteCmd(fd, 0xaf); //--turn on oled panel
}


void WriteData(int fd,unsigned char I2C_Data)//写数据
{
	wiringPiI2CWriteReg8(fd,0x40, I2C_Data);
}
 

void OLED_SetPos(int fd,unsigned char x, unsigned char y) //设置起始点坐标
{
	WriteCmd(fd, (unsigned char)(0xb0 + x));
	WriteCmd(fd,((y & 0x0f) | 0x00));//LOW
	WriteCmd(fd,(((y & 0xf0) >> 4) | 0x10));//HIGHT
}

/*写 缓存数据*/
void Write_DataBuffer()//这个是将DataBuffer数组里面的值，全部写进屏里去
{

	unsigned char i, j;
 
	for (i = 0; i < 8; i++)
	{
		OLED_SetPos(i2cHand, i, 0); //设置起始点坐标
		for (j = 0; j < 128; j++)
		{
			WriteData(i2cHand, DataBuffer[i][j]);//写数据
		}
	}
}


void OLED_Fill(void)//全屏填充
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 128; j++)
		{
			DataBuffer[i][j] = 0xff;
		}
	}
	Write_DataBuffer();
}
 
 
void OLED_CLS(void)//清屏
{
	unsigned char i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 128; j++)
		{
			DataBuffer[i][j] = 0x00;
		}
	}
	Write_DataBuffer();
}



int main(void)
{
  
 
	delay(1000); // 毫秒
 
	wiringPiSetupSys();
 
	i2cHand=wiringPiI2CSetup(0x3c);	/*加载i2c设备*/
	OLED_Init(i2cHand);
 
	while (true)
	{
 
		OLED_Fill();
		delay(1000);
 
		OLED_CLS();
		delay(1000); // 毫秒
 
 
	}
 
	return 0;
}
