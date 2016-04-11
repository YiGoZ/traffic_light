#ifndef _LED_
#define _LED_
#include"LIB.h"


#define SN 0;
#define EW 1;

sbit CSN=P2^4;
sbit CEW=P2^5;

extern void LED_cmd(bit DIRECTION,uchar LED,bit SWITCH);

#endif