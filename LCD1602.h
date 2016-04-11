#ifndef _LCD1602_
#define _LCD1602_
#include <REGX52.H>
extern char FL,SL;
sbit RS=P3^5;
sbit RW=P3^6;
sbit EN=P3^4;
sbit BUSY=P0^7;
extern void busy();						   			//检测LCD忙信号，并在忙的情况下延时
extern void WriteData(char Data); 					//向LCD发送一字节数据
extern void WriteCmd(char cmd);						//向LCD发送命令
extern void LCD_Init();								//初始化LCD
extern void WriteStr(char line,char pos,char *str);	//向LCD的对应行对应位置写入一个字符串
#endif