#ifndef _KEY_
#define _KEY_ 
#include <REGX52.H>
sbit s2=P3^0;
sbit s3=P3^1;
sbit s4=P3^2;
sbit s5=P3^3;
extern unsigned char keyscan();									//����ɨ�裬���ذ�������Ӧ���룬����+����
extern unsigned char KeyValueSwitch(unsigned char value);		//��������ת��Ϊ��Ӧ����ֵ�����밴�����룬���ض�Ӧ��ֵ
extern unsigned char key[20];									//������������
#define UP_VALUE key[16]										//�������ϼ�����
#define DOWN_VALUE key[17]										//�������¼�����
#define LEFT_VALUE key[18]										//�������������
#define RIGHT_VALUE kay[19]										//�������Ҽ�����
#define UP 16													//�������ϼ���ֵ
#define DOWN 17													//�������¼���ֵ
#define LEFT 18													//�����������ֵ
#define RIGHT 19												//�������Ҽ���ֵ
#endif