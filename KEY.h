#ifndef _KEY_
#define _KEY_ 
#include <REGX52.H>
sbit s2=P3^0;
sbit s3=P3^1;
sbit s4=P3^2;
sbit s5=P3^3;
extern unsigned char keyscan();									//按键扫描，返回按键的相应编码，独立+矩阵
extern unsigned char KeyValueSwitch(unsigned char value);		//将按键码转化为相应的数值，传入按键编码，返回对应数值
extern unsigned char key[20];									//按键编码声明
#define UP_VALUE key[16]										//定义向上键编码
#define DOWN_VALUE key[17]										//定义向下键编码
#define LEFT_VALUE key[18]										//定义向左键编码
#define RIGHT_VALUE kay[19]										//定义向右键编码
#define UP 16													//定义向上键数值
#define DOWN 17													//定义向下键数值
#define LEFT 18													//定义向左键数值
#define RIGHT 19												//定义向右键数值
#endif