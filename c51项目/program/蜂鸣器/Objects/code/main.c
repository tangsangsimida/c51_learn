#include <REGX52.H>
#include <intrins.h>
#include "c51tangsang.h"
#include "lcd1602.h"


void beep(uint i);


void main()
{
	//i->一次响的长度，，，j-> 每次响声间隔时间
//	static uint i=200,j=200;
	static uint i=200;
	while(1)
	{
//		beep(i);
//		if(j)
//		{
//			delay(j-=1);
//		}
//		else
//		{
//			delay(0);
//		}
		beep(i);
		i=0;
		
		
		
	}
}














//void main()
//{
//	int i;
//	while(1)
//	{
//		for(i=0;i<16;i++)
//		{
//			show_digital((i%8)+1,i);
//			delay(100);
//		}
//	}
//}