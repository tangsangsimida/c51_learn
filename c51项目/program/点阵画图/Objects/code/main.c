#include <REGX52.H>
#include "c51tangsang.h"
sbit RCK  = P3^5;  //RCLK
sbit SRCK = P3^6;  //时钟 SRCLK
sbit SER  = P3^4;  //串行数据 SER
//写入数据
void write_bite(unsigned char byte)
{
	unsigned char i;
	//把数据放进寄存器，寄存器为不可位操作寄存器
	for(i=0;i<8;i++)
	{
		//把最高位取出来
		SER =byte&(0x80>>i);
	}
	//需要一个上升沿才能传入数据
	SER =1;
	//传入数据后让io保持低电平，为下一次传入数据做准备(下一次上升沿)
	SER =0;
}
void main()
{
	//上电之后单片机的所有io都是高电平
	SER = 0;
	RCK = 0;
	write_bite(0xF0);
	while(1)
	{
		
	}
}