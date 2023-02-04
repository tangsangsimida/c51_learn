#include "c51tangsang.h"
#include "LCD1602_b.h"
#include <intrins.h>

char counter=0,counpare=0,button=0;
char before=0,after=0;

void time_0_ms() interrupt 1
{
    TH0=64535/256;
    TL0=64535%256;
    counter++;
	counter%=100;
    if(counter>=100-counpare/2 || counter <=(100+counpare/2)%100)
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
