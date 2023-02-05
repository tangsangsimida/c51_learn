/*
 *�ÿ�Ϊtangsang���ִ��죬�˹����죬�Ƚϴֲڣ�����Ƿȱ��覴ã����ṩѧϰ�ο� 
 *�ÿ�Ϊtangsang���ִ��죬�˹����죬�Ƚϴֲڣ�����Ƿȱ��覴ã����ṩѧϰ�ο� 
 *�ÿ�Ϊtangsang���ִ��죬�˹����죬�Ƚϴֲڣ�����Ƿȱ��覴ã����ṩѧϰ�ο� 
 */
 
 
 #include "REG52.H"
 
sbit RCK  = P3^5;  //
sbit SRCK = P3^6;  //
sbit SER  = P3^4;  //
sbit Buzzer=P2^5; //������
sbit time_0_case=TCON^4;
//��ʱ������Ӧ����Ĭ��Ϊ0�ģ����ر�״̬
 
//�ú꽫�޷��ŵ����ͼ� 
typedef unsigned int uint;
typedef unsigned char uchar;



extern uchar date_uart;//����ʵʱ�������ܵ�������




#ifndef  _C51TANGSANG_H_
#define  _C51TANGSANG_H_

void delayus(unsigned int);
extern void delay(unsigned int);
//��ʱ��������λms

extern void show_digital(unsigned int th,unsigned int digital);
//��̬�������ʾ��1.�ڼ�λ��ʾ��2.��ʾ�����֡�����ʱ������ʾ��ĸ��

extern void show_clum(unsigned char,unsigned char);
//led����ͼ������ʾ1.��ʾ��ĳһ�У�2.��ʾ�����ݣ������ơ�

extern void beep(uint i);
//����������һ�Σ�i->������ʱ�䳤��

extern void time_0_ms_init();
//��ʱ��0��ʼ����һ������� ���ȼ�Ϊ --> 1

extern void time_1_ms_init();
//��ʱ��1��ʼ����һ������� ���ȼ�Ϊ --> 3

extern void time_1_us_init();

extern void time_0_us_init();

extern uint buttom_getstate_4();
//��ȡ��������״̬

extern int buttom_getstate_16();
//��ȡ������̵�״̬��

extern void uart_init();
//���ڳ�ʼ��4800������

extern void uart_sendbyte(unsigned char);
//��Ƭ����������

extern void uart_getdata();
/*
 * uart��������
 * ���ڽ������ݻᴥ���жϣ�����������Ժܴ󣬺����൱��һ��ģ��
 * */


#endif


