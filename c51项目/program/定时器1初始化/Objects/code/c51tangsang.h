/*
 *该库为tangsang亲手打造，人工打造，比较粗糙，功能欠缺或瑕疵，仅提供学习参考 
 *该库为tangsang亲手打造，人工打造，比较粗糙，功能欠缺或瑕疵，仅提供学习参考 
 *该库为tangsang亲手打造，人工打造，比较粗糙，功能欠缺或瑕疵，仅提供学习参考 
 */
 
 
 #include <REGX52.H>
 
sbit RCK  = P3^5;  //
sbit SRCK = P3^6;  //
sbit SER  = P3^4;  //
sbit Buzzer=P2^5; //蜂鸣器
 
 
//用宏将无符号的类型简化 
typedef unsigned int uint;
typedef unsigned char uchar;




#ifndef  _C51TANGSANG_H_
#define  _C51TANGSANG_H_

void time_init();
//定时器声明
void delayus(unsigned int);
extern void delay(unsigned int);
//延时函数，单位ms

extern void show_digital(unsigned int th,unsigned int digital);
//静态数码管显示，1.第几位显示，2.显示的数字。，暂时不能显示字母；

extern void show_clum(unsigned char,unsigned char);
//led点阵图按列显示1.显示的某一列，2.显示的数据，二进制。

void beep(uint i);
//蜂鸣器发声一次，i->发声的时间长度

void time_0_init();
//定时器0初始化，一毫秒溢出 优先级为 --> 1

void time_1_init();
//定时器1初始化，一毫秒溢出 优先级为 --> 3
#endif


