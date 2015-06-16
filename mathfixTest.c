#include <eZ8.h>
#include <sio.h>

#include "mathfix.h"
#include "ansi.h"

char flag = 0;

 #pragma interrupt
void timer0int() {
	flag++;
} 

void setTimer() {
	DI();
	// TEN = 0, TPOL = 0, PRES = 111, TMODE = 001 
	T0CTL = 0x039;
	// Den højeste nibbel sættes til 0
	T0H = 0x000;
	// Den laveste nibbel sættes til 1
	T0L = 0x001;
	//Dette er reload values, som er opdelt i høj og lav
	T0RH = 0x05;
	T0RL = 0xA0;
	
	// Interrupt prioriteten sættes
    IRQ0ENH |= 0x20; //High priority 
	IRQ0ENL |= 0x20;
	SET_VECTOR(TIMER0,timer0int);
	
	//Timeren enables
	T0CTL |= 0x80;

	//Interrput enables
	EI();
}

void main() {
	struct Ball b;
	long x,y;

	//drawBoxX4(1,1,21,21);
	b.x = (1<<14) * 5;
	b.y = (1<<14) * 5;
	b.angle = 64;
	printf("%ld,%ld\n",b.x,b.y);
	//reflectBallLSidefromAbove(&b);
	changeDirection(&(b.v),b.angle);
	printf("%d\n",b.angle);
	printFix(expand(b.v.y));
	updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	//reflectBallBottomfromLeft(&b);
	//printf("%ld",b.angle);	
    updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	updateBall(&b,0,0,10,10);
	printf("(%ld,%ld)\n",round(b.x),round(b.y));
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	//setTimer();
	/*rotate(&(b.v),85);
	printf("%ld,%ld\n",b.v.x,b.v.y);
	rotate(&(b.v),85);
	printf("%ld,%ld\n",b.v.x,b.v.y);
	rotate(&(b.v),85);
	printf("%ld,%ld\n",b.v.x,b.v.y);
	rotate(&(b.v),85);
	printf("%ld,%ld\n",b.v.x,b.v.y);
	rotate(&(b.v),85);
	printf("%ld,%ld\n",b.v.x,b.v.y);
	rotate(&(b.v),85);
	printf("%ld,%ld\n",b.v.x,b.v.y);*/
	/*printFix(expand(b.v.x));
	printf("\n");
	printFix(expand(b.v.y));
	n = expand(b.v.y);
	n = (n + 0x8000) >> 16;
	
	printf("\n%ld\n",n);
	printFix(n);*/
	/*while(1) {
		if(flag == 50) {
			updateBall(&b,1, 1, 21, 21);
			flag = 0;
		}
	}*/

}
