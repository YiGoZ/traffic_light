/*������һЩ���õ���������*/
#ifndef _LIB_
#define _LIB_
#include <REGX52.H>
/*LEDλ����*/
sbit LEDR1=P1^0;
sbit LEDG1=P1^1;
sbit LEDR2=P1^2;
sbit LEDG2=P1^3;
sbit LEDR3=P1^4;
sbit LEDG3=P1^5;
sbit LEDR4=P1^6;
sbit LEDG4=P1^7;

typedef unsigned int uint;
typedef unsigned char uchar;
extern void delay(uint ms);	//������ʱ
#endif
