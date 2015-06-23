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
   	char level11[14][5];
	char level22[14][5];
	char level33[14][5];
	unsigned char i,j;
	int points1 = 1400, points2 = 2800, points3 = 4650;
	//int points1 = 200, points2 = 200, points3 = 200;
	char lives, progression = 0;
	char flag1;
	char check;
	unsigned char oldx = 0;
	
	struct striker_t striker;
	struct Ball b;
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
		if ( check & 0x02) {
			bgcolor(0);
			clrscr();
			drawBox(15,110,30,157,7);
			gotoxy(22,112);
			printf("This is our version of the arkonoid game");
			gotoxy(23,112);
			printf("To move the striker left, press the PD3 button");
			gotoxy(24,112);
			printf("To move the striker right, press the PF7 button");
			gotoxy(25,112);
			printf("To leave this menu, press the PD3 button");
			while(1) {
				check = readKey();
				if(check & 0x04) {
					bgcolor(0);
					clrscr();
					drawStartGameBox();
					drawSeeHiScoreBox();
					drawSeePowerUps();
					drawMenuWindow();
					break;
				}
			}
		} 
		if ( check & 0x01) {
			for(i = 0; i < 14; i++) {
				for(j = 0; j < 5; j++) {
					level11[i][j] = level1[i][j];
				}
			}
			clrscr();
			fgcolor(15);
			drawBoxX4(wallx1,1,59,wallx2);
			make_boxes(level11);
			initStriker(&striker, left, right, yposs);
			gotoxy(3,241);
			printf("%d",points1);
			while(1) {
				LEDUpdate(striker.lives);
				if(returnflag()) {
					update_striker(&striker, wallx1 , wallx2);
					updateBall(&b,&striker,&level11[0][0],wallx1, 1, wallx2, 59, oldx);
					set_flag0();
				}
				oldx = b.x;
				checkFailure(&b,&striker,left,right,yposs);
				if( !striker.lives ) {
					bgcolor(0);
					clrscr();
					drawStartGameBox();
					drawSeeHiScoreBox();
					drawSeePowerUps();
					drawMenuWindow();
					striker.lives = 4;
					break;	
				}
				if (striker.points == points1) {
					progression++;
					break;
				}
			}
		}
		if (progression & 0x01) {
			for(i = 0; i < 14; i++) {
				for(j = 0; j < 5; j++) {
					level22[i][j] = level2[i][j];
				}
			}
			clrscr();
			fgcolor(15);
			drawBoxX4(wallx1,1,59,wallx2);
			make_boxes(level22);
			initBall(&b);
			setStriker1(&striker,left,right,yposs);
			while(1) {
				LEDUpdate(striker.lives);
				if(returnflag()) {
					update_striker(&striker, wallx1 , wallx2);
					updateBall(&b,&striker,&level22[0][0],wallx1, 1, wallx2, 59, oldx);
					set_flag0();
				}
				oldx = b.x;
				checkFailure(&b,&striker,left,right,yposs);
				if( !striker.lives ) {
					bgcolor(0);
					clrscr();
					drawStartGameBox();
					drawSeeHiScoreBox();
					drawSeePowerUps();
					drawMenuWindow();
					striker.lives = 4;
					progression = 0;
					break;	
				}
				if ((striker.points - points1) == points2) {
					progression++;
					break;
				}
			}
		}
		if (progression & 0x02) {
			for(i = 0; i < 14; i++) {
				for(j = 0; j < 5; j++) {
					level33[i][j] = level3[i][j];
				}
			}
			clrscr();
			fgcolor(15);
			drawBoxX4(wallx1,1,59,wallx2);
			make_boxes(level33);
			initBall(&b);
			setStriker1(&striker,left,right,yposs);
			while(1) {
				LEDUpdate(striker.lives);
				if(returnflag()) {
					update_striker(&striker, wallx1 , wallx2);
					updateBall(&b,&striker,&level33[0][0],wallx1, 1, wallx2, 59, oldx);
					set_flag0();
				}
				oldx = b.x;
				checkFailure(&b,&striker,left,right,yposs);
				if( !striker.lives ) {
					bgcolor(0);
					clrscr();
					drawStartGameBox();
					drawSeeHiScoreBox();
					drawSeePowerUps();
					drawMenuWindow();
					striker.lives = 4;
					progression = 0;
					break;	
				}
				if ((striker.points - points1 - points2) == points3) {
					progression *= 2;
					break;
				}
			}
		}
		if (progression & 0x04) {
			bgcolor(0);
			clrscr();
			drawBox(20,109,26,145,7);
			gotoxy(22,112);
			printf("Congratulation!");
			gotoxy(23,112);
			printf("You've won the game");
			gotoxy(24,112);
			printf("Press PD3 to leave to startmenu");
			while (1) {
				check = readKey();
				if (check & 0x04) {
					bgcolor(0);
					clrscr();
					drawStartGameBox();
					drawSeeHiScoreBox();
					drawSeePowerUps();
					drawMenuWindow();
					striker.lives = 4;
					progression = 0;
					break;	
				}
			}
		}
	}
}