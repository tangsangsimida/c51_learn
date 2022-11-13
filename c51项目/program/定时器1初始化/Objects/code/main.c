#include <REGX52.H>
#include <intrins.h>
#include "c51tangsang.h"

void show();

void main()
{
	time_1_init();
	while(1)
	{
		
	}
}

void show() interrupt 3
{
	P2=0xAA;
}