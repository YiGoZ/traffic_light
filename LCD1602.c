#include <REGX52.H>
#include"LCD1602.h"

char FL=0x80,SL=0xc0;
/*���æ�ź�*/
void busy()
{
	P0=0xff;
	do
	{
		RS=0;
		RW=1;
		EN=0;
		EN=1;
	}while(BUSY==1);
	EN=0;

}
/*дһ���ֽ�����*/
void WriteData(char Data) 
{
	busy();
	EN=0;
	P0 = Data;
	RS=1;
	RW=0;
	EN=1;
	EN=0;
}
/*��������*/
void WriteCmd(char cmd)
{
	busy();
   	EN=0;
	P0=cmd;
	RS=0;
	RW=0;
	EN=1;
	EN=0;

}
/*��ʼ��*/
void LCD_Init()
{
	WriteCmd(0x38);		//16*2��ʾ��5*7����8λ���ݽӿ�
	WriteCmd(0x0c);		//��ʾ��������꿪�����������˸
	WriteCmd(0x06);	   	//���ֲ���������Զ�����
	WriteCmd(0x01);	   	//����

}
/*д�ַ���*/
void WriteStr(char line,char pos,char *str)
{	char i=0;
	WriteCmd(line+pos-1);
	while(str[i]!='\0')
	{
	//	WriteCmd(line+pos-1+i);
		WriteData(str[i]);
		i++;
	}
}
