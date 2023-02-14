#include <REGX52.H>
#include "c51tangsang.h"

void Delay(unsigned char);
void Trolley_power(void);

// 左后方轮子
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


unsigned char compare1=20,conter1=0;

//pwm给0代表刹车

int main ()
{
	//time_0_init()
	time_0_ms_init();
	
	
	IN2_left_behind = 1;
	IN2_right_behind = 0;
	IN2_left_front = 0;
	IN2_right_front = 1;
	
	
	PWM_right_behind=1;
	PWM_right_front = 1;
	PWM_left_behind=1;
	PWM_left_front = 1;
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
	conter1%=100;
	if(conter1<compare1)
	{
		IN1_left_behind = 0;
		IN1_right_behind =1;
		IN1_left_front = 1;
		IN1_right_front = 0;
		
	}
	else
	{
		IN1_left_behind = 0;
		IN1_right_behind = 0;
		IN1_left_front = 0;
		IN1_right_front = 0;
		
	}

	
}