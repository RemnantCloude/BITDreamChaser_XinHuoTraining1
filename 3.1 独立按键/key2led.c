#include <reg52.h>

sbit led1 = P2^0;
sbit key = P3^1;
void delayms(int xms)
{
	int i,j;
	for(i=xms;i>0;i--)
	{
		for(j=0;j<110;j++);
	}
}
	

void main()
{
	while(1)
	{
		if(key==0)
		{
			delayms(10);
			if(key==0)
			{
				led1 = ~led1;
				while(key==0);
			}
		}
	}
		
}