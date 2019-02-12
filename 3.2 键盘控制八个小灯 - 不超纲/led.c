#include <reg52.h>
#include <intrins.h>

/* �����̵�����ˮ��
	R1C1��2��3��4==>LED1234
	R2C1��2��3��4==>LED5678
   
	P1==>����
	P2==>��ˮ��
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
		P2=led;							//����P2��������ˮ��
		flag=0;							//��¼��ʱ�Ƿ��м�����	
		P1=0x7f;  						 //row1 �͵͵�ƽ
		temp=P1&0x0f;    				  //temp�������Ǳ���P1����λ��ֵ
		if(temp!=0x0f)					//���temp==0x0f ˵����һ��û�м�������
		{                  
			delayms(10);                 //��ʱȥ��
			temp=P1&0x0f;				 
			if(temp!=0x0f)   //ȷ����һ���м�������
			{				
				temp=P1;
				switch(temp)
				{
					case 0x77:          //����һ���ĸ����Ƿ��а���������
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
				while(temp!=0x0f){          //�����ɿ�ǰͣ���ڴ�ѭ��
					temp=P1;
					temp=temp&0x0f;
				}
			}
		}
		
		if(!flag)          //ȷ��Ŀǰû�ж�ȡ��һ�еİ���ֵ
		{
			P1 = 0xbf;   //row2 �͵͵�ƽ
			temp = P1&0x0f;    				  //temp�������Ǳ���P1����λ��ֵ
			if(temp != 0x0f)					//���temp==0x0f ˵����һ��û�м�������
			{                  
				delayms(10);                 //��ʱȥ��
				temp = P1&0x0f;				 
				if(temp != 0x0f)   //ȷ����һ���м�������
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
					while(temp != 0x0f){          //�����ɿ�ǰͣ���ڴ�ѭ��
						temp = P1;
						temp = temp&0x0f;
					}
				}
			}
		}
		
		//�˴�ʡ��ɨ������С������е�ʵ�ַ�������ҵΪ�ο���һ�еڶ��е�ɨ��ʵ�֣�������ɵ����е����еļ��(�������п��ܻᴥ����������
		//ѧ��������ͬѧ˼��һ����û�и�����ʵ�ַ�ʽ
		//Ҫ���ǵ������еİ����ܹ�ʵ�ֺ͵�һ���в�ͬ�Ĺ���
		
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


