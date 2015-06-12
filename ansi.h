#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routine
 
#define ESC 0x1B
 
void fgcolor(int foreground);
void bgcolor(int background);
 
void color(int foreground, int background);
 
void resetbgcolor();
void clrscr();
void gotoxy(int x, int y);
void underline(char on);
void reverse(char on);
void blink(char on);
void window(int x1, int y1, int x2, int y2, char* s, int style);
void drawsBoxX4(char x1,char y1,char x2, char y2);
void drawBox(char x1, char y1, char x2, char y2, char color);
void drawLine(char x1, char y1, char y2);
