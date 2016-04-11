#include"KEY.h"
#include"LIB.h"
#include <REGX52.H>



/*�������붨��*/
uchar key[20]= {  0xee,0xde,0xbe,0x7e,
				  0xed,0xdd,0xbd,0x7d,
				  0xeb,0xdb,0xbb,0x7b,
				  0xe7,0xd7,0xb7,0x77,
				  0x01,0x02,0x03,0x04};

/*����ɨ�裬���ذ�������*/
uchar keyscan()
{
	uchar l=0,h=0;
	P3=0xff;
	if(s2==0)								  //�������̲���
	{	
		delay(10);
		if(s2==0)
		{
			while(!s2);
			return key[16];
		}
	}
	else if(s3==0)
	{
		delay(10);
		if(s3==0)
		{
			while(!s3);
			return key[17];
		}	
	}
	else if(s4==0)
	{
		delay(10);
		if(s4==0)
		{
			while(!s4)
			return key[18];
		}	
	}
	else if(s5==0)
	{	
		delay(10);
		if(s5==0)
		{
			while(!s5);
			return key[19];
		}	 
	}
	else									 //������̲���
	{
		P3=0xf0;
		if( (P3&0xf0) != 0xf0)
		{
			delay(10);
			if( (P3&0xf0) != 0xf0)
			{
				l = P3 & 0xf0;
				P3 = 0x0f;
				if((P3&0x0f) != 0x0f)
				{
					delay(10);
					if((P3&0x0f) != 0x0f)
					{
						h = P3 & 0x0f;
						while((P3&0x0f) != 0x0f);			
					}
				}
			}
		}
	} 
	P3=0xff;
	return h+l;
	   
}
/*��������ת��Ϊ��Ӧ��ֵ*/
uchar KeyValueSwitch(uchar value)
{
	uchar i;
	for(i=0;i<20;i++)
	{
		if(value==key[i])
		{
		return (i);
		}	
	}
}