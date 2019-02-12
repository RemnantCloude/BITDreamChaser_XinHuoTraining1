#include <reg52.h>
#include <intrins.h>

/* �����̵�����ˮ��
	R1C1��2��3��4==>LED1234
	R2C1��2��3��4==>LED5678
   ����
	P1==>����
	P2==>��ˮ��
	��ʹ�õ�����
*/

//functions
void delayms(unsigned int);
int keyScan();


//VARIABLES	
int a,keyNum;
unsigned char num = 0;
unsigned char led;
unsigned char code lightUp[]={
	0xfe,0xfd,0xfb,0xf7,
	0xef,0xdf,0xbf,0x7f};  //һ����������С��״̬�����飬eg.��led=lightUp[0]���ȼ��ڡ�led=0xfe��

void main()
{
		
	
	led=0xff;	
	while(1) {
		//light up led
		P2 = led;
		P1 = 0x7f;   //row1 ���͵�ƽ
		keyNum = keyScan();  //keyNum��Ϊ����ɨ������Ӧ�İ������
		if(keyNum == 0){
			P1 = 0xbf;   //row2
			keyNum = keyScan();
//			if(keyNum==0){
//				P1=0xdf;   //row3
//				keyNum=keyScan();      //P1^6���˷���������һ����ȡ��ע�ͻ�ܳ�
				if(keyNum == 0){
					P1=0xef;   //row4
					keyNum=keyScan();
				}
			
		}
		keyNum=(keyNum-1)%8;   //��һ����Ŀ�����ð��������С�Ʊ�Ŷ�Ӧ
		if((keyNum<=7)&&(keyNum>=0)){
			led=lightUp[keyNum];	
			//delayms(100);
		}
		
	}
		
	
}
void delayms(unsigned int xms)
{
	unsigned int i,j;
	for(i=0;i<xms;i++)
	{
		for(j=0;j<110;j++);
	}
}


int keyScan(){
	int key=0;
	unsigned char temp;
	temp=P1&0x0f;
	if(temp!=0x0f){                  //temp==0x0f indicates all four columns are low level
		delayms(10);
		temp=P1&0x0f;
		if(temp!=0x0f){
			temp=P1;
			//LED=0;   //LIT LED
			switch(temp){
				case 0x77:          //search low level column in row1
					key=1;
					break;
				case 0x7b:
					key=2;
					break;
				case 0x7d:
					key=3;
					break;
				case 0x7e:
					key=4;
					break;
				case 0xb7:          //row2
					key=5;
					break;
				case 0xbb:
					key=6;
					break;
				case 0xbd:
					key=7;
					break;
				case 0xbe:
					key=8;
					break;
				case 0xd7:          //row3
					key=9;
					break;
				case 0xdb:
					key=10;
					break;
				case 0xdd:
					key=11;
					break;
				case 0xde:
					key=12;
					break;
				case 0xe7:          //row4
					key=13;
					break;
				case 0xeb:
					key=14;
					break;
				case 0xed:
					key=15;
					break;
				case 0xee:
					key=16;
					break;
			}
		}
		while(temp!=0x0f){          //wait till release
			temp=P1;
			temp=temp&0x0f;
		}
	}
	return key;
}