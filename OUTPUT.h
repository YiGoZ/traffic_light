/*����ܶ�̬��ʾ*/
#ifndef _OUTPUT_
#define _OUTPUT_
#include <REGX52.H>
#include"LIB.h"
sbit wei = P2^7;				  		//������λѡ����
sbit duan= P2^6;						//��������ѡ����
extern uchar wx[8];		 				//λѡ����
extern uchar dx[26];					//��ѡ����
extern void output(uint pos,uint num);	//��̬��ʾ������������ʾλ�ü�����
#endif