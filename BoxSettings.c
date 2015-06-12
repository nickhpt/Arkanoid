#include <eZ8.h>
#include <sio.h>
#include "ansi.h"
#include "mathfix.h"
#include "charset.h"
#include "GameSettings.h"

struct box_t{ 
	char x1,y1;
	char x2;
	char y2;
	char pwrup;
	char hp;
};

void setpwr(struct box_t *box_p) {
	box_p -> pwrup = 0;

} 

void setBox(struct box_t *box_p) {
		box_p ->x2 = 3;
		box_p -> y2 = 1;
		box_p -> hp = 2;
		setpwr(box_p);
		
} 

void changehp(struct box_t *box_p) {
	box_p->hp--;
	
}
