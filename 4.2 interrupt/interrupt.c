#include <reg52.h>

sbit led1 = P2^0;
sbit k3 = P3^2;

void delay_10ms()   //延时函数
{
	unsigned int i, j;
  	for(i = 10; i>0; i--)
		for(j = 110; j>0; j--);
}


void main()
{
	EA = 1;			//总中断使能
	EX0 = 1;		//外部中断0使能
	IT0 = 1;		//触发方式为下降沿触发
	while(1);
}

void OutInterrupt0() interrupt 0		//外部中断0服务函数
{
	delay_10ms();	//软件消抖
	if(k3 == 0)		//k3默认为高电平1，1 -> 0产生下降沿触发
	{
		led1 = ~led1;
	}
}