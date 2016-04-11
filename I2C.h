#ifndef _I2C_
#define _I2C_
#include <REGX52.H>
#include"LIB.h"
#define AT24C02_ADDR 0xa0
sbit SDA=P2^0;
sbit SCL=P2^1;
/*24c02*/
extern void delay_5us();							//5΢���ʱ����ʱ
extern void I2C_Init();								//��ʼ��I2C����
extern void I2C_Start();							//��ʼ�ź�
extern void Master_ACK(bit i);						//��������Ӧ��
extern bit Test_ACK();								//���ܴӻ�Ӧ��
extern void I2C_Send_Byte(uchar byte);				//����һ���ֽ�����
extern uchar I2C_Read_Byte();						//����һ���ֽ�����
extern bit I2C_TransmitData(uchar ADDR,DAT);		//��ȷ���ĵ�ַ����һ�ֽ�����
extern uchar I2C_ReceiveData(uchar ADDR);			//��ȷ���ĵ�ַ��ȡһ�ֽ�����
extern void I2C_TransmitStr(uchar ADDR,char *str);	//��ȷ���ĵ�ַ����һ���ַ���	 
extern void I2C_ReceiveStr(uchar ADDR,char *str);	//��ȷ���ĵ�ַ��ȡһ���ַ���
#endif