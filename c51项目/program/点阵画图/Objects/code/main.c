#include <REGX52.H>
#include "c51tangsang.h"
sbit RCK  = P3^5;  //RCLK
sbit SRCK = P3^6;  //ʱ�� SRCLK
sbit SER  = P3^4;  //�������� SER
//д������
void write_bite(unsigned char byte)
{
	unsigned char i;
	//�����ݷŽ��Ĵ������Ĵ���Ϊ����λ�����Ĵ���
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
void main()
{
	//�ϵ�֮��Ƭ��������io���Ǹߵ�ƽ
	SER = 0;
	RCK = 0;
	write_bite(0xF0);
	while(1)
	{
		
	}
}