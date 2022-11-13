
#include "c51tangsang.h"

/*
 *该库为tangsang亲手打造，人工打造，比较粗糙，功能欠缺或瑕疵，仅提供学习参考 
 *该库为tangsang亲手打造，人工打造，比较粗糙，功能欠缺或瑕疵，仅提供学习参考 
 *该库为tangsang亲手打造，人工打造，比较粗糙，功能欠缺或瑕疵，仅提供学习参考 
 */



//延时函数
//unsigned int ms参数单位毫秒 
void delay(unsigned int ms)
{
	unsigned char i, j;
	while(ms--)
	{	
		i = 12;
		j = 169;
		do
		{
			while (--j);
		} while (--i);
	}
}
//八位数码管指定位置显示数字
//后期可扩展为智能显示字母或数字，or DIY显示 
void show_digital(unsigned int th,unsigned int digital)
{
	//给一个数组存放能够显示的所有数字，后期给字母换一个表存放
	//此处存在内存越界的情况，应判断传入的参数是否在规定数码管数量内，超出则显示规定内容，主要是程序员自己调试程序的时候会出现下标越界
	//后期也可以通过按钮实现数码管显示相应的内容
	//或者通过按钮显示相对应的数字 
	//0-9 
	unsigned char code digital_table[]={0xc0,0xf9,0xa4,0xb0, 
																			0x99,0x92,0x82,0xf8,  
																			0x80,0x90,0x88,0x83, 
																			0xc6,0xa1,0x86,0x8e};
	switch(th)
	{																		//    P2_4 P2_3 P2_2
		case 8:P2_2=0;P2_3=0;P2_4=0;break;// 1. 1			1 		1
		case 4:P2_2=0;P2_3=0;P2_4=1;break;// 2. 1			1			0
		case 6:P2_2=0;P2_3=1;P2_4=0;break;// 3. 1 		0 		1
		case 2:P2_2=0;P2_3=1;P2_4=1;break;// 4. 1 		0 		0
		case 7:P2_2=1;P2_3=0;P2_4=0;break;// 5. 0 		1 		1
		case 3:P2_2=1;P2_3=0;P2_4=1;break;// 6. 0 		1 		0
		case 5:P2_2=1;P2_3=1;P2_4=0;break;// 7. 0 		0 		1
		case 1:P2_2=1;P2_3=1;P2_4=1;break;// 8. 0 		0 		0
		//默认暂时先用1代替
		default:P2_2=0;P2_3=0;P2_4=0;P0=digital_table[digital];
	}
	//上面的字码是共阳极的，所以直接取反，懒得写字码，直接百度的，结果发现是共阳极 的，潮。
	P0=~digital_table[digital];
	delay(1);
	//消个抖
	
}

static void write_byte(unsigned char byte)
{
	unsigned char i;
	//把数据放进寄存器，寄存器为不可位操作寄存器利用& |压栈式赋值
	for(i=0;i<8;i++)
	{
		//把最高位取出来
		SER =byte>>7;
		byte<<=1;
		//时钟和rck该复习了
		SRCK =0;
		SRCK =1;
	}
	//需要一个上升沿才能传入数据
	RCK =1;
	//传入数据后让io保持低电平，为下一次传入数据做准备(下一次上升沿)
	RCK =0;
}


void show_clum(unsigned char clum,unsigned char Data)
{
	write_byte(Data);
	P0=~(0x80>>(clum-1));
	//列为共阴极给0选中
}

//定时器初始化
void time_init()
{
	//TMOD = 0x01;//工作模式，不可位寻址，每一个位都有相应的含义，
	TMOD&=0xF0;//上面的写法可能存在与另一个定时器冲突的情况；
	TMOD|=0x01;//用&|的方式赋值不会影响另一个定时器的运行
	TF0=0;//默认应该是0不配置不影响，避免一开始就产生中断;
	TH0=64535/256;//高八位数据     晶振12mhz，一个周期为1us，最大65535us，
	TL0=64535%256;//低八位数据->64535 = 65535-1000; -> 1000us=1ms; 定时器单位为1ms
	ET0=1;//三个中断系统的接口
	EA=1;
	PT0=0;
	TR0=1; //定时器0的运行控制位
}

//延时函数，单位：us
void delayus(unsigned int j)		//@12.000MHz
{
	unsigned char i;
	while(j--)
	{
		i = 2;
		while (--i);
	}
}

// uint i --->蜂鸣器一次声响的长度
void beep(uint i)
{
		while(i--)
		{
			P2_5=0;
			delayus(20);//高电平的占用时间越长蜂鸣器的音调越高，
			P2_5=1;
			delayus(10);
		}
}
