#include "the_auto_turn_where.h"

unsigned char  State_In1_left_front = 1;
unsigned char  State_In2_left_front = 1;
unsigned char  State_In1_right_front = 1;
unsigned char  State_In2_right_front = 1;
unsigned char  State_In1_left_behind = 1;
unsigned char  State_In2_left_behind = 1;
unsigned char  State_In1_right_behind = 1;
unsigned char  State_In2_right_behind = 1;

//具体运动轨迹没有测试，以下各个参数均没有测试。
void go_along (void)
{
	//向钱移动
	State_In1_left_front = 1;
	State_In2_left_front = 0;
	State_In1_right_front = 0;
	State_In2_right_front = 1;
	State_In1_left_behind = 0;
	State_In2_left_behind = 1;
	State_In1_right_behind = 1;
	State_In2_right_behind = 0;
}
void go_back (void)
{
	//向后移动
	State_In1_left_front = 0;
	State_In2_left_front = 1;
	State_In1_right_front = 1;
	State_In2_right_front = 0;
	State_In1_left_behind = 1;
	State_In2_left_behind = 0;
	State_In1_right_behind = 0;
	State_In2_right_behind = 1;
}
void go_left(void)
{
	//向左移动
	State_In1_left_front = 1;
	State_In2_left_front = 0;
	State_In1_right_front = 1;
	State_In2_right_front = 0;
	State_In1_left_behind = 1;
	State_In2_left_behind = 0;
	State_In1_right_behind =1;
	State_In2_right_behind = 0;
}
void go_right(void)
{
	//向右移动
	State_In1_left_front = 0;
	State_In2_left_front = 1;
	State_In1_right_front = 0;
	State_In2_right_front = 1;
	State_In1_left_behind = 0;
	State_In2_left_behind = 1;
	State_In1_right_behind = 0;
	State_In2_right_behind = 1;
}
void turn_left(void)
{
	//左转
	State_In1_left_front = 0;
	State_In2_left_front = 1;
	State_In1_right_front = 0;
	State_In2_right_front = 1;
	State_In1_left_behind = 1;
	State_In2_left_behind = 0;
	State_In1_right_behind = 1;
	State_In2_right_behind = 0;
}
void turn_right(void)
{
	//右转
	State_In1_left_front = 1;
	State_In2_left_front = 0;
	State_In1_right_front = 1;
	State_In2_right_front = 0;
	State_In1_left_behind = 0;
	State_In2_left_behind = 1;
	State_In1_right_behind = 0;
	State_In2_right_behind = 1;
}
void stop(void)
{
	//停止
	State_In1_left_front = 0;
	State_In2_left_front = 0;
	State_In1_right_front = 0;
	State_In2_right_front = 0;
	State_In1_left_behind = 0;
	State_In2_left_behind = 0;
	State_In1_right_behind = 0;
	State_In2_right_behind = 0;
}
void brake(void)
{
	//刹车
	State_In1_left_front = 1;
	State_In2_left_front = 1;
	State_In1_right_front = 1;
	State_In2_right_front = 1;
	State_In1_left_behind = 1;
	State_In2_left_behind = 1;
	State_In1_right_behind = 1;
	State_In2_right_behind = 1;
}
