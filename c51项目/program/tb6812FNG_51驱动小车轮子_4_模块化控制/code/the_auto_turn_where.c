#include <REGX52.H>
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


unsigned char  State_In1_left_front = 1;
unsigned char  State_In2_left_front = 1;
unsigned char  State_In1_right_front = 1;
unsigned char  State_In2_right_front = 1;
unsigned char  State_In1_left_behind = 1;
unsigned char  State_In2_left_behind = 1;
unsigned char  State_In1_right_behind = 1;
unsigned char  State_In2_right_behind = 1;
void go_along (void)
{
	State_In1_left_front = 0;
	State_In2_left_front = 1;
	State_In1_right_front = 0;
	State_In2_right_front = 1;
	State_In1_left_behind = 0;
	State_In2_left_behind = 1;
	State_In1_right_behind = 0;
	State_In2_right_behind = 1;
}
void go_back (void)
{
	State_In1_left_front = 1;
	State_In2_left_front = 0;
	State_In1_right_front = 1;
	State_In2_right_front = 0;
	State_In1_left_behind = 1;
	State_In2_left_behind = 0;
	State_In1_right_behind = 1;
	State_In2_right_behind = 0;
}
void go_left(void)
{
	
}
void go_right(void)
{
	
}
void turn_left(void)
{
	
}
void turn_right(void)
{
	
}
void stop(void)
{
	
}
void brake(void)
{

}
