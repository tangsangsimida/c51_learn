#include "the_auto_turn_where.h"

sbit PWM_left_behind = P3^0; //PWM1
sbit STBY_left = P3^1;		 //芯片工作状态
sbit IN1_left_behind = P3^2; //IN1
sbit IN2_left_behind = P3^3; //IN2
// 右后方轮子
sbit PWM_right_behind = P2^0; //PWM2
sbit STBY_right = P2^1;		 //芯片工作状态2
sbit IN1_right_behind = P2^3; //IN1_2
sbit IN2_right_behind = P2^2; //IN2_2
// 左前方轮子
sbit PWM_left_front = P0^2; //PWM3
//sbit STBY_right = P2^1;		 //芯片工作状态2
sbit IN1_left_front = P0^0; //IN1_2
sbit IN2_left_front = P0^1; //IN2_2
// 右前方轮子
sbit PWM_right_front = P2^6; //PWM4
//sbit STBY_right = P2^1;		 //芯片工作状态2
sbit IN1_right_front = P2^4; //IN1_2
sbit IN2_right_front = P2^5; //IN2_2

//pwm功率系数100、计时器

unsigned char State_what_to_do_now;
enum State_What_To_Do_Now{goalong=1,goback,turnleft,turnright,goleft,goright}state_whattodo;

//电机功率系数1=100；
unsigned char compare1=20;
unsigned int conter1=0,compare_turn_state=1500;

void Trolley_power(void);

int main ()
{
	//time_0_init()
	time_0_ms_init();
	
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
//		//00------->自由停车
//		//10------->正转
//		//01------->反转
//		//11------->刹车
	}
}

void Trolley_power(void) interrupt 1
{
	TH0=64535/256;//高八位数据     晶振12mhz，一个周期为1us，最大65535us，
	TL0=64535%256;//低八位数据->64535 = 65535-1000; -> 1000us=1ms; 定时器单位为1ms
	conter1++;
	conter1%=3000;
	if(conter1<compare_turn_state)
	{
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
	else
	{
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
}
