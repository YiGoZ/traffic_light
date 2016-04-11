/*数码管动态显示*/
#ifndef _OUTPUT_
#define _OUTPUT_
#include <REGX52.H>
#include"LIB.h"
sbit wei = P2^7;				  		//锁存器位选定义
sbit duan= P2^6;						//锁存器段选定义
extern uchar wx[8];		 				//位选声明
extern uchar dx[26];					//段选声明
extern void output(uint pos,uint num);	//动态显示函数，输入显示位置及数字
#endif