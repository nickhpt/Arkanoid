#include <eZ8.h>
#include <sio.h>

struct box_t{ 
	char x1,y1,x2,y2;
	char length;
	char width;
	char pwrup;
	char hp;
};

void setpwr(struct box_t *box_p);

void setBox(struct box_t *box_p);

void changehp(struct box_t *box_p);
