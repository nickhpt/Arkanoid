#include <eZ8.h>
#include <sio.h>
#include "ansi.h"

struct box_t{ 
	char x1,y1,x2,y2;
	char length;
	char width;
	char pwrup;
	char hp;
};


struct striker_t{
	char lftend, rghtend;								//The different zones of the striker
	char xpos,ypos;										//leftend, leftmid, central, rightmid, rigthend
}; 

void setpwr(struct box_t *box_p);

void setBox(struct box_t *box_p, char hp1, char point);

void changehp(struct box_t *box_p, char change);

void setStriker(struct striker_t *striker_p, char xpos1, char ypos1);

void moveStriker(struct striker_t *striker_p, char direction); 

void changelives(struct striker_t *striker_p);

void scorepoints(struct striker_t *striker_p, char point);
