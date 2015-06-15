#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routine
 
void fgcolor(int foreground);
void bgcolor(int background);
 
void color(int foreground, int background);
 
void resetbgcolor();
void clrscr();
void gotoxy(char x, char y);
void underline(char on);
void reverse(char on);
void blink(char on);
void window(char x1, char y1, char x2, char y2, char* s, char style);
void drawBoxX4(char x1,char y1,char x2, char y2);
void drawBox(char x1, char y1, char x2, char y2, char color);
void drawLine(char y1, char x1, char x2);
void clearLine(char y1, char x1, char x2);
void clearBox(char x1, char y1, char x2, char y2);
void drawBall(char ball.x1,char ball.y1,char ball.x, char ball.y)
