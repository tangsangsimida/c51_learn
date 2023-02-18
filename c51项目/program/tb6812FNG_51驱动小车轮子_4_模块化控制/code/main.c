#include "the_auto_turn_where.h"
#include <REGX52.H>
#include "c51tangsang.h"

//电机功率系数1=100；
unsigned char conter2=0,compare=20;
unsigned int conter1=0,compare_turn_state=1000;
//根基小车的固定路径，计算出规则进行设计路线，不可进行路径临时改变
void work_use_time(void);
//定时器
void time_10_us_init(void);
void auto_pwm(void);
int main ()
{
	//time_0_init()
	time_0_ms_init();
	//time1
	time_10_us_init();
	
	//四个电机八个控制位全部置1初始化刹车
	IN1_right_front = State_In1_left_front;
	IN1_right_behind = State_In1_left_behind;
	IN1_left_front = State_In1_right_front;
	IN1_left_behind = State_In1_right_behind;
	IN2_right_front = State_In2_left_front;
	IN2_right_behind = State_In2_left_behind;
	IN2_left_front = State_In2_right_front;
	IN2_left_behind = State_In2_right_behind;
	
	//电机给电
	PWM_right_behind=1;
	PWM_right_front = 1;
	PWM_left_behind=1;
	PWM_left_front = 1;
	
	//芯片使能
	STBY_left = 1;
	STBY_right=1;
	
	while(1)
	{
		//正转
//		STBY_left = 1; //电机驱动芯片开始工作
//		PWM_left_behind =1; //pwm输入，可以直接全功率输入---->置1
//		//电机旋转方向------>正反转
//		//正转
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
	TF1=0;//设置默认为未溢出	

//	IE1=1;//中断开关
//	IT1=1;
	
	ET1=1;//三个中断系统的接口
	PT1=1;
	TR1=1;//定时器1开始运行
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
	TH0=65525/256;	//高八位数据     晶振12mhz，一个周期为1ms，最大65535us，
	TL0=65525%256;	//低八位数据->64535 = 65535-1000; -> 1000us=1ms; 定时器单位为1ms
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
