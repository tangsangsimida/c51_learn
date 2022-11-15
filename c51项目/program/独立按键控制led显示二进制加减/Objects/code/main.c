#include <intrins.h>
#include "c51tangsang.h"

uint butt=0;

void main()
{	
	P2=0xFF;
	while(1)
	{
		butt=buttom_getstate_4();
		switch(butt)
		{
			case 1:
				P2=P2-1;break;
			case 2:
				P2=P2+1;break;
			case 3:
				P2=0x0;break;
			case 4:
				P2=0xFF;break;
		}
	}
}

