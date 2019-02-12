#include <reg52.h>

/* �����̵�����ˮ��
	R1C1��2��3��4==>LED1234
	R2C1��2��3��4==>LED5678
   ����
	P1==>����
	P2==>��ˮ��
*/

//functions
void delayms(unsigned int);

//matrix keyboard
sbit r1 = P1^7;     
sbit r2 = P1^6;
sbit r3 = P1^5;
sbit r4 = P1^4;
sbit c1 = P1^3;
sbit c2 = P1^2;
sbit c3 = P1^1;
sbit c4 = P1^0;

//VARIABLES	
unsigned char led;

void main(){
	r1 = 0;        //��1������͵�ƽ��234�иߵ�ƽ��234�а�����Ч
	r2 = 1;
	r3 = 1;
	r4 = 1;     
	led=0xff;
	while(1){
		P2 = led;
		if(c1 == 0){
			delayms(10);
			if(c1 == 0){
				led = 0xee;
				delayms(50);
			} //��һ���������£�led1&5��
		}
		if(c2==0){
			delayms(10);
			if(c2==0){
				led=0xdd;
				delayms(50);

			} //�ڶ����������£�led2&4��
		}
		if(c3 == 0)
		{
			delayms(10);
			if(c3 == 0)
			{
				led = 0xbb;
				delayms(50);			
			} //�������������£�led3&7��
		}
		if(c4 == 0)
		{
			delayms(10);	
			if(c4 == 0)
			{
				led = 0x77;
				delayms(50);
			} //���ĸ��������£�led4&8��
		}
	}
}

void delayms(unsigned int xms)
{
	unsigned int i,j;
	for(i = 0;i < xms;i++)
	{
		for(j = 0;j < 110;j++);
	}
}


