#include <REGX52.H>
#include"UART.h"
void UART_Init()
{
	TMOD|=0X20;		 //T1工作模式2，8为自动重装
	TH1=0XFD;
	TL1=0XFD;  		 //	BPS9600
	TR1=1;
	SM0=0;		   	//串口工作方式1 10位异步
	SM1=1;
	REN=1;			//串口允许接受数据
	EA=1;

}
/*
void UART() interrupt 4			   //串口中断操作示例
{
	if(TI)
	{
		TI=0;
		SBUF=num;
	}
	else if(RI)
	{
		num=SBUF;
		num++;
		SBUF=num;
		RI=0;
		while(!TI);
		TI=0;
	}
	
}
*/