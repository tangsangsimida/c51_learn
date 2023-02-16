

#ifndef _THEAUTOTURNWHERE_H_
#define _THESUTOTURNWHERE_H_

#include <REGX52.H>
#include "c51tangsang.h"

//�ĸ����� �˸����ŵ�״̬����
extern unsigned char  State_In1_left_front;
extern unsigned char  State_In2_left_front;
extern unsigned char  State_In1_right_front;
extern unsigned char  State_In2_right_front;
extern unsigned char  State_In1_left_behind;
extern unsigned char  State_In2_left_behind;
extern unsigned char  State_In1_right_behind;
extern unsigned char  State_In2_right_behind;

void go_along (void);
//��Ǯ�ƶ�

void go_back (void);
//����ƶ�

void go_left(void);
//�����ƶ�

void go_right(void);
//�����ƶ�

void turn_left(void);
//��ת

void turn_right(void);
//��ת

void stop(void);
//ֹͣ

void brake(void);
//ɲ��


#endif

