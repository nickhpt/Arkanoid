#include <eZ8.h>
#include <sio.h>
#include "ansi.h"
#include "mathfix.h"
#include "GameSettings.h"


void setpwr(struct box_t *box_p) {
	box_p -> pwrup = 0;

} 

void setBox(struct box_t *box_p, char xpos1, char ypos1,  char xpos2, char ypos2, char hp1, char point) {
		box_p -> x1 = xpos1;
		box_p -> y1 = ypos1; 
		box_p -> x2 = xpos2;
		box_p -> y2 = ypos2; 
		box_p -> hp = hp1;
		setpwr(box_p);
		box_p -> boxpoint = point;

		
} 

void changehp(struct box_t *box_p, char change) {
	box_p->hp += change;
	
}

void changeBox(struct *Box Box){
	gotoxy(Box.x,Box.y);
	if(box.hp == 0){
		fgcolor(x);
	}
	if(box.hp == 1){
		fgcolor(x);
	}
	if(box.hp==2){
		fgcolor(x)
	}
	}
	}
	}
}
