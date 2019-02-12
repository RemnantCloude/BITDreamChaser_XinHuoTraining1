#include <reg52.h>

/* 检测键盘点亮流水灯
	R1C1、2、3、4==>LED1234
	R2C1、2、3、4==>LED5678
   连线
	P1==>键盘
	P2==>流水灯
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
	r1 = 0;        //第1行输出低电平，234行高电平，234行按键无效
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
			} //第一个按键按下，led1&5亮
		}
		if(c2==0){
			delayms(10);
			if(c2==0){
				led=0xdd;
				delayms(50);

			} //第二个按键按下，led2&4亮
		}
		if(c3 == 0)
		{
			delayms(10);
			if(c3 == 0)
			{
				led = 0xbb;
				delayms(50);			
			} //第三个按键按下，led3&7亮
		}
		if(c4 == 0)
		{
			delayms(10);	
			if(c4 == 0)
			{
				led = 0x77;
				delayms(50);
			} //第四个按键按下，led4&8亮
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


