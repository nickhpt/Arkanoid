#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routine
#include <string.h>		        // For strlen() function
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
 
void gotoxy(char x, char y) { //moves cursor to coordinates
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
	for(i = 1; i < x2; i++) {
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

void drawsBoxX4(char x1,char y1,char x2, char y2) {
	char i;
	gotoxy(x1,y1);
	printf("%c",218);
	for(i = y1 + 1; i < y2; i++) {
		printf("%c",196);
	}
	printf("%c",191);
	for(i = 1; i =< x2; i++) {
		gotoxy(x1 + i, y1);
	   	printf("%c",179);
	   	gotoxy(x1 + i, y2);
	   	printf("%c",179);
	}
}

void drawBox(char x1, char y1, char x2, char y2, char color) {
	char i;
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
	for(i = y1 + 1; i < length; i++) {
		printf("%c",196);
	}
		printf("%c",191);
	for(i = 1; i < x2; i++) {
		gotoxy(x1 + i, y1);
	   	printf("%c",179);
	   	gotoxy(x1 + i, y2);
		printf("%c",179);
	}
	gotoxy(x2,y1);
	printf("%c",192);
	for(i = y1; i < y2; i++) {
		printf("%c",196);
	}
	printf("%c",217);
}
