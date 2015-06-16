#include <eZ8.h>
#include <sio.h>
#include "ansi.h"
#include "mathfix.h"
#include "charset.h"
#include "GameSettings.h"
#include "inputfix.h"




void main() {

	struct striker_t striker;

	char wallx1 = 1;
	char wallx2 = 127;
	char left = 30;
	char right = 34;
	char yposs = 78;

	setTimer();
	
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	
	clrscr();	
	drawBoxX4(1,wallx1,yposs, wallx2); 
	drawLine(yposs, left, right);
	initStriker(&striker, left, right, yposs);
	
//	while(1);

	while(1){
	update_striker(&striker, wallx1 , wallx2);
	};	
}


