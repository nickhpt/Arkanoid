#include <eZ8.h>
#include <sio.h>

#include "mathfix.h"
#include "ansi.h"
#include "GameSettings.h"
#include "inputfix.h"

#define ESC 0x1B

#define wallx1 0x01
#define wallx2 0xF0
#define left 0x77
#define right 0x86
#define yposs 0x39



void main() {
	char level1[14][5] = {
							{5,4,3,2,1},
							{5,4,3,2,1},
							{5,4,3,2,1},
							{5,4,3,2,1},
							{5,4,3,2,1},
							{5,4,3,2,1},
							{5,4,3,2,1},
							{5,4,3,2,1},
							{5,4,3,2,1},
							{5,4,3,2,1},
							{5,4,3,2,1},
							{5,4,3,2,1},	
							{5,4,3,2,1},
							{5,4,3,2,1}
							};
   	
	char lives;
	char flag1;
	char check;
	struct striker_t striker;
	unsigned char oldx = 0;
	struct Ball b;
	striker.lives = 4;
	initBall(&b);

	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	printf("%c[?25l", ESC);
	clrscr();
	setTimer();
	LEDinit();
	drawStartGameBox();
	drawSeeHiScoreBox();
	drawSeePowerUps();
	drawMenuWindow();
	while(1) {
		check = readKey();
		if ( check & 0x01) {
			clrscr();
			fgcolor(15);
			drawBoxX4(wallx1,1,59,wallx2);
			make_boxes(level1);
			initStriker(&striker, left, right, yposs);
			while(striker.lives) {
				lives = striker.lives;
				LEDUpdate(lives);
				flag1 = returnflag();
				if(returnflag()) {
					update_striker(&striker, wallx1 , wallx2);
					updateBall(&b,&striker,&level1[0][0],wallx1, 1, wallx2, 59, b.x);
					set_flag0();
				}
				if(round(b.x) > 57) {
					striker.lives--;
					if(striker.lives == 0) {
						PEOUT = 0x1F;
						PGOUT = 0x7F;
						PEOUT |= 0x80;
						PEOUT &= ~0x80;
					}
					else if(striker.lives == 1) {
						PEOUT = 0x1F;
						PGOUT = 0x7F;
						PGOUT |= 0x80;
						PGOUT &= ~0x80;
					}
					else if(striker.lives == 2) {
						PEOUT = 0x1F;
						PGOUT = 0x7F;
						PEOUT |= 0x20;
						PEOUT &= ~0x20;
					}
					else if(striker.lives == 3) {
						PEOUT = 0x1F;
						PGOUT = 0x7F;
						PEOUT |= 0x40;
						PEOUT &= ~0x40;
					}
					clearLine(striker.ypos,striker.lftend,striker.rghtend);
					gotoxy(b.x,b.y);
					printf(" ");
					setStriker1(&striker,left,right,yposs);
					initBall(&b);
				}
				oldx = round(b.x);
				if( !striker.lives ) {
					bgcolor(0);
					clrscr();
					drawStartGameBox();
					drawSeeHiScoreBox();
					drawSeePowerUps();
					drawMenuWindow();
					
				}
			}
		}
	}
	
}