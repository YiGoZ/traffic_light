#ifndef _LCD1602_
#define _LCD1602_
#include <REGX52.H>
extern char FL,SL;
sbit RS=P3^5;
sbit RW=P3^6;
sbit EN=P3^4;
sbit BUSY=P0^7;
extern void busy();						   			//���LCDæ�źţ�����æ���������ʱ
extern void WriteData(char Data); 					//��LCD����һ�ֽ�����
extern void WriteCmd(char cmd);						//��LCD��������
extern void LCD_Init();								//��ʼ��LCD
extern void WriteStr(char line,char pos,char *str);	//��LCD�Ķ�Ӧ�ж�Ӧλ��д��һ���ַ���
#endif