#include <REGX52.H>
#include<intrins.h>
#include"LED.h"


void LED_cmd(bit DIRECTION,uchar LED,bit SWITCH)
{
	uchar temp;
	CSN=0;
	CEW=0;
	if(DIRECTION==0)
	{
		CSN=1;
	}
	else if(DIRECTION == 1)
	{
		CEW=1;
	}
	if(SWITCH == 0)
	{
		temp=0xff-1;
		temp=_crol_(temp,LED);
		P1=P1&&temp;		
	}
	else if(SWITCH == 1)
	{
		temp=1;
		temp=_crol_(temp,LED);
		P1=P1||temp;
	}
	CSN=0;
	CEW=0;


}