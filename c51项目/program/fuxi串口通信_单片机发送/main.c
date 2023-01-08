#include <REGX52.H>

sfr buffer=0x99;

//unsigned char data_;

void UartInit(void)		//4800bps@11.0592MHz
{
	PCON &= 0x7F;		//�����ʲ�����
	SCON = 0x50;		//8λ����,�ɱ䲨����
	TMOD &= 0x0F;		//�����ʱ��1ģʽλ
	TMOD |= 0x20;		//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
	TL1 = 0xFA;		//�趨��ʱ��ֵ
	TH1 = 0xFA;		//�趨��ʱ����װֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//������ʱ��1
	
	//�����ʼ�����ֻ�ܸ������㲨���ʵĴ��룬Ĭ�ϲ�����жϴ򿪣���Ҫ�Լ��ֶ����жϣ�
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
	// Uart_sendByte(buffer); �������жϺ�����ֱ��sendByte
	// ������Ҫ���������Ͳ��ܼ�������
}

void main()
{

	UartInit();
	//����Ƭ�����յ���Ϣ���Ϸ��ظ�computer--->�յ��ͷ�����
	while(1)
	{
		
	}
		
}

