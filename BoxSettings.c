#include <eZ8.h>
#include <sio.h>
#include "ansi.h"
#include "mathfix.h"
#include "charset.h"
#include "GameSettings.h"

struct box_t{ 
	char x1,y1;
	char length;
	char width;
	char pwrup;
	char hp;
	char boxpoint;
};

void setpwr(struct box_t *box_p) {
	box_p -> pwrup = 0;

} 

void setBox(struct box_t *box_p, char hp1, char point) {
		box_p ->length = 3;
		box_p -> width = 1;
		box_p -> hp = hp1;
		setpwr(box_p);
		box_p -> boxpoint = point;

		
} 

void changehp(struct box_t *box_p) {
	box_p->hp--;
	
}
