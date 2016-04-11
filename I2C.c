#include <REGX52.H>
#include<intrins.h>
#include"I2C.h"
#include"LIB.h"

void delay_5us()	//5΢���ʱ����ʱ
{
	_nop_();
}

void I2C_Init()		//��ʼ��I2C����
{
	SDA=1;
	_nop_();
	SCL=1;
}

void I2C_Start()	//��ʼ�ź�
{
	SCL=1;
	_nop_();
	SDA=1;
	delay_5us();
	SDA=0;
	delay_5us();
}

void I2C_Stop()		//��ֹ�ź�
{
	SDA=0;
	_nop_();
	SCL=1;
	delay_5us();
	SDA=1;
	delay_5us();
}

void Master_ACK(bit i)
{
	SCL=0;			//����ʱ������ ����SDA���ݱ仯
	_nop_();	   	//ʹ�����ȶ�
	if(i)			//i=1������������Ӧ�𣬷����Ӧ��
	{
		SDA=0;
	}
	else
	{
		SDA=1;
	}
	_nop_();		//ʹ�����ȶ�	
	SCL=1;			//ʱ��������Ч��ʹ�ӻ���ȡӦ���ź�
	delay_5us();
	SCL=0;			//������������ ռ�����߼���ͨ��
	_nop_();
	SDA=1;		   	//������������ ʹ�ӻ�����
	_nop_();
}

bit Test_ACK()		//��ȡ�ӻ�Ӧ��
{
	SCL=1;
	delay_5us();
	if(SDA)
	{
		SCL=0;
		_nop_();
		I2C_Stop();
		return 0;
	}
	else
	{
		SCL=0;
		_nop_();
		return 1;
	}

}
/*����һ�ֽ�����*/
void I2C_Send_Byte(uchar byte)			 
{
	uchar i;
	for(i=1;i<=8;i++)
	{
		SCL=0;
		_nop_();
		if(byte&0x80)
		{
			SDA=1;
			_nop_();
		}
		else
		{
			SDA=0;
			_nop_();
		}
		SCL=1;
		_nop_();
		byte<<=1;
	}
	SCL=0;
	_nop_();
	SDA=1;
	_nop_();
}		
/*��ȡһ�ֽ�����*/
uchar I2C_Read_Byte()					 
{
	uchar byte,i;
	SCL=0;
	_nop_();
	SDA=1;
	_nop_();
	for(i=1;i<=8;i++)
	{
		byte<<=1;
		SCL=1;
		_nop_();
		if(SDA)
		{
			byte=byte|0x01;
		}
		else
		{
			byte=byte&0xfe;
		}
		_nop_();
		SCL=0;
		_nop_();
	}
	return byte;
}


/*I2C��������*/
bit I2C_TransmitData(uchar ADDR,DAT)
{
	I2C_Start();
	I2C_Send_Byte(AT24C02_ADDR+0);
	if (!Test_ACK())
	{
		return(0);
	}
	I2C_Send_Byte(ADDR); 
	if (!Test_ACK())
	{
		return(0);
	}
	I2C_Send_Byte(DAT);
	if (!Test_ACK())
	{
		return(0);
	}
	I2C_Stop();
	return(1);	
}

/*I2C��������*/
uchar I2C_ReceiveData(uchar ADDR)
{
	uchar DAT;
	I2C_Start();
	I2C_Send_Byte(AT24C02_ADDR+0);
	if (!Test_ACK())
	{
		return(0);
	}
	I2C_Send_Byte(ADDR);
	Master_ACK(0);
	I2C_Start();
	I2C_Send_Byte(AT24C02_ADDR+1);
	if (!Test_ACK())
	{
		return(0);
	}
	DAT = I2C_Read_Byte();
	Master_ACK(0);
	I2C_Stop();
	return(DAT);	
}
/*��ȷ���ĵ�ַ�����ַ���*/
void I2C_TransmitStr(uchar ADDR,char *str)		 
{
	uchar i=0;
	while(str[i]!='\0')
	{
		I2C_TransmitData(ADDR+i,str[i]);
		delay(5000);
		i++;
	}
	I2C_TransmitData(ADDR+i,str[i]);
	delay(5000);
}
/*��ȷ���ĵ�ַ��ȡ�ַ���*/
void I2C_ReceiveStr(uchar ADDR,char *str)
{
	uchar i=0;
	while(str[i]=I2C_ReceiveData(ADDR+i))
	{
		i++;
	}
	str[i]='\0';
}