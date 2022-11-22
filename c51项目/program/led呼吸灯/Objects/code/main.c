#include <intrins.h>
#include "c51tangsang.h"


int ms=0;

//led呼吸灯
int main()
{
    time_0_us_init();
//    time_0_case=0;
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
    int i;
    TL0 = 0xFF;		//设置定时初值
    TH0 = 0xFF;		//设置定时初值
	ms++;
    for(i=0;i<5;i++)
    {
        if(ms<95)
        {
            P2_0=0;
        }
        else
        {
            P2_0=1;
        }
    }
    ms%=100;
}