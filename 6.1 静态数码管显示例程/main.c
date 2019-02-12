

#include "reg52.h"			 

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

u8 code smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//显示0~F的值


void main()
{	
	LSA=0;
	LSB=0;
	LSC=0;	//控制38译码器的Y0输出低电平
	P0=smgduan[0];
	while(1);
}
