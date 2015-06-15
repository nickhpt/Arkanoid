#include <eZ8.h>
#include <sio.h>
#include "ansi.h"
#include "mathfix.h"
#include "GameSettings.h"
#include "inputfix.h"


void setStriker(struct striker_t *striker_p, char xpos1, char xpos2, char ypos1) {
	striker_p -> ypos = ypos1;
	striker_p -> points = 0;
	striker_p -> lives = 3;
	striker_p -> lftend = xpos1;
	striker_p -> rghtend = xpos2;
	printf("dfdfdf");
}

void moveStriker(struct striker_t *striker_p, char direction) { 
	striker_p -> lftend += direction;
	striker_p -> rghtend += direction;

}

void changelives(struct striker_t *striker_p) {
	striker_p ->lives--;
}

void scorepoints(struct striker_t *striker_p, char point) {
	striker_p -> points += point;
}

void update_striker(struct striker_t * striker_p, char x1_wall, char x2_wall) {
	char flag = returnflag();
	if(flag) {
		char direction = 0;
		char check = readKey();
	
		if(check == 4 && !(striker_p->lftend == x1_wall)) {
			clearLine(striker_p-> ypos, striker_p->lftend, striker_p->rghtend);
			direction--;
			moveStriker(striker_p, direction);
			drawLine(striker_p-> ypos, striker_p->lftend, striker_p->rghtend); 
		}
		if(check == 1 && !(striker_p->rghtend == x2_wall)) {
			clearLine(striker_p-> ypos, striker_p->lftend, striker_p->rghtend);
			direction++;
			moveStriker(striker_p, direction);
			drawLine(striker_p-> ypos, striker_p->lftend, striker_p->rghtend);
		}

		 set_flag0();
	}
}
