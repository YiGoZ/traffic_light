#ifndef _I2C_
#define _I2C_
#include <REGX52.H>
#include"LIB.h"
#define AT24C02_ADDR 0xa0
sbit SDA=P2^0;
sbit SCL=P2^1;
/*24c02*/
extern void delay_5us();							//5微秒的时序延时
extern void I2C_Init();								//初始化I2C总线
extern void I2C_Start();							//起始信号
extern void Master_ACK(bit i);						//主机发送应答
extern bit Test_ACK();								//接受从机应答
extern void I2C_Send_Byte(uchar byte);				//发送一个字节数据
extern uchar I2C_Read_Byte();						//接受一个字节数据
extern bit I2C_TransmitData(uchar ADDR,DAT);		//向确定的地址发送一字节数据
extern uchar I2C_ReceiveData(uchar ADDR);			//从确定的地址读取一字节数据
extern void I2C_TransmitStr(uchar ADDR,char *str);	//向确定的地址发送一个字符串	 
extern void I2C_ReceiveStr(uchar ADDR,char *str);	//从确定的地址读取一个字符串
#endif