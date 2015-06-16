#include <eZ8.h>
#include <sio.h>
#include "ansi.h"
#include "mathfix.h"
#include "GameSettings.h"
#include "inputfix.h"


void setStriker(struct striker_t *striker_p, unsigned char xpos1,unsigned char xpos2,unsigned char ypos1) {
	striker_p -> ypos = ypos1;
	striker_p -> points = 0;
	striker_p -> lives = 3;
	striker_p -> lftend = xpos1;
	striker_p -> rghtend = xpos2;
	printf("dfdfdf");
}

void initStriker(struct striker_t * striker_p,unsigned char xpos1,unsigned char xpos2,unsigned char ypos1) {
	striker_p -> ypos = ypos1;
	striker_p -> points = 0;
	striker_p -> lives = 3;
	striker_p -> lftend = xpos1;
	striker_p -> lftmid = striker_p -> lftend +1;
	striker_p -> center = striker_p -> lftend + 2;
	striker_p -> rghtmid = striker_p -> rghtend -1;
	striker_p -> rghtend = xpos2;
}

void change_striker(struct striker_t * striker_p,unsigned char xpos1,unsigned char xpos2) {
	striker_p -> lftend = xpos1;
	striker_p -> rghtend = xpos2;
	striker_p -> lftmid = striker_p -> lftend +1;
	striker_p -> center = striker_p -> lftend + 2;
	striker_p -> rghtmid = striker_p -> rghtend -1; 
}

void moveStriker(struct striker_t *striker_p,unsigned char direction) { 
	striker_p -> lftend += direction;
	striker_p -> rghtend += direction;

}

void changelives(struct striker_t *striker_p) {
	striker_p ->lives--;
}

void scorepoints(struct striker_t *striker_p,unsigned char point) {
	striker_p -> points += point;
}

void update_striker(struct striker_t * striker_p,unsigned char x1_wall, unsigned char x2_wall) {
	unsigned char flag = returnflag();
	if(flag) {
		unsigned char direction = 0;
		unsigned char check = readKey();
	
		if(check == 4 && !(striker_p->lftend == x1_wall+1)) {
			clearLine(striker_p-> ypos, striker_p->lftend, striker_p->rghtend);
			direction--;
			moveStriker(striker_p, direction);
			change_striker(striker_p, striker_p->lftend, striker_p->rghtend);
			drawLine(striker_p-> ypos, striker_p->lftend, striker_p->rghtend);
		}
		if(check == 1 && !(striker_p->rghtend == x2_wall-1)) {
			clearLine(striker_p-> ypos, striker_p->lftend, striker_p->rghtend);
			direction++;
			moveStriker(striker_p, direction);
			change_striker(striker_p, striker_p->lftend, striker_p->rghtend);	 
			drawLine(striker_p-> ypos, striker_p->lftend, striker_p->rghtend);
		}

		 set_flag0();
	}
}
