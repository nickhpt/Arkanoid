#include <eZ8.h>
#include <sio.h>
#include "ansi.h"

struct box_t{ 
	char x1,y1,x2,y2;
	char pwrup;
	char hp;
	char boxpoint;
};


struct striker_t{
	char lftend, rghtend;								//The different zones of the striker
	char xpos,ypos;										//leftend, leftmid, central, rightmid, rigthend
}; 

void setpwr(struct box_t *box_p);

void setBox(struct box_t *box_p, char xpos1, char ypos1,  char xpos2, char ypos2, char hp1, char point);

void changehp(struct box_t *box_p, char change);

void setStriker(struct striker_t *striker_p, char xpos1, char ypos1);

void moveStriker(struct striker_t *striker_p, char direction); 

void changelives(struct striker_t *striker_p);

void scorepoints(struct striker_t *striker_p, char point);
