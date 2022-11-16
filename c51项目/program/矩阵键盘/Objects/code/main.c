#include <REGX52.H>
#include <intrins.h>
#include "c51tangsang.h"
#include "LCD1602_b.h"


int  main()
{
    int buttom_16_state=0;
	LCD_Init();
	LCD_ShowString(1,1,"Input password:");
    LCD_ShowNum(2,1,0,4);
	while(1)
	{
        buttom_16_state=buttom_getstate_16();
        if(buttom_16_state)
        {
            LCD_ShowNum(2,1,buttom_16_state,4);
        }
	}
}
