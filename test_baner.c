#include <eZ8.h>
#include <sio.h>
#include "ansi.h"
#include "mathfix.h"
#include "charset.h"
#include "GameSettings.h"
#include "inputfix.h"




void main() {
	#define ESC 0x1B
	struct striker_t striker;

	struct box_t box1;

	unsigned char wallx1 = 1;
	unsigned char wallx2 = 252;
	unsigned char left = 30;
	unsigned char right = 44;
	unsigned char yposs = 59;
 
	char boxarray1[14][5] = {
							{2,2,2,2,2},
							{0,0,2,0,0},
							{2,2,2,2,2},
							{0,0,0,0,0},
							{2,2,2,2,2},
							{2,0,2,0,2},
							{2,0,0,0,2},
							{0,0,0,0,0},
							{0,0,0,2,2},
							{2,0,0,0,2},
							{2,2,2,2,2},
							{0,0,0,0,0},	
							{0,0,0,0,0},
							{0,0,0,0,0}
							};
	setTimer();
	
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	
	printf("%c[?25l", ESC);
	clrscr();

	drawBoxX4(1,wallx1,yposs, wallx2); 
//	drawLine(yposs, left, right);
//	initStriker(&striker, left, right, yposs);
	make_boxes(boxarray1);

while(1);
 }
