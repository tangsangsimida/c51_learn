#include <intrins.h>
#include "c51tangsang.h"

//led呼吸灯
int main()
{
    int i=0;
	while(1)
	{
        P2=0;
        delay(i+=100);
        P2=0xFF;
	}
}

