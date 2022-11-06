#include <REGX52.H>
#include "c51tangsang.h"
main()
{
	while(1)
	{
		int i=20;
		while(i--)
		{
			P2_5=1;
			delay(100);
			P2_5=0;
			delay(100);
		}
		//教程此处有一个清零i的值，真不明白有什么用
		P2_5=0;
	}
}