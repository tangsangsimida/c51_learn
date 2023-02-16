

#ifndef _THEAUTOTURNWHERE_H_
#define _THESUTOTURNWHERE_H_

#include <REGX52.H>
#include "c51tangsang.h"

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

