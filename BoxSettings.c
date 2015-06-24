#include <eZ8.h>
#include <sio.h>
#include <stdio.h>
#include "ansi.h"
#include "GameSettings.h"

const char level1[14][5] = {
							{1,0,0,1,0},
							{1,0,0,0,1},
							{1,0,0,0,1},
							{1,1,1,1,0},
							{0,0,0,0,0},
							{0,1,1,1,0},
							{1,0,0,0,1},
							{1,0,0,0,1},
							{0,1,1,1,0},
							{0,0,0,0,0},
							{0,1,0,0,0},
							{1,0,1,0,1},	
							{1,0,1,0,1},
							{0,0,0,1,0}
							};

const char level2[14][5] = {
							{3,3,3,3,0},
							{3,3,3,0,0},
							{3,3,0,0,0},
							{3,0,0,0,0},
							{0,0,0,0,0},
							{0,3,0,0,0},
							{3,5,3,2,2},
							{0,3,0,2,0},
							{0,0,0,0,0},
							{0,0,0,0,0},
							{0,0,0,0,0},
							{0,1,0,0,0},	
							{1,5,1,0,0},
							{0,1,0,0,0}
							};
const char level3[14][5] = {
							{2,0,2,1,2},
							{5,0,2,0,0},
							{2,0,0,0,2},
							{0,0,0,0,0},
							{3,3,3,3,3},
							{0,0,5,0,0},
							{3,0,0,0,3},
							{0,0,0,0,0},
							{4,4,0,2,2},
							{4,4,0,0,2},
							{4,0,2,2,2},
							{4,0,3,3,3},	
							{0,0,0,0,0},
							{1,1,0,1,1}
							};



void make_boxes(char boxarray[14][5]) {
	char i, j;
	unsigned char x1 = 4;
	unsigned char y1 = 8;
	gotoxy(x1,y1);
	for( i = 0; i < 14; i++) {
		for( j = 0; j < 5; j++) {
			
			drawBox2(x1,y1,x1 + 4, y1 + 16, boxarray[i][j]);
			
			x1 += 4;
		}
		x1 = 4;
		y1 += 16;
	}
}

// C- FILEN:

#include <eZ8.h>
#include <sio.h>
#include "ascii.h"


const char velkommen[19][16]  ={

 {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,46},
 {95,95,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
 {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
 {32,13,10,95,95,32,32,95,32,32,95,95,32,95,95,95},
 {95,32,124,32,32,124,32,32,32,95,95,95,95,32,32,95},
 {95,95,95,32,32,32,95,95,95,95,95,32,32,32,95,95},
 {95,95,32,32,13,10,92,32,92,47,32,92,47,32,47,47},
 {32,95,95,32,92,124,32,32,124,32,95,47,32,95,95,95},
 {92,47,32,32,95,32,92,32,47,32,32,32,32,32,92,95},
 {47,32,95,95,32,92,32,13,10,32,92,32,32,32,32,32},
 {47,92,32,32,95,95,95,47,124,32,32,124,95,92,32,32},
 {92,95,95,40,32,32,60,95,62,32,41,32,32,89,32,89},
 {32,32,92,32,32,95,95,95,47,32,13,10,32,32,92,47},
 {92,95,47,32,32,92,95,95,95,32,32,62,95,95,95,95},
 {47,92,95,95,95,32,32,62,95,95,95,95,47,124,95,95},
 {124,95,124,32,32,47,92,95,95,95,32,32,62,13,10,32},
 {32,32,32,32,32,32,32,32,32,32,32,32,92,47,32,32},
 {32,32,32,32,32,32,32,32,92,47,32,32,32,32,32,32},
 {32,32,32,32,32,32,92,47,32,32,32,32,32,92,47,32}
};

// Main C Filen

#include <eZ8.h>
#include <sio.h>
#include "ascii.h"

void main(){

	printf("%c",velkommen[10][10]);

	while(1);

	
}

//Header Filen:
#include <eZ8.h>
#include <sio.h>

extern const char velkommen[19][16];

//Metoden der kan printe arrayet

void drawWelcome(){
	int i; int j;
	for (i = 0; i < 17; i++){
		for (j = 0; j < 20; j++){
			printf("%c",velkommen[i][j]);
		}
	}
	
}
