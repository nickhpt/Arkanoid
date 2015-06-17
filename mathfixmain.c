#include <eZ8.h>
#include <sio.h>

#include "mathfix.h"
#include "ansi.h"
#include "GameSettings.h"
#include "inputfix.h"

#define ESC 0x1B



void main() {
	char flag1;
	struct striker_t striker;
	unsigned char wallx1 = 1;
	unsigned char wallx2 = 252;
	unsigned char left = 30;
	unsigned char right = 34;
	unsigned char yposs = 59;
	struct Ball b;
	b.x = (1<<14) * 6;
	b.y = (1<<14) * 4;
	b.angle = 50;
	changeDirection(&(b.v),b.angle);

	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	printf("%c[?25l", ESC);
	clrscr();
	setTimer();
	drawBoxX4(1,1,58,252);
	drawLine(yposs, left, right);
	initStriker(&striker, left, right, yposs);
	while(1) {
		flag1 = returnflag();
		if(flag1 == 1) {
			updateBall(&b,1, 1, 252, 58);
			update_striker(&striker, wallx1 , wallx2);
			flag1 = 0;
		}
	}

}
