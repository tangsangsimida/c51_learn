

#ifndef _THEAUTOTURNWHERE_H_
#define _THESUTOTURNWHERE_H_

#include <REGX52.H>
#include "c51tangsang.h"

extern unsigned char  State_In1_left_front;
extern unsigned char  State_In2_left_front;
extern unsigned char  State_In1_right_front;
extern unsigned char  State_In2_right_front;
extern unsigned char  State_In1_left_behind;
extern unsigned char  State_In2_left_behind;
extern unsigned char  State_In1_right_behind;
extern unsigned char  State_In2_right_behind;



void go_along (void);

void go_back (void);

void go_left(void);

void go_right(void);

void turn_left(void);

void turn_right(void);

void stop(void);

void brake(void);


#endif

