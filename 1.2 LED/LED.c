#include <reg52.h>

sbit led1 = P2^0;

void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()
{
	while (1)
	{
		led1 = 0;
		Delay1000ms();
		led1 = 1;
		Delay1000ms();
	}
	
}
