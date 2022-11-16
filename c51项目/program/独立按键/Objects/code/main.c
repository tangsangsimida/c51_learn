#include <intrins.h>
#include "c51tangsang.h"

uint buttom_getstate();

void main()
{
	static uint buttom_state=0;
//	time_0_ms_init();
//	P2=0xFE;
	while(1)
	{
		buttom_state=buttom_getstate();
		switch(buttom_state)
		{
			case 1: P2_0=~P2_0;break;
			case 2: P2_1=~P2_1;break;
			case 3: P2_2=~P2_2;break;
			case 4: P2_3=~P2_3;break;
//			case 0: P2=0xFF;
		}
	}
}


uint buttom_getstate()
{
	if(P3_0==0)
	{
		delay(20);
		while(P3_0==0);
		return 2;
	}
	if(P3_1==0)
	{
		delay(20);
		while(P3_1==0);
		return 1;
	}
	if(P3_2==0)
	{
		delay(20);
		while(P3_2==0);
		return 3;
	}
	if(P3_3==0)
	{
		delay(20);
		while(P3_3==0);
		return 4;
	}
	return 0;
}



//void P2_cror() interrupt 1
//{
//	static unsigned int i=0;
//	TH0=64535/256;//高八位数据     晶振12mhz，一个周期为1us，最大65535us，
//	TL0=64535%256;//低八位数据->64535 = 65535-1000; -> 1000us=1ms; 定时器单位为1ms
//	i++;
//	if(i==100)//一秒
//	{
//		i=0;
//		P2=_crol_(P2,1);
//	}
//}
