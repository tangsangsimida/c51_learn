#include <intrins.h>
#include "c51tangsang.h"

int ms=0,compare;

//led呼吸灯
int main()
{
    time_0_ms_init();
    compare=90;
	while(1)
	{
//		for(i=0;i<100;i++)
//		{
//            for(count=0;count<15;count++)
//            {
//                P2_0=0;
//                delayus(i);
//                P2_0=0xFF;
//                delayus(100-i);
//            }
//		}
//		for(i=100;i>0;i--)
//		{
//            for(count=0;count<15;count++) 
//            {
//                P2_0=0;
//                delayus(i);
//                P2_0=0xFF;
//                delayus(100-i);
//            }
//		}



	}
}

void addnum() interrupt 1
{
    unsigned int bright_time,out_time;
    TH0=64535/256;		//设置定时初值
    TL0=64535%256;		//设置定时初值
	ms++;
	ms%=100;


}