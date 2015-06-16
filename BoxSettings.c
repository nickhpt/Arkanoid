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

void changeBox(struct *Box Box) {
	gotoxy(Box.x,Box.y);
	if(box.hp == 1){
		fgcolor(x);
		//print box med 1 liv
	}
	if(box.hp == 2){
		fgcolor(x);
		//print box med 2 liv 
	}
	if(box.hp==3) {
		fgcolor(x)
		//print box med 3 liv
	}
	}
	}
	}
}

/*
void createBox(box_t * box) { //Begyndelsen på createBox
int height = 4;
int width = 2;
	if (box -> hp != 0) {
	    for (int i = 0; i <= heigth; i++) {
		     gotoxy(box -> x1, box -> y1+i); // gennemløber en side i boxen
			 for (j = 0; j < width; j++) {
			 //printf tegn kassen tegnet "|" kan evt bruges? eller en tilsvarende ANSI
			 	}
			}
	  }else{
 	  	if(box -> hp <= 0) {
			for (i = 0; i < heigth; i++) {
				gotoxy(box -> x1,box -> y+i)
				for (j = 0; j < width; j++) {
					printf(" "); //Tegn ingenting hvis ikke der nogen liv 
				}
			}
		}
*/
