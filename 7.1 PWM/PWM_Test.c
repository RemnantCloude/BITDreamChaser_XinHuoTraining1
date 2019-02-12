#include <reg52.h>
#include <intrins.h>

#define uint unsigned int 

sbit LED = P2^0;
static uint counter = 0;
static uint threshold;
static uint round = 30;

void Timer0Init(void) 	//100΢��@11.0592MHz
{
	TMOD = 0x01;		//���ö�ʱ��ģʽ
	TL0 = (65536-10)%256;		//���ö�ʱ��ֵ
	TH0 = (65536-10)/256;		//���ö�ʱ��ֵ
	EA = 1;
	TR0 = 1;
	ET0 = 1;
}

void Delay10ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 18;
	j = 235;
	do
	{
		while (--j);
	} while (--i);
}


void TogglePin() interrupt 1
{
	TL0 = (65536-10)%256;		//���ö�ʱ��ֵ
	TH0 = (65536-10)/256;		//���ö�ʱ��ֵ
	counter++;
	if(counter >= threshold)
	{
		LED = 1;
	}
	
	if(counter >= round)
	{
		LED = 0;
		counter = 0;
	}
}

int main()
{
	Timer0Init();
	LED = 0;
	while(1)
	{
//		threshold = 15;
		for(threshold = 0;threshold < 30;threshold++)
		Delay10ms();
		for(threshold = 30;threshold > 0;threshold--)
		Delay10ms();
	}
}