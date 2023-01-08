#include <REGX52.H>

sfr buffer=0x99;

//unsigned char data_;

void UartInit(void)		//4800bps@11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFA;		//设定定时初值
	TH1 = 0xFA;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	
	//波特率计算器只能给出计算波特率的代码，默认不会把中断打开，需要自己手动打开中断；
	EA=1;
	ES=1;
}


void Uart_sendByte(unsigned char Byte)
{
	buffer = Byte;
	while(TI==0);
	TI=0;
}

void Delay1ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}

void ReceptionByte() interrupt 4
{
	P2=~P2;
	if(RI==1)
	{
		
		Uart_sendByte(buffer);
		RI=0;
	}
	// Uart_sendByte(buffer); 不能在中断函数中直接sendByte
	// 还是需要将数据外送才能继续发送
}

void main()
{

	UartInit();
	//当单片机接收到信息马上返回给computer--->收到就发出来
	while(1)
	{
		
	}
		
}

