#include <eZ8.h>
#include <sio.h>

#include "mathfix.h"
#include "ansi.h"
#include "GameSettings.h"
#include "inputfix.h"

#define ESC 0x1B



void main() {
	char boxarray1[14][5] = {
							{1,2,3,4,5},
							{1,2,3,4,5},
							{1,2,3,4,5},
							{1,2,3,4,5},
							{1,2,3,4,5},
							{1,2,3,4,5},
							{1,2,3,4,5},
							{1,2,3,4,5},
							{1,2,3,4,5},
							{1,2,3,4,5},
							{1,2,3,4,5},
							{1,2,3,4,5},	
							{1,2,3,4,5},
							{1,2,3,4,5}
							};

	char flag1;
	int maximize;
	struct striker_t striker;
	unsigned char wallx1 = 1;
	unsigned char wallx2 = 252;
	unsigned char left = 119;
	unsigned char right = 134;
	unsigned char yposs = 57;
	struct Ball b;
	b.x = (1<<14) * 27;
	b.y = (1<<14) * 127;
	b.angle = 128;
	changeDirection(&(b.v),b.angle);

	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	printf("%c[?25l", ESC);
	clrscr();
	setTimer();
	fgcolor(15);
	drawBoxX4(1,1,59,252);
	make_boxes(boxarray1);
	drawLine(yposs, left, right);
	initStriker(&striker, left, right, yposs);
	while(1) {
		flag1 = returnflag();
		maximize = returnflag();
		if(flag1 == 10) {
			updateBall(&b,&striker,&boxarray1[0][0],1, 1, 252, 58);
			flag1 = 0;
			update_striker(&striker, wallx1 , wallx2);
		}
	}
	
}