/*
 *�ÿ�Ϊtangsang���ִ��죬�˹����죬�Ƚϴֲڣ�����Ƿȱ��覴ã����ṩѧϰ�ο� 
 *�ÿ�Ϊtangsang���ִ��죬�˹����죬�Ƚϴֲڣ�����Ƿȱ��覴ã����ṩѧϰ�ο� 
 *�ÿ�Ϊtangsang���ִ��죬�˹����죬�Ƚϴֲڣ�����Ƿȱ��覴ã����ṩѧϰ�ο� 
 */
 
 
 #include <REGX52.H>
 
sbit RCK  = P3^5;  //
sbit SRCK = P3^6;  //
sbit SER  = P3^4;  //
sbit Buzzer=P2^5; //������
 
 
//�ú꽫�޷��ŵ����ͼ� 
typedef unsigned int uint;
typedef unsigned char uchar;




#ifndef  _C51TANGSANG_H_
#define  _C51TANGSANG_H_

void time_init();
//��ʱ������

extern void delay(unsigned int);
//��ʱ��������λms

extern void show_digital(unsigned int th,unsigned int digital);
//��̬�������ʾ��1.�ڼ�λ��ʾ��2.��ʾ�����֡�����ʱ������ʾ��ĸ��

extern void show_clum(unsigned char,unsigned char);
//led����ͼ������ʾ1.��ʾ��ĳһ�У�2.��ʾ�����ݣ������ơ�

void Buzzer_on(uint ms);
//��������1.Ƶ��

#endif


