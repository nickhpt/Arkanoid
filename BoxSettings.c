#include <eZ8.h>
#include <sio.h>
#include "ansi.h"
#include "mathfix.h"
#include "GameSettings.h"


void setpwr(struct box_t *box_p) {
	box_p -> pwrup = 0;

} 

void setBox(struct box_t *box_p,unsigned char xpos1,unsigned char ypos1,unsigned char xpos2,unsigned char ypos2,unsigned char hp1,unsigned char point) {
		box_p -> x1 = xpos1;
		box_p -> y1 = ypos1; 
		box_p -> x2 = xpos2;
		box_p -> y2 = ypos2; 
		box_p -> hp = hp1;
		setpwr(box_p);
		box_p -> boxpoint = point;

		
} 

void changehp(struct box_t *box_p,unsigned char change) {
	box_p->hp += change;
	
}
