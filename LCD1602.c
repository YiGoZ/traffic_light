#include <REGX52.H>
#include"LCD1602.h"

char FL=0x80,SL=0xc0;
/*检测忙信号*/
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
/*写一个字节数据*/
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
/*发送命令*/
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
/*初始化*/
void LCD_Init()
{
	WriteCmd(0x38);		//16*2显示，5*7点阵，8位数据接口
	WriteCmd(0x0c);		//显示器开，光标开，光标允许闪烁
	WriteCmd(0x06);	   	//文字不动，光标自动右移
	WriteCmd(0x01);	   	//清屏

}
/*写字符串*/
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
