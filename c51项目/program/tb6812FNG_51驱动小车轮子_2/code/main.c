#include <REGX52.H>
#include "c51tangsang.h"

void Delay(unsigned char);
void Trolley_power(void);

sbit PWM_left_behind = P3^0; //PWM1
sbit STBY_left = P3^1;		 //оƬ����״̬
sbit IN1_left_behind = P3^2; //IN1
sbit IN2_left_behind = P3^3; //IN2

sbit PWM_right_behind = P2^0; //PWM2
sbit STBY_right = P2^1;		 //оƬ����״̬2
sbit IN1_right_behind = P2^3; //IN1_2
sbit IN2_right_behind = P2^2; //IN2_2


unsigned char compare1=36,compare2=100,conter1=0,conter2=0;

//pwm��0����ɲ��

int main ()
{
	//time_0_init()
	time_0_ms_init();
	IN2_left_behind = 0;
	IN2_right_behind = 1;
	PWM_right_behind=1;
	PWM_left_behind=1;
	STBY_left = 1;
	STBY_right=1;
	while(1)
	{
		//��ת
//		STBY_left = 1; //�������оƬ��ʼ����
//		PWM_left_behind =1; //pwm���룬����ֱ��ȫ��������---->��1
//		//�����ת����------>����ת
//		//00------->����ͣ��
//		//10------->��ת
//		//01------->��ת
//		//11------->ɲ��
//		IN1_left_behind = 0;
//		IN2_left_behind = 1;
//		Delay(1000);
//		
//		//ɲ��
//		IN1_left_behind = 1;
//		IN2_left_behind = 1;
//		Delay(1000);
//		
		//��ת
//		IN1_left_behind = 1;
//		IN2_left_behind = 0;
//		Delay(1000);

		
	}
}
void Trolley_power(void) interrupt 1
{
	TH0=64535/256;//�߰�λ����     ����12mhz��һ������Ϊ1us�����65535us��
	TL0=64535%256;//�Ͱ�λ����->64535 = 65535-1000; -> 1000us=1ms; ��ʱ����λΪ1ms
	conter1++;
	conter1%=100;
	conter2++;
	conter2%=100;
	if(conter1<compare1)
	{
		IN1_left_behind = 1;
//		IN1_right_behind =0;
		
		
	}
	else
	{
		IN1_left_behind = 0;
//		IN1_right_behind =1;
		
	}
	if(conter2<compare2)
	{
//		IN1_left_behind = 1;
		
		IN1_right_behind =0;
		
	}
	else
	{
//		IN1_left_behind = 0;
		IN1_right_behind =1;
		
	}
//	if(conter1<compare)
//	{
//		IN1_right_behind = 0;
//		
//	}
//	else
//	{
//		IN1_right_behind = 1;
//		
//	}
	
}
// ms
//void Delay(unsigned char num)	
//{
//	unsigned char i, j;

//	while(num--)
//	{
//		i = 2;
//		j = 239;
//		do
//		{
//			while (--j);
//		} while (--i);
//	}
//}
