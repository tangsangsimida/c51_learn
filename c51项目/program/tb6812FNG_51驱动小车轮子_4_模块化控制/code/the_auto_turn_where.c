#include "the_auto_turn_where.h"

unsigned char  State_In1_left_front = 1;
unsigned char  State_In2_left_front = 1;
unsigned char  State_In1_right_front = 1;
unsigned char  State_In2_right_front = 1;
unsigned char  State_In1_left_behind = 1;
unsigned char  State_In2_left_behind = 1;
unsigned char  State_In1_right_behind = 1;
unsigned char  State_In2_right_behind = 1;

//�����˶��켣û�в��ԣ����¸���������û�в��ԡ�
void go_along (void)
{
	//��Ǯ�ƶ�
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
	//����ƶ�
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
	//�����ƶ�
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
	//�����ƶ�
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
	//��ת
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
	//��ת
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
	//ֹͣ
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
	//ɲ��
	State_In1_left_front = 1;
	State_In2_left_front = 1;
	State_In1_right_front = 1;
	State_In2_right_front = 1;
	State_In1_left_behind = 1;
	State_In2_left_behind = 1;
	State_In1_right_behind = 1;
	State_In2_right_behind = 1;
}
