#include <intrins.h>
#include "c51tangsang.h"


int main()
{
	uart_init();
    uart_sendbyte(date_uart);
    /*
     * 串口接收数据会触发中断，跟程序耦合性很大，函数相当于一个模板
     * */
	while(1)
	{

	}
}

