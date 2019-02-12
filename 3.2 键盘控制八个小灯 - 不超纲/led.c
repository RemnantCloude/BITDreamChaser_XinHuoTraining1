#include <reg52.h>
#include <intrins.h>

/* 检测键盘点亮流水灯
	R1C1、2、3、4==>LED1234
	R2C1、2、3、4==>LED5678
   
	P1==>键盘
	P2==>流水灯
*/

//functions
void delayms(unsigned int);
int keyScan();


//VARIABLES	
unsigned char led;
unsigned char temp;
int flag;
void main()
{			
	led = 0xff;	
	while(1) 
	{
		P2=led;							//操作P2，操作流水灯
		flag=0;							//记录此时是否有键按下	
		P1=0x7f;  						 //row1 送低电平
		temp=P1&0x0f;    				  //temp的作用是保存P1后四位的值
		if(temp!=0x0f)					//如果temp==0x0f 说明这一行没有键被按下
		{                  
			delayms(10);                 //延时去抖
			temp=P1&0x0f;				 
			if(temp!=0x0f)   //确认这一行有键被按下
			{				
				temp=P1;
				switch(temp)
				{
					case 0x77:          //检测第一行四个键是否有按键被按下
					led = 0xfe;
					flag = 1;
					break;
				    case 0x7b:
					led = 0xfd;
					flag =1;
					break;
				    case 0x7d:
					led = 0xfb;
					flag = 1;
					break;
					case 0x7e:
					led = 0xf7;
					flag = 1;
					break;
				}
				while(temp!=0x0f){          //按键松开前停留在此循环
					temp=P1;
					temp=temp&0x0f;
				}
			}
		}
		
		if(!flag)          //确保目前没有读取第一行的按键值
		{
			P1 = 0xbf;   //row2 送低电平
			temp = P1&0x0f;    				  //temp的作用是保存P1后四位的值
			if(temp != 0x0f)					//如果temp==0x0f 说明这一行没有键被按下
			{                  
				delayms(10);                 //延时去抖
				temp = P1&0x0f;				 
				if(temp != 0x0f)   //确认这一行有键被按下
				{				
					temp = P1;
					switch(temp)
					{
					case 0xb7:          //row2
						led = 0xef;
						break;
					case 0xbb:
						led = 0xdf;
						break;
					case 0xbd:
						led = 0xbf;
						break;
					case 0xbe:
						led = 0x7f;
						break;
					}
					while(temp != 0x0f){          //按键松开前停留在此循环
						temp = P1;
						temp = temp&0x0f;
					}
				}
			}
		}
		
		//此处省略扫描第三行、第四行的实现方法，作业为参考第一行第二行的扫描实现，自行完成第三行第四行的检测(检测第三行可能会触发蜂鸣器）
		//学有余力的同学思考一下有没有更简便的实现方式
		//要求是第三四行的按键能够实现和第一二行不同的功能
		
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


