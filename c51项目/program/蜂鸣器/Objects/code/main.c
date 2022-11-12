#include <REGX52.H>
#include <intrins.h>
#include "c51tangsang.h"



void main()
{
	int i;
	while(1)
	{
		for(i=0;i<17;i++)
		{
			show_digital((i%10)+1,i);
			delay(100);
		}
	}
}

