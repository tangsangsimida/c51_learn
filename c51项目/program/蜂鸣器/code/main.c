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
		//�̴̳˴���һ������i��ֵ���治������ʲô��
		P2_5=0;
	}
}