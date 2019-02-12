#include <reg52.h>

sbit led1 = P2^0;

void timer0_ms(unsigned int n);	//��ʱ��0��������

void main()
{
	led1 = 1;
	while(1)
	{
		timer0_ms(1000);			//��ʱ1s
		led1 = ~led1;				//С��״̬ȡ��
	}
}

void timer0_ms(unsigned int n)	//��ʱ��0��������λΪms
{
	unsigned int count = 0;			//�����������count
	TMOD = 0x01;					//���ö�ʱ��0Ϊ����ģʽ1
	TH0 = 0xfc;						//���ö�ʱ��0�ĳ�ֵ
	TL0 = 0x18;
	TR0 = 1;						//��ʱ��0��ʼ����
	while(1)
	{
		if(TF0 == 1)				//�����⵽���
		{
			TF0 = 0;				//�����־��0
			TH0 = 0xfc;				//���趨ʱ��0�ĳ�ֵ
			TL0 = 0x18;
			count++;				//���������Լ�
			if(count == n)	break;	//���ﶨʱ�������˳�ѭ��
		}
	}
}