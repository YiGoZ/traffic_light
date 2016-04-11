#include <REGX52.H>
#include<intrins.h>
#include"I2C.h"
#include"LIB.h"

void delay_5us()	//5微秒的时序延时
{
	_nop_();
}

void I2C_Init()		//初始化I2C总线
{
	SDA=1;
	_nop_();
	SCL=1;
}

void I2C_Start()	//起始信号
{
	SCL=1;
	_nop_();
	SDA=1;
	delay_5us();
	SDA=0;
	delay_5us();
}

void I2C_Stop()		//终止信号
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
	SCL=0;			//拉低时钟总线 允许SDA数据变化
	_nop_();	   	//使总线稳定
	if(i)			//i=1拉低数据总线应答，否则非应答
	{
		SDA=0;
	}
	else
	{
		SDA=1;
	}
	_nop_();		//使数据稳定	
	SCL=1;			//时钟总线有效，使从机读取应答信号
	delay_5us();
	SCL=0;			//拉低数据总线 占用总线继续通信
	_nop_();
	SDA=1;		   	//拉高数据总线 使从机控制
	_nop_();
}

bit Test_ACK()		//获取从机应答
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
/*发送一字节数据*/
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
/*读取一字节数据*/
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


/*I2C发送数据*/
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

/*I2C接收数据*/
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
/*向确定的地址发送字符串*/
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
/*从确定的地址读取字符串*/
void I2C_ReceiveStr(uchar ADDR,char *str)
{
	uchar i=0;
	while(str[i]=I2C_ReceiveData(ADDR+i))
	{
		i++;
	}
	str[i]='\0';
}