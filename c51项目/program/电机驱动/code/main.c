#include <intrins.h>
#include "c51tangsang.h"
#include "LCD1602_b.h"

char counter=0,counpare=0,button=0;

void time_0_ms() interrupt 1
{
    TH0=64535/256;
    TL0=64535%256;
    counter++;
	counter%=100;
    if(counter<counpare)
    {
        P1_0=1;
    }
    else
    {
        P1_0=0;
    }

}

int main()
{
    LCD_Init();
    time_0_ms_init();
	while(1)
	{
        LCD_ShowNum(1,2,button,1);
        if(buttom_getstate_4())
        button++;
        button%=4;
        if(button==1){counpare=35;}
        if(button==2){counpare=70;}
        if(button==3){counpare=100;}
        if(button==0){counpare=0;}
	}
}
