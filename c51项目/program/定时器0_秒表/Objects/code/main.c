#include <intrins.h>
#include "c51tangsang.h"
#include "LCD1602_b.h"

void menu_main();
void menu_time();
void show_time();
void time_clear_0();

//定时器实现秒表功能
//1.利用lcd1602动态显示
//2.用独立按键1实现启动并显示秒表界面
//3.用独立按键2实现开始计时功能，再次按下独立按键2可暂停
//4.用独立按键3实现结束计时，并将计时器置零
//5.用独立按键4实现推出计时器功能
//6.推出计时器后显示hello字样，在启动时显示hello字样

uchar s=0,m=0,h=0;
uint ms=0;
uchar buttom_state=0;//判断是否进入计时器
uchar time_begining=0;//time_begining ---->定时器是否在运行1on2off;
uchar buttom_time_on_state=0;//在计时器中的按钮状态
uchar buttom_jishi=0; //正在计时的时候的按键状态

//需要实时更新状态的变量
uchar time_on_start=0; //计时器是否正在计时1:在，0：不在
uchar time_on=0;//是否在计时器界面；1.在/ 0：不在





int main()
{
    //
	LCD_Init();
    time_0_ms_init();
    //启动定时器0;
    time_0_case=0;

	while(1)
	{
begin:
        menu_main();
        //初始化开始菜单

        //读取当前按键状态，如果1按下，就进入计时器；
        buttom_state=buttom_getstate_4()+1;
        //这里有个bug，如果直接读取返回值的话读取1的时候每个按键都可以控制，
        // 这里==如果后面的判断值为1的话，它感觉它默认是在bool判断
        if(buttom_state==2&&time_on==0)
        {
            time_on=1;//按钮1被按下，进入计时器,更新状态
            menu_time();
            buttom_time_on_state=1;
            while(buttom_time_on_state)                                                                 //定时器窗口循环;
            {
                //如果当前已经在定时器里面了，再次按下按钮1就会推出time_menu();
                // 但是如果这个时候计时器一已经在运作了就不起作用
                //time_begining ---->定时器是否在运行1 on / 2 off;
                //现在button_state是2，即在time_menu状态，当想要退出时将buttom_state置零即可
                buttom_time_on_state=buttom_getstate_4()+1;
                if(buttom_time_on_state==2&&!time_on_start)
                {
                    //当前状态：在计时器中，并且第一个按键按下，并且计时器没有运行计时
                    //在计数器中，按下第一个按键，返回menu_main;
                    //先把屏幕清空，再返回出去
                    LCD_clear();
                    time_on=0;
                    buttom_time_on_state=0;
                }
                else if(buttom_time_on_state==3)//定时器窗口按2，开始计时
                {
                    //第二个按键按下，当前状态：在计数器中，并且按下第二个按键---->开始计时
                    time_on_start=1;//更新状态---->计时器开始计时
                    time_0_case=1;
                    buttom_jishi=1;
                    while(buttom_jishi)                                                                //正在计时窗口循环
                    {
                        show_time();
                        buttom_jishi=buttom_getstate_4()+1;
                        if(buttom_jishi==2&&time_on_start==0)
                        {
                            //当没有计时的时候按1的话直接推出去，返回定时器窗口循环
                            buttom_time_on_state=0;
                            //将外部循环条件置为否
                            LCD_clear();
                            buttom_jishi=0;
                            time_on=0;
                        }
                        else if(buttom_jishi==3)
                        {
                            //计时器在计时，并且按下了按钮2，实现暂停功能;
                            //先判断是开始还是继续计时
                            if(time_on_start==1)
                            {
                                time_0_case=0;
                                time_on_start=0;
                            }
                            else
                            {
                                time_0_case=1;
                                time_on_start=1;
                            }

                        }
                        else if(buttom_jishi==4)
                        {
                            //计时器在计时的同时，按下了按钮3，实现：将计时器置零，并且暂停计时；
                            time_0_case=0;
                            time_clear_0();
                            time_on_start=0;

                        }
                        else if(buttom_jishi==5)
                        {
                            //计时器在计时的同时，按下了按钮4，实现:直接推出计时器，
                            // -->1.退出计时器之前应当关闭计时器，并将计时器置零
//                            time_0_case=0;// 将计时器暂停先，
//                            time_clear_0();
//                            time_on_start=0;
//                            buttom_state=0;
                            //将窗口循环条件置零，正常返回外层
                            time_0_case=0;
                            time_on_start=0;
                            time_on=0;
                            LCD_clear();
                            goto begin;
                        }
                    }

                }
                else if(buttom_time_on_state==4)
                {
                    //当前状态：在计数器中，并且按下第三个按键
                }
                else if(buttom_time_on_state==5)
                {
                    //当前状态：在计数器中，并且按下第四个按键
                    //更新状态
                    time_0_case=0;
                    time_on_start=0;
                    time_on=0;
                    LCD_clear();
                    goto begin;
                }

            }

        }


	}
}


void time_inter() interrupt 1
{
    TH0=64535/256;//高八位数据     晶振12mhz，一个周期为1us，最大65535us，
    TL0=64535%256;//低八位数据->64535 = 65535-1000; -> 1000us=1ms; 定时器单位为1ms
    ms++;
    if(ms==1000)
    {
        ms=0;
        s++;
        if(s==60)
        {
           s=0;
           m++;
           if(m==60)
           {
               m=0;
               h++;
           }
        }
    }
}

void menu_time()
{
    LCD_clear();
    LCD_ShowString(1,1,"timer:");
    LCD_ShowString(2,3,":");
    LCD_ShowString(2,6,":");
    LCD_ShowString(2,9,":");
    LCD_ShowNum(2,1,0,2);
    LCD_ShowNum(2,4,0,2);
    LCD_ShowNum(2,7,0,2);
    LCD_ShowNum(2,10,0,2);
}
void show_time()
{
    LCD_ShowNum(2,1,h,2);
    LCD_ShowNum(2,4,m,2);
    LCD_ShowNum(2,7,s,2);
    LCD_ShowNum(2,10,ms/100,2);
}
void menu_main()
{
//    LCD_clear();
    LCD_ShowString(1,1,"hello");
}
void time_clear_0()
{
    //作用：将计时器重置
    h=0;
    m=0;
    s=0;
    ms=0;
}