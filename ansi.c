#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routine
#include <string.h>
 
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
 
void gotoxy(int x, int y) { //Gå til givne koordinater
  printf("%c[%d;%dH",ESC,x,y);
}
 
void underline(char on) { //Understregning af ord
  if(on != 0) {
     printf("%c[04m",ESC);
  } else {
     printf("%c[24m",ESC);
  }
}
 
void reverse(char on) { //Bytter om på forgrund og bagrunds - farven
   if(on != 0) {
     printf("%c[07m",ESC);
   } else {
     printf("%c[27m",ESC);
   }
}
 
void blink(char on) { //Teksten kommer til at blinke, når on forskellig fra 0
  if(on != 0) {
     printf("%c[05m",ESC);
  } else {
     printf("%c[25m",ESC);
  }
}
 
void window(int x1, int y1, int x2, int y2, char* s, int style) {
  int i;
  int n = strlen(s);
  gotoxy(x1,y1);
  color(0,15);
  printf("%c%c",218,180);
  reverse(1);
  printf("%s",s);
  for(i = (y1 + n + 2); i < y2 - 1; i++) {
     printf(" ");
  }
  reverse(0);
  printf("%c%c\n",195,191);
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
