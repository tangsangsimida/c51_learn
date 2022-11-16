
#include "c51tangsang.h"

/*
 *�ÿ�Ϊtangsang���ִ��죬�˹����죬�Ƚϴֲڣ�����Ƿȱ��覴ã����ṩѧϰ�ο� 
 *�ÿ�Ϊtangsang���ִ��죬�˹����죬�Ƚϴֲڣ�����Ƿȱ��覴ã����ṩѧϰ�ο� 
 *�ÿ�Ϊtangsang���ִ��죬�˹����죬�Ƚϴֲڣ�����Ƿȱ��覴ã����ṩѧϰ�ο� 
 */



//��ʱ����
//unsigned int ms������λ���� 
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
//��λ�����ָ��λ����ʾ����
//���ڿ���չΪ������ʾ��ĸ�����֣�or DIY��ʾ 
void show_digital(unsigned int th,unsigned int digital)
{
	//��һ���������ܹ���ʾ���������֣����ڸ���ĸ��һ������
	//�˴������ڴ�Խ��������Ӧ�жϴ���Ĳ����Ƿ��ڹ涨����������ڣ���������ʾ�涨���ݣ���Ҫ�ǳ���Ա�Լ����Գ����ʱ�������±�Խ��
	//����Ҳ����ͨ����ťʵ���������ʾ��Ӧ������
	//����ͨ����ť��ʾ���Ӧ������ 
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
		//Ĭ����ʱ����1����
		default:P2_2=0;P2_3=0;P2_4=0;P0=digital_table[digital];
	}
	//����������ǹ������ģ�����ֱ��ȡ��������д���룬ֱ�Ӱٶȵģ���������ǹ����� �ģ�����
	P0=~digital_table[digital];
	delay(1);
	//������
	
}

static void write_byte(unsigned char byte)
{
	unsigned char i;
	//�����ݷŽ��Ĵ������Ĵ���Ϊ����λ�����Ĵ�������& |ѹջʽ��ֵ
	for(i=0;i<8;i++)
	{
		//�����λȡ����
		SER =byte>>7;
		byte<<=1;
		//ʱ�Ӻ�rck�ø�ϰ��
		SRCK =0;
		SRCK =1;
	}
	//��Ҫһ�������ز��ܴ�������
	RCK =1;
	//�������ݺ���io���ֵ͵�ƽ��Ϊ��һ�δ���������׼��(��һ��������)
	RCK =0;
}


void show_clum(unsigned char clum,unsigned char Data)
{
	write_byte(Data);
	P0=~(0x80>>(clum-1));
	//��Ϊ��������0ѡ��
}

//��ʱ��������λ��us
void delayus(unsigned int j)		//@12.000MHz
{
	unsigned char i;
	while(j--)
	{
		i = 2;
		while (--i);
	}
}

// uint i --->������һ������ĳ���
void beep(uint i)
{
		while(i--)
		{
			P2_5=0;
			delayus(20);//�ߵ�ƽ��ռ��ʱ��Խ��������������Խ�ߣ�
			P2_5=1;
			delayus(10);
		}
}
void time_0_ms_init()
{
	//TMOD = 0x01;//����ģʽ������λѰַ��ÿһ��λ������Ӧ�ĺ��壬
	TMOD&=0xF0;//�����д�����ܴ�������һ����ʱ����ͻ�������
	TMOD|=0x01;//��&|�ķ�ʽ��ֵ����Ӱ����һ����ʱ��������
	TF0=0;//Ĭ��Ӧ����0�����ò�Ӱ�죬����һ��ʼ�Ͳ����ж�;
	TH0=64535/256;//�߰�λ����     ����12mhz��һ������Ϊ1us�����65535us��
	TL0=64535%256;//�Ͱ�λ����->64535 = 65535-1000; -> 1000us=1ms; ��ʱ����λΪ1ms
	ET0=1;//�����ж�ϵͳ�Ľӿ�
	EA=1;
	PT0=0;
	TR0=1; //��ʱ��0�����п���λ
}

void time_1_ms_init()
{
	TMOD&=0x0F;
	TMOD|=0x10;
	TL1=64535%256;
	TH1=64535/256;
	TF1=0;//����Ĭ��Ϊδ���	

//	IE1=1;//�жϿ���
//	IT1=1;
	
	ET1=1;//�����ж�ϵͳ�Ľӿ�
	EA=1;
	PT1=0;
	
	TR1=1;//��ʱ��1��ʼ����
}

