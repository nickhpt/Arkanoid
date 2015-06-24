#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routine
#include <string.h>		     // For strlen() function 

#include "ansi.h"

 
#define ESC 0x1B
 
void fgcolor(int foreground) {

  int type = 22;             // normal text
    if (foreground > 7) {
      type = 1;                // bold text
        foreground -= 8;
    }
  printf("%c[%d;%dm", ESC, type, foreground+30);
}
 
void bgcolor(int background) {

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
 
//Clears screen with last background color
void clrscr() { 
	printf("%c[2J",ESC);
}
  
//Clears to the end of the line
void clreol() { 
	printf("%c[K",ESC);
}
 
// Goes to (x,y)-coordinates
void gotoxy(unsigned char x,unsigned char y) {
	printf("%c[%d;%dH",ESC,x,y);
}
 
//Underlines characters
void underline(char on) { 
	  if(on) {
	     printf("%c[04m",ESC);
	  } else {
	     printf("%c[24m",ESC);
	  }
}
 
//Reverses the background and foreground colors
void reverse(char on) { 
	   if(on) {
	     printf("%c[07m",ESC);
	   } else {
	     printf("%c[27m",ESC);
	   }
}
 
//Makes the text blink
void blink(char on) {
	  if(on) {
	  	printf("%c[05m",ESC);
	  } else {
	  	printf("%c[25m",ESC);
	  }
}
 
//Draws a window with (x1,y1) and (x2,y2) coordinates and writes the string s at the top
void window(char x1, char y1, char x2, char y2, char* s, char style) {
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

//Draws a box with the bottom line missing
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

//Draws a simple box with upper left corner in (x1,y1) and lower right corner (x2,y2)
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
}

//Draws a simple line at the depth y1, from x1 to x2
void drawLine(unsigned char y1,unsigned char x1,unsigned char x2) {
	unsigned char i;
	bgcolor(4);
    gotoxy(y1,x1);
	for(i = x1; i <= x2; i++) {
		printf("%c",32);
	}
}

//Clears line at depth y1 from x1 to x2
void clearLine(unsigned char y1,unsigned char x1, unsigned char x2) {
	unsigned char i;
	gotoxy(y1,x1);
	bgcolor(0);
	for(i = x1; i <= x2; i++) {
		printf(" ");
	}
}

//Removes a box with upper left corner in (x1,y1) and lower right corner in (x1,y2)
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

//Draws a compact box with upper left corner in (x1,y1) and lower right corner (x2,y2)
void drawBox2(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, char color) {
	unsigned char i, j;
	bgcolor(color);
	for(i = x1; i < x2; i++) {
		gotoxy(i,y1);
		for(j = y1; j < y2; j++) {
			printf("%c",32);
		}
	}
}

//Clears a compact box with upper left corner in (x1,y1) and lower right corner (x2,y2)
void clearBox2(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2) {
	unsigned char i, j;
	gotoxy(x1,y1);
	bgcolor(0);
	for(i = x1; i < x2; i++) {
		gotoxy(x1+i,y1);
		for(j = y1; j < y2; j++) {
			printf(" ");
		}
	}
}

//Draws one of the startmenu windows
void drawStartGameBox() {
	unsigned char x1 = 15; unsigned char x2 = 20; 
	unsigned char y1 = 117; unsigned char y2 = 138;
	char color = 1;
	   
	int x = ((x2-x1)>> 1)+x1;
	int y = ((y2-y1)>> 1)+y1-7; //Konstanten 7 så teksten står ordentligt 
	
	gotoxy(x,y);
	printf("PF7 to start game");
	drawBox(x1,y1,x2,y2,color);
	
	}
	
//Draws the second of the startmenu windows
void drawSeeHelp() {
	int moveX = 10; //Bruges til at forskydde denne boks fra den forrige. 
	unsigned char x1 = 15+moveX; unsigned char x2 = 20+moveX;
	unsigned char y1 = 117; unsigned char y2 = 138;
	char color = 1;
	int foreground = 7; 
	
	int x = ((x2-x1)>> 1)+x1;
	int y = ((y2-y1)>> 1)+y1-7;
	
	gotoxy(x,y);
	fgcolor(foreground);
	printf("PF6 to see help");
	drawBox(x1,y1,x2,y2,color);
	
}
	
	
	
//Draws the frame of the startmenu
void drawMenuWindow() {
    unsigned char x1 = 3; unsigned char x2 = 50;
    unsigned char y1 = 8; unsigned char y2 = 254;
	char color = 2;
	drawBox(x1,y1,x2,y2,color);
}

