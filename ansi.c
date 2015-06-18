#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routine
#include <string.h>		     // For strlen() function 

#include "ansi.h"
 
#define ESC 0x1B
 
void fgcolor(int foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  int type = 22;             // normal text
    if (foreground > 7) {
      type = 1;                // bold text
        foreground -= 8;
    }
  printf("%c[%d;%dm", ESC, type, foreground+30);
}
 
void bgcolor(int background) {
/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                The designers of HyperTerminal, however, preferred black text on white background, which is why
                the colors are initially like that, but when the background color is first changed there is no
                  way comming back.
   Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.
 
    Value      Color      
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}
 
void color(int foreground, int background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  int type = 22;             // normal text
    if (foreground > 7) {
      type = 1;                // bold text
        foreground -= 8;
    }
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}
 
void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
	printf("%c[m", ESC);  
}
 
void clrscr() { //clear screen
	printf("%c[2J",ESC);
}
  
void clreol() { //clear to end of line
	printf("%c[K",ESC);
}
 
void gotoxy(unsigned char x,unsigned char y) {
	printf("%c[%d;%dH",ESC,x,y);
}
 
void underline(char on) { //underlines characters
	  if(on != 0) {
	     printf("%c[04m",ESC);
	  } else {
	     printf("%c[24m",ESC);
	  }
}
 
void reverse(char on) { //Reverses foreground and background colors
	   if(on != 0) {
	     printf("%c[07m",ESC);
	   } else {
	     printf("%c[27m",ESC);
	   }
}
 
void blink(char on) { //Makes text blink
	  if(on != 0) {
	  	printf("%c[05m",ESC);
	  } else {
	  	printf("%c[25m",ESC);
	  }
}
 
void window(char x1, char y1, char x2, char y2, char* s, char style) {//Draws a window with (x1,y1) and (x2,y2) coordinates and writes the string s at the top
	char i;
	char n = strlen(s);
	gotoxy(x1,y1);
	color(0,15);																																				   
	printf("%c%c",218,180);
	reverse(1);
	printf("%s",s);
	for(i = (y1 + n + 2); i < y2 - 1; i++) {
	   	printf(" ");
	}
	reverse(0);
	printf("%c%c",195,191);
	for(i = 1; i < (x2-x1); i++) {
	   	gotoxy(x1 + i, y1);
	   	printf("%c",179);
	   	gotoxy(x1 + i, y2);
	   	printf("%c",179);
	}
	gotoxy(x2,y1);
	printf("%c",192);
	for(i = y1; i < y2-1; i++) {
	   	printf("%c",196);
	}
	printf("%c",217);
}

void drawBoxX4(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2) {
	unsigned char i;
	bgcolor(0);
	gotoxy(x1,y1);
	printf("%c",218);
	for(i = y1 + 1; i < y2; i++) {
		printf("%c",196);
	}
	printf("%c",191);
	for(i = 1; i <= x2; i++) {
		gotoxy(x1 + i, y1);
	   	printf("%c",179);
	   	gotoxy(x1 + i, y2);
	   	printf("%c",179);
	}
}

void drawBox(unsigned char x1, unsigned char y1,unsigned char x2,unsigned char y2,unsigned char color) {
	unsigned char i;
	if(color == 5) 
		fgcolor(4);
    else if(color == 4)
		fgcolor(2);
	else if(color == 3)
		fgcolor(10);
	else if(color == 2)
		fgcolor(11);
	else if(color == 1)
		fgcolor(1);
	gotoxy(x1,y1);
	printf("%c",218);
	for(i = y1 + 1; i < y2; i++) {
		printf("%c",196);
	}
	printf("%c",191);
	for(i = 1; i < (x2-x1); i++) {
		gotoxy(x1 + i, y1);
	   	printf("%c",179);
	   	gotoxy(x1 + i, y2);
		printf("%c",179);
	}
	gotoxy(x2,y1);
	printf("%c",192);
	for(i = y1; i < y2-1; i++) {
		printf("%c",196);
	}
	printf("%c",217);
	fgcolor(0);
}

void drawLine(unsigned char y1,unsigned char x1,unsigned char x2) {
	unsigned char i;
	bgcolor(4);
    gotoxy(y1,x1);
	for(i = x1; i <= x2; i++) {
		printf("%c",32);
	}
}

void clearLine(unsigned char y1,unsigned char x1, unsigned char x2) {
	unsigned char i;
	gotoxy(y1,x1);
	bgcolor(0);
	for(i = x1; i <= x2; i++) {
		printf(" ");
	}
}

void clearBox(unsigned char x1, unsigned char y1,unsigned char x2,unsigned char y2) {
	unsigned char i;
	gotoxy(y1,x1);
	for(i = y1; i <= y2; i++) {
		printf(" ");
	}
	gotoxy(x1,y1);
	for(i = 1; i < (x2-x1); i++) {
		gotoxy(x1 + i, y1);
	   	printf(" ");
	   	gotoxy(x1 + i, y2);
		printf(" ");
	}
	gotoxy(x2,y1);
	for(i = y1; i <= y2; i++) {
		printf(" ");
	}
}

void drawStartGameBox() {

unsigned char x1 = 15; unsigned char x2 = 20; 
unsigned char y1 = 117; unsigned char y2 = 134;
char color = 1;

   
int x = ((x2-x1)>> 1)+x1;
int y = ((y2-y1)>> 1)+y1-7; //Konstanten 7 så teksten står ordentligt 

gotoxy(x,y);
printf("1 to start game");
drawBox(x1,y1,x2,y2,color);

//printf("%d\n%d",x,y);
}


/*
StartMenu added der skal dog korrigeres lidt i skærmens størrelse. 
Derudover skal der arbejdes på noget ACSII som teskt i boksene
void drawSeeHiScoreBox() {
int moveX = 10; //Bruges til at forskydde denne boks fra den forrige. 
unsigned char x1 = 15+moveX; unsigned char x2 = 20+moveX;
unsigned char y1 = 117; unsigned char y2 = 134;
char color = 1;
int foreground = 7; //int background = 2;

int x = ((x2-x1)>> 1)+x1;
int y = ((y2-y1)>> 1)+y1-7;
printf("%d\n%d",x,y);

gotoxy(x,y);
fgcolor(foreground);
printf("2 to see Hiscore");
drawBox(x1,y1,x2,y2,color);

}

void drawSeePowerUps() {
int moveX = 20; //Bruges til at forskydde denne boks fra den forrige. 
unsigned char x1 = 15+moveX; unsigned char x2 = 20+moveX;
unsigned char y1 = 117; unsigned char y2 = 134;
char color = 1;
int foreground = 7; //int background = 2;

int x = ((x2-x1)>> 1)+x1;
int y = ((y2-y1)>> 1)+y1-7;
printf("%d\n%d",x,y);

gotoxy(x,y);
fgcolor(foreground);
printf("3 to see Hiscore");
drawBox(x1,y1,x2,y2,color);
}



void drawMenuWindow() {
    unsigned char x1 = 3; unsigned char x2 = 50;
    unsigned char y1 = 8; unsigned char y2 = 254;
	char color = 2;
	drawBox(x1,y1,x2,y2,color);
}
*/
