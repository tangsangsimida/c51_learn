#include <REGX52.H>
#include "c51tangsang.h"
#include <stdio.h>
sbit RCK  = P3^5;  //RCLK
sbit SRCK = P3^6;  //ʱ�� SRCLK
sbit SER  = P3^4;  //�������� SER
//д������
void show_clum(unsigned char,unsigned char);
static void write_byte(unsigned char);
//�˴�������1ѡ�У���Ϊ��������.
static void write_byte(unsigned char byte)
{
	unsigned char i;
	//�����ݷŽ��Ĵ������Ĵ���Ϊ����λ�����Ĵ�������& |ѹջʽ��ֵ
	for(i=0;i<8;i++)
	{
		//�����λȡ����
		SER =byte&(0x80>>i);
	}
	
	//��Ҫһ�������ز��ܴ�������
	SER =1;
	//�������ݺ���io���ֵ͵�ƽ��Ϊ��һ�δ���������׼��(��һ��������)
	SER =0;
}
void show_clum(unsigned char clum,unsigned char Data)
{
	write_byte(Data);
	P0=~(0x80>>(clum-1));
	//��Ϊ��������0ѡ��
}
void main()
{
	//�ϵ�֮��Ƭ��������io���Ǹߵ�ƽ
	SER = 0;
	RCK = 0;
	delay(100);
	show_clum(4,0xAA);
	while(1)
	{
		
	}
}
