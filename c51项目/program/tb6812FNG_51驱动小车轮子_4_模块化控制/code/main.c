#include "the_auto_turn_where.h"
#include <REGX52.H>
#include "c51tangsang.h"

//�������ϵ��1=100��
unsigned char conter2=0,compare=20;
unsigned int conter1=0,compare_turn_state=1000;
//����С���Ĺ̶�·�������������������·�ߣ����ɽ���·����ʱ�ı�
void work_use_time(void);
//��ʱ��
void time_10_us_init(void);
void auto_pwm(void);
int main ()
{
	//time_0_init()
	time_0_ms_init();
	//time1
	time_10_us_init();
	
	//�ĸ�����˸�����λȫ����1��ʼ��ɲ��
	IN1_right_front = State_In1_left_front;
	IN1_right_behind = State_In1_left_behind;
	IN1_left_front = State_In1_right_front;
	IN1_left_behind = State_In1_right_behind;
	IN2_right_front = State_In2_left_front;
	IN2_right_behind = State_In2_left_behind;
	IN2_left_front = State_In2_right_front;
	IN2_left_behind = State_In2_right_behind;
	
	//�������
	PWM_right_behind=1;
	PWM_right_front = 1;
	PWM_left_behind=1;
	PWM_left_front = 1;
	
	//оƬʹ��
	STBY_left = 1;
	STBY_right=1;
	
	while(1)
	{
		//��ת
//		STBY_left = 1; //�������оƬ��ʼ����
//		PWM_left_behind =1; //pwm���룬����ֱ��ȫ��������---->��1
//		//�����ת����------>����ת
//		//��ת
//		State_In1_left_front = 1;
//		State_In2_left_front = 0;
//		State_In1_right_front = 0;
//		State_In2_right_front = 1;
//		State_In1_left_behind = 0;
//		State_In2_left_behind = 1;
//		State_In1_right_behind = 1;
//		State_In2_right_behind = 0;
	}
}
void time_10_us_init(void)
{
	TMOD&=0x0F;
	TMOD|=0x10;
	TL1=65405%256;
	TH1=65405/256;
	TF1=0;//����Ĭ��Ϊδ���	

//	IE1=1;//�жϿ���
//	IT1=1;
	
	ET1=1;//�����ж�ϵͳ�Ľӿ�
	PT1=1;
	TR1=1;//��ʱ��1��ʼ����
}
void auto_pwm(void) interrupt 3
{
	//10us 
	TL1=65435%256;
	TH1=65435/256;
	conter2++;
	conter2%=100;
	if(conter2>compare)
	{
		stop();
		IN1_right_front = State_In1_left_front;
		IN1_right_behind = State_In1_left_behind;
		IN1_left_front = State_In1_right_front;
		IN1_left_behind = State_In1_right_behind;
		IN2_right_front = State_In2_left_front;
		IN2_right_behind = State_In2_left_behind;
		IN2_left_front = State_In2_right_front;
		IN2_left_behind = State_In2_right_behind;
	}
	
}
void work_use_time(void) interrupt 1
{
	TH0=65525/256;	//�߰�λ����     ����12mhz��һ������Ϊ1ms�����65535us��
	TL0=65525%256;	//�Ͱ�λ����->64535 = 65535-1000; -> 1000us=1ms; ��ʱ����λΪ1ms
	conter1++;
	conter1%=4000;
	if(conter1<500)
	{
		compare=20;
		brake();
		go_along();
		IN1_right_front = State_In1_left_front;
		IN1_right_behind = State_In1_left_behind;
		IN1_left_front = State_In1_right_front;
		IN1_left_behind = State_In1_right_behind;
		IN2_right_front = State_In2_left_front;
		IN2_right_behind = State_In2_left_behind;
		IN2_left_front = State_In2_right_front;
		IN2_left_behind = State_In2_right_behind;
	}
	else if(conter1<1500&&conter1>=1000)
	{
		compare=20;
		go_right();
		IN1_right_front = State_In1_left_front;
		IN1_right_behind = State_In1_left_behind;
		IN1_left_front = State_In1_right_front;
		IN1_left_behind = State_In1_right_behind;
		IN2_right_front = State_In2_left_front;
		IN2_right_behind = State_In2_left_behind;
		IN2_left_front = State_In2_right_front;
		IN2_left_behind = State_In2_right_behind;
		
	}
	else if(conter1<2500&&conter1>=2000)
	{
		compare=20;
		go_back();
		IN1_right_front = State_In1_left_front;
		IN1_right_behind = State_In1_left_behind;
		IN1_left_front = State_In1_right_front;
		IN1_left_behind = State_In1_right_behind;
		IN2_right_front = State_In2_left_front;
		IN2_right_behind = State_In2_left_behind;
		IN2_left_front = State_In2_right_front;
		IN2_left_behind = State_In2_right_behind;
	}
	else if(conter1<3500&&conter1>=3000)
	{
		compare=20;
		go_left();
		IN1_right_front = State_In1_left_front;
		IN1_right_behind = State_In1_left_behind;
		IN1_left_front = State_In1_right_front;
		IN1_left_behind = State_In1_right_behind;
		IN2_right_front = State_In2_left_front;
		IN2_right_behind = State_In2_left_behind;
		IN2_left_front = State_In2_right_front;
		IN2_left_behind = State_In2_right_behind;

	}
	else
	{
		stop();
		IN1_right_front = State_In1_left_front;
		IN1_right_behind = State_In1_left_behind;
		IN1_left_front = State_In1_right_front;
		IN1_left_behind = State_In1_right_behind;
		IN2_right_front = State_In2_left_front;
		IN2_right_behind = State_In2_left_behind;
		IN2_left_front = State_In2_right_front;
		IN2_left_behind = State_In2_right_behind;
	}
}
