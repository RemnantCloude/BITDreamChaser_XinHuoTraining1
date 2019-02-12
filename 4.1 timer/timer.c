#include <reg52.h>

sbit led1 = P2^0;

void timer0_ms(unsigned int n);	//定时器0函数声明

void main()
{
	led1 = 1;
	while(1)
	{
		timer0_ms(1000);			//延时1s
		led1 = ~led1;				//小灯状态取反
	}
}

void timer0_ms(unsigned int n)	//定时器0函数，单位为ms
{
	unsigned int count = 0;			//定义计数变量count
	TMOD = 0x01;					//设置定时器0为工作模式1
	TH0 = 0xfc;						//设置定时器0的初值
	TL0 = 0x18;
	TR0 = 1;						//定时器0开始计数
	while(1)
	{
		if(TF0 == 1)				//如果检测到溢出
		{
			TF0 = 0;				//溢出标志置0
			TH0 = 0xfc;				//重设定时器0的初值
			TL0 = 0x18;
			count++;				//计数变量自加
			if(count == n)	break;	//到达定时条件，退出循环
		}
	}
}