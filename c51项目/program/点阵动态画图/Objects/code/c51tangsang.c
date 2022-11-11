#include <REGX52.H>
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
		//默认暂时先用1代替
		default:P2_2=0;P2_3=0;P2_4=0;P0=digital_table[digital];
	}
	P0=digital_table[digital];
}

