#include <REGX52.H>
#include"UART.h"
void UART_Init()
{
	TMOD|=0X20;		 //T1����ģʽ2��8Ϊ�Զ���װ
	TH1=0XFD;
	TL1=0XFD;  		 //	BPS9600
	TR1=1;
	SM0=0;		   	//���ڹ�����ʽ1 10λ�첽
	SM1=1;
	REN=1;			//���������������
	EA=1;

}
/*
void UART() interrupt 4			   //�����жϲ���ʾ��
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