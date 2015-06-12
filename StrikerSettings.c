#include <eZ8>
#include <sio>
#include "ansi.c"
#include "mathfix.h"
#include "GameSettingsh"

// structure for striker
struct striker_t{
	char lftend, rghtend;								//The different zones of the striker
	char xpos,ypos;										//leftend, leftmid, central, rightmid, rigthend
	char points;
	char lives;

}

void setStriker(struct striker_t *striker_p, char xpos1, char ypos1) {
	striker_p -> xpos = xpos1;
	striker_p -> ypos = ypos1;
	striker_p -> points = 0;
	striker_p -> lives = 3;
}

void moveStriker(struct striker_t *striker_p, char direction) { 
	striker_p -> xpos += direction;	
}

void changelives(struct striker_t *striker_p) {
	striker_t ->lives--;
}

void scorepoints(struct striker_t *striker_p, char point) {
	striker_p -> points += point;
}
