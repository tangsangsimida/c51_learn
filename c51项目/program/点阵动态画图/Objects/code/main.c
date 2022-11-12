#include <REGX52.h>
#include "c51tangsang.h"
#include <string.h>
sbit RCK  = P3^5;  //
sbit SRCK = P3^6;  //
sbit SER  = P3^4;  //

unsigned char clum[]={0xFE,0x0E,0x0F,0x1E,0x10,0x11,0x18,0x92,0x10,0x20,0xA8,0x92,0x10,0x20,0x88,0x8E,
0x10,0x20,0x88,0x82,0x10,0x11,0x88,0x92,0x10,0x0E,0x48,0x8E,0x10,0x00,0x00,0x00,}; //



//д������
void show_clum(unsigned char,unsigned char);
static void write_byte(unsigned char);
//
static void write_byte(unsigned char byte)
{
	unsigned char i;
	//
	for(i=0;i<8;i++)
	{
		//�����λȡ����
		SER =byte>>7;
		byte<<=1;
		//ʱ�Ӻ�rck�ø�ϰ��
		SRCK =0;
		SRCK =1;
	}
	//
	RCK =1;
	//
	RCK =0;
}
void show_clum(unsigned char clum,unsigned char Data)
{
	write_byte(Data);
	P0=~(0x80>>(clum-1));
	//
}
//lattice_init
void led_init()
{
	SER = 0;
	RCK = 0;
}
void main()
{	
	unsigned char cl;
	//
	led_init();
	while(1)
	{
		for(cl=1;cl<=strlen(clum);cl++)
		{
			show_clum(cl,clum[cl-1]);
		}
		delay(500);
	}
}
