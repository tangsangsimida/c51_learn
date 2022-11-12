#include <REGX52.H>
unsigned int time_count=0;


void time_init();//初始化计时器/定时器


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


void time_on() interrupt 1
{
	TH0=64535/256;//高八位数据     晶振12mhz，一个周期为1us，最大65535us，
	TL0=64535%256;//低八位数据->64535 = 65535-1000; -> 1000us=1ms; 定时器单位为1ms
	time_count++;
	if(time_count==1000)
	{
		time_count=0;
		P2=~P2;
	}
}



void main()
{
	P2=0xAA;
	time_init();
	while(1)
	{
		
	}
}

