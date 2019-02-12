#include <reg52.h>

sbit led1 = P2^0;
sbit k3 = P3^2;

void delay_10ms()   //��ʱ����
{
	unsigned int i, j;
  	for(i = 10; i>0; i--)
		for(j = 110; j>0; j--);
}


void main()
{
	EA = 1;			//���ж�ʹ��
	EX0 = 1;		//�ⲿ�ж�0ʹ��
	IT0 = 1;		//������ʽΪ�½��ش���
	while(1);
}

void OutInterrupt0() interrupt 0		//�ⲿ�ж�0������
{
	delay_10ms();	//�������
	if(k3 == 0)		//k3Ĭ��Ϊ�ߵ�ƽ1��1 -> 0�����½��ش���
	{
		led1 = ~led1;
	}
}