void time_1_us_init()
{
	TMOD&=0x0F;
	TMOD|=0x10;
	TL1=65534%256;
	TH1=65534/256;
	TF1=0;//����Ĭ��Ϊδ���	

//	IE1=1;//�жϿ���
//	IT1=1;
	
	ET1=1;//�����ж�ϵͳ�Ľӿ�
	EA=1;
	PT1=0;
	
	TR1=1;//��ʱ��1��ʼ����
}

void time_0_us_init()
{
	//TMOD = 0x01;//����ģʽ������λѰַ��ÿһ��λ������Ӧ�ĺ��壬
	TMOD&=0xF0;//�����д�����ܴ�������һ����ʱ����ͻ�������
	TMOD|=0x01;//��&|�ķ�ʽ��ֵ����Ӱ����һ����ʱ��������
	TF0=0;//Ĭ��Ӧ����0�����ò�Ӱ�죬����һ��ʼ�Ͳ����ж�;
	TH0=65534/256;//�߰�λ����     ����12mhz��һ������Ϊ1us�����65535us��
	TL0=65534%256;//�Ͱ�λ����->64535 = 65535-1000; -> 1000us=1ms; ��ʱ����λΪ1ms
	ET0=1;//�����ж�ϵͳ�Ľӿ�
	EA=1;
	PT0=0;
	TR0=1; //��ʱ��0�����п���λ
}

//��ȡ��������״̬
uint buttom_getstate_4()
{
	if(P3_0==0)
	{
		delay(20);while(P3_0==0);delay(20);return 2;
	}
	if(P3_1==0)
	{
		delay(10);while(P3_1==0);delay(20);return 1;
	}
	if(P3_2==0)
	{
		delay(10);while(P3_2==0);delay(20);return 3;
	}
	if(P3_3==0)
	{
		delay(10);while(P3_3==0);delay(20);return 4;
	}
	return 0;
}

int buttom_getstate_16()
{
    int state=0;
    P1=0xFF;
    //�Ȱ�P1ȫ����1��Ȼ�����Ӧio��0��һ���ж�
    P1_3=0;
    //������̵�һ��--->�ж��������
    if(P1_7==0){ delay(50);while(P1_7==0);delay(20);state=1;}
    if(P1_6==0){ delay(50);while(P1_7==0);delay(20);state=5;}
    if(P1_5==0){ delay(50);while(P1_7==0);delay(20);state= 9;}
    if(P1_4==0){ delay(50);while(P1_7==0);delay(20);state= 13;}

    P1=0xFF;
    //�Ȱ�P1ȫ����1��Ȼ�����Ӧio��0��һ���ж�
    P1_2=0;
    //������̵ڶ���--->0100
    if(P1_7==0){ delay(20);while(P1_7==0);delay(20);state= 2;}
    if(P1_6==0){ delay(20);while(P1_7==0);delay(20);state= 6;}
    if(P1_5==0){ delay(20);while(P1_7==0);delay(20);state= 10;}
    if(P1_4==0){ delay(20);while(P1_7==0);delay(20);state= 14;}

    P1=0xFF;
    //�Ȱ�P1ȫ����1��Ȼ�����Ӧio��0��һ���ж�
    P1_1=0;
    //������̵ڶ���--->0010
    if(P1_7==0){ delay(20);while(P1_7==0);delay(20);state= 3;}
    if(P1_6==0){ delay(20);while(P1_7==0);delay(20);state= 7;}
    if(P1_5==0){ delay(20);while(P1_7==0);delay(20);state= 11;}
    if(P1_4==0){ delay(20);while(P1_7==0);delay(20);state= 15;}

    P1=0xFF;
    //�Ȱ�P1ȫ����1��Ȼ�����Ӧio��0��һ���ж�
    P1_0=0;
    //������̵ڶ���--->0001
    if(P1_7==0){ delay(20);while(P1_7==0);delay(20);state= 4;}
    if(P1_6==0){ delay(20);while(P1_7==0);delay(20);state= 8;}
    if(P1_5==0){ delay(20);while(P1_7==0);delay(20);state= 12;}
    if(P1_4==0){ delay(20);while(P1_7==0);delay(20);state= 16;}

    return state;
}