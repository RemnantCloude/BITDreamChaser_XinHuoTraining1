#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int
	
#define LED P2 

void delayms(uint xms){
    uint i,j;
    for(i = xms;i > 0;i--)
        for(j = 110;j > 0;j--);	
}

void main(){
	  uint i;
    LED =	0xfe;
	  delayms(500);
	  for(i = 0;i < 7;i++){
		    LED = LED << 1;
			  LED = LED + 1;
        delayms(500);			
		}
	  for(i = 0;i < 6;i++){
		    LED = LED >> 1;
        LED = LED + 0x80;
        delayms(500);			
		}
	  /*for(i = 0;i < 7;i++){
		    LED = _crol_(LED,1);
        delayms(500);			
		}
		for(i = 0;i < 6;i++){
		    LED = _cror_(LED,1);
        delayms(500);			
		}*/
}