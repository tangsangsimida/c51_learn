#include <REGX52.H>
#include "c51tangsang.h"
#include <string.h>
sbit RCK  = P3^5;  //RCLK
sbit SRCK = P3^6;  //时钟 SRCLK
sbit SER  = P3^4;  //串行数据 SER

unsigned char clum[]={0xF8,0x49,0x5E,0x48,0x48,0x5E,0x49,0xF8,}; //显示图像的数据,静态显示图像



//写入数据
void show_clum(unsigned char,unsigned char);
static void write_byte(unsigned char);
//此处阳极给1选中，行为共阳连接.
static void write_byte(unsigned char byte)
{
	unsigned char i;
	//把数据放进寄存器，寄存器为不可位操作寄存器利用& |压栈式赋值
	for(i=0;i<8;i++)
	{
		//把最高位取出来
		SER =byte>>7;
		byte<<=1;
		//时钟和rck该复习了
		SRCK =0;
		SRCK =1;
	}
	//需要一个上升沿才能传入数据
	RCK =1;
	//传入数据后让io保持低电平，为下一次传入数据做准备(下一次上升沿)
	RCK =0;
}
void show_clum(unsigned char clum,unsigned char Data)
{
	write_byte(Data);
	P0=~(0x80>>(clum-1));
	//列为共阴极给0选中
}
void main()
{	
	unsigned char cl;
	//上电之后单片机的所有io都是高电平
	SER = 0;
	RCK = 0;


	while(1)
	{
		for(cl=1;cl<=8;cl++)
		{
			show_clum(cl,clum[cl-1]);
		}
	}
}
