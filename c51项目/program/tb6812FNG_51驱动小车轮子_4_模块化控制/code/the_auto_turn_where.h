#ifndef _THEAUTOTURNWHERE_H_
#define _THESUTOTURNWHERE_H_

#include <REGX52.H>
#include "c51tangsang.h"
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

//霍尔传感器//left
sbit Adc_left = P0^7;
sbit E1A_left = P3^4;
sbit E1B_left = P3^5;
sbit E2A_left = P3^6;
sbit E2B_left = P3^7;
//霍尔传感器//right
sbit Adc_right = P1^3;
sbit E1A_right = P3^4;
sbit E1B_right = P3^5;
sbit E2A_right = P3^6;
sbit E2B_right = P3^7;

//四个轮子 八个引脚的状态变量
extern unsigned char  State_In1_left_front;
extern unsigned char  State_In2_left_front;
extern unsigned char  State_In1_right_front;
extern unsigned char  State_In2_right_front;
extern unsigned char  State_In1_left_behind;
extern unsigned char  State_In2_left_behind;
extern unsigned char  State_In1_right_behind;
extern unsigned char  State_In2_right_behind;

void go_along (void);
//向钱移动

void go_back (void);
//向后移动

void go_left(void);
//向左移动

void go_right(void);
//向右移动

void turn_left(void);
//左转

void turn_right(void);
//右转

void stop(void);
//停止

void brake(void);
//刹车


#endif

