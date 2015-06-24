#include <eZ8.h>
#include <sio.h>
#include "ansi.h"


struct striker_t {
	unsigned char lftend, rghtend;											
	unsigned char ypos;																
	int points;
	unsigned char lives;										
}; 


void setStriker(struct striker_t *striker_p,unsigned char xpos1,unsigned char xpos2,unsigned char ypos1);

void setStriker1(struct striker_t *striker_p, unsigned char xpos1,unsigned char xpos2,unsigned char ypos1);

void moveStriker(struct striker_t *striker_p,unsigned char direction); 


void initStriker(struct striker_t * striker_p,unsigned char xpos1,unsigned char xpos2,unsigned char ypos1);

void change_striker(struct striker_t * striker_p,unsigned char xpos1,unsigned char xpos2);

void update_striker(struct striker_t * striker_p,unsigned char x1_wall,unsigned char x2_wall);

 
struct TVector {
      long x, y;
};

struct Ball {
       long x;
	   long y;
	   struct TVector v;
	   int angle;
};
 
void changeDirection(struct TVector *v, int n);
void reflectBallSide(struct Ball *ball);
void reflectBallBottomTop(struct Ball *ball);

void reflectBallStriker(struct Ball *ball, struct striker_t *striker);
void boxImpact(struct Ball *ball, char *boxes, struct striker_t *striker, unsigned char oldx);

void checkFailure(struct Ball *ball, struct striker_t *striker,unsigned char left, unsigned char right, unsigned char yposs);
void progressBall(struct Ball *ball);
void checkWallCollision(struct Ball* ball,unsigned char xmin,unsigned char ymin,unsigned char xmax,unsigned char ymax );
void updateBall(struct Ball* ball, struct striker_t *striker,char *boxes, unsigned char xmin,unsigned char ymin,unsigned char xmax,
				unsigned char ymax, unsigned char oldx);
void make_boxes(char boxarray[14][5]);
void initBall(struct Ball *ball);

extern const char level1[14][5];
extern const char level2[14][5];
extern const char level3[14][5];

