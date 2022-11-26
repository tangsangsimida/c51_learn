#include <intrins.h>
#include "c51tangsang.h"

void uart_init();
void uart_sendbyte(unsigned char);

//串口通信单片机---->电脑
int main()
{
    uart_init();
	while(1)
	{
		
	}
}

//void uart_init()
//{
//    PCON |=0x80;//波特率加倍，这个位在电源寄存器上，所以只能与运算改变值
//    SCON = 0x40;//八位数据可变波特率---串行控制寄存器
////    AUXR &=0xBF;//定时器1时钟为12T
////    AUXR &=0xFE;//选择定时器1作为波特率发生器
//    TMOD &=0x0F;//将定时器1模式置零，准备设置定时器1
//    TMOD |=0x20;//设定定时器1为八位自动重装
//    TL1 = 0xF3;//设定定时器初值
//    TH1 = 0xF3;//设定定时器初值
//    ET1 =0; //禁止定时器1中断
//    TR1=1; //启动定时器1
//}
//void uart_init(void)		//2400bps@12.000MHz
//{
//    PCON &= 0x7F;		//波特率不倍速
//    SCON = 0x50;		//8位数据,可变波特率
////    AUXR &= 0xBF;		//定时器1时钟为Fosc/12,即12T
////    AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
//    TMOD &= 0x0F;		//清除定时器1模式位
//    TMOD |= 0x20;		//设定定时器1为8位自动重装方式
//    TL1 = 0xF3;		//设定定时初值
//    TH1 = 0xF3;		//设定定时器重装值
//    ET1 = 0;		//禁止定时器1中断
//    TR1 = 1;		//启动定时器1
//}

void uart_init(void)		//4800bps@11.0592MHz
{
    PCON &= 0x7F;		//波特率不倍速
    SCON = 0x50;		//8位数据,可变波特率
//    AUXR &= 0xBF;		//定时器1时钟为Fosc/12,即12T
//    AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
    TMOD &= 0x0F;		//清除定时器1模式位
    TMOD |= 0x20;		//设定定时器1为8位自动重装方式
    TL1 = 0xFA;		//设定定时初值
    TH1 = 0xFA;		//设定定时器重装值
    ET1 = 0;		//禁止定时器1中断
    TR1 = 1;		//启动定时器1
}

void uart_sendbyte(unsigned char byte)
{
    SBUF=byte;
	while(TI==0);
	TI=0;
}
