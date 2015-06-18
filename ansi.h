#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routine
 
void fgcolor(int foreground);
void bgcolor(int background);
 
void color(int foreground, int background);
 
void resetbgcolor();
void clrscr();
void gotoxy(unsigned char x,unsigned char y);
void underline(char on);
void reverse(char on);
void blink(char on);
void window(char x1, char y1, char x2, char y2, char* s, char style);
void drawBoxX4(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2);
void drawBox(unsigned char x1, unsigned char y1,unsigned char x2,unsigned char y2,unsigned char color);
void drawLine(unsigned char y1,unsigned char x1,unsigned char x2);
void clearLine(unsigned char y1,unsigned char x1,unsigned char x2);
void clearBox(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2);
void drawBox2(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, char color);
void clearBox2(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2);
