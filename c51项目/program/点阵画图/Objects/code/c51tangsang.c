#include <REGX52.H>
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
	unsigned char digital_table[]={0x3,0x9F,0x24,0xC,0x99,0x49,0x7D,0x1F,0xFE,0x19};
	switch(th)
	{
		case 1:P2_2=0;P2_3=0;P2_4=0;break;
		case 2:P2_2=0;P2_3=0;P2_4=1;break;
		case 3:P2_2=0;P2_3=1;P2_4=0;break;
		case 4:P2_2=0;P2_3=1;P2_4=1;break;
		case 5:P2_2=1;P2_3=0;P2_4=0;break;
		case 6:P2_2=1;P2_3=0;P2_4=1;break;
		case 7:P2_2=1;P2_3=1;P2_4=0;break;
		case 8:P2_2=1;P2_3=1;P2_4=1;break;
		//Ĭ����ʱ����1����
		default:P2_2=0;P2_3=0;P2_4=0;P0=digital_table[digital];
	}
	P0=digital_table[digital];
}

