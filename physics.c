#include <eZ8.h>
#include <sio.h>

#include "ansi.h"
#include "mathfix.h"
#include "GameSettings.h"

//This function initializes the ball to have the position x = 27, y = 127
void initBall(struct Ball *ball) {
	ball->x = (1<<14) * 27;
	ball->y = (1<<14) * 127;
	ball->angle = 128;
	changeDirection(&(ball->v),ball->angle);
}

//This function changes the direction of the ball
void changeDirection(struct TVector *v, int n) {
	v->x = sin(n);
	v->y = cos(n);
}

//Deletes the old ball and prints the new ball
void progressBall(struct Ball *ball) { 
	bgcolor(0);
	gotoxy(round(ball->x),round(ball->y));
	printf(" ");
	ball->x = ball->x + ball->v.x;
	ball->y = ball->y + ball->v.y;  
	gotoxy(round(ball->x),round(ball->y));
	printf("O");
}

//Reflects the ball verti
void reflectBallSide(struct Ball *ball) {
	ball->angle = 256 - ball->angle;
	ball->angle %= 512;
	changeDirection(&(ball->v),ball->angle);
}

void reflectBallBottomTop(struct Ball *ball) {
	ball->angle = 512 - ball->angle;
	ball->angle %= 512;
	changeDirection(&(ball->v),ball->angle);
}
 
// checking for ball collision with wall and ceiling
void checkWallCollision(struct Ball* ball,unsigned char xmin,unsigned char ymin,unsigned char xmax,unsigned char ymax ) {
	if( round(ball->x + ball->v.x) == xmax || round(ball->x + ball->v.x) == xmin ) {
		reflectBallBottomTop(ball);
	}
	if( round(ball->y + ball->v.y) == ymin || round(ball->y + ball->v.y) == ymax ) {
		reflectBallSide(ball);
	}		
}

void reflectBallStriker(struct Ball *ball, struct striker_t *striker) {
	int n; 
	unsigned char length = (striker->rghtend - striker->lftend) / 5;
	if( ball->v.y >= 0 ) {
		if( round(ball->y) >= striker->lftend && round(ball->y) <= (striker->lftend + length - 1) ) {
			n = ball->angle/2;
			reflectBallBottomTop(ball);
			ball->angle -= n;
			changeDirection(&(ball->v),ball->angle);
		}
		else if( round(ball->y) >= (striker->lftend + length) && round(ball->y) <= (striker->lftend + 2 * length - 1) ) {
			n = ball->angle/3;
			reflectBallBottomTop(ball);
			ball->angle -= n;
			changeDirection(&(ball->v),ball->angle);
		}
	    else if( round(ball->y) >= (striker->lftend + 2 * length) && round(ball->y) <= (striker->rghtend - 2 * length) ) {
			reflectBallBottomTop(ball);
		}
		else if( round(ball->y) >= (striker->rghtend - 2 * length - 1) && round(ball->y) <= (striker->rghtend - length) ) {
			n = ball->angle/3;
			reflectBallBottomTop(ball);
			ball->angle += n;
			changeDirection(&(ball->v),ball->angle);
		}
		else if( round(ball->y) >= (striker->rghtend - length - 1) && round(ball->y) <= striker->rghtend ) {
			n = ball->angle/2;
			reflectBallBottomTop(ball);
			ball->angle += n;
			changeDirection(&(ball->v),ball->angle);
		} 
	}
	else if ( ball->v.y < 0 ) {
		if( round(ball->y) >= striker->lftend && round(ball->y) <= (striker->lftend + length - 1) ) {
			n = (256 - ball->angle) /2;
			reflectBallBottomTop(ball);
			ball->angle -= n;
			changeDirection(&(ball->v),ball->angle);
		}
		else if( round(ball->y) >= (striker->lftend + length) && round(ball->y) <= (striker->lftend + 2 * length - 1) ) {
			n = (256 - ball->angle) /3;
			reflectBallBottomTop(ball);
			ball->angle -= n;
			changeDirection(&(ball->v),ball->angle);
		}
	    else if( round(ball->y) >= (striker->lftend + 2 * length) && round(ball->y) <= (striker->rghtend - 2 * length) ) {
			reflectBallBottomTop(ball);
		}
		else if( round(ball->y) >= (striker->rghtend - 2 * length - 1) && round(ball->y) <= (striker->rghtend - length) ) {
			n = (256 - ball->angle) /3;
			reflectBallBottomTop(ball);
			ball->angle += n;
			changeDirection(&(ball->v),ball->angle);
		}
		else if( round(ball->y) >= (striker->rghtend - length - 1) && round(ball->y) <= striker->rghtend ) {
			n = (256 - ball->angle) /2;
			reflectBallBottomTop(ball);
			ball->angle += n;
			changeDirection(&(ball->v),ball->angle);
		} 	
	} 
}

void boxImpact(struct Ball *ball, char *boxes, struct striker_t *striker, unsigned char oldx) {
	unsigned char i;
	unsigned char x,y;
	x = (round(ball->x + ball->v.x) - 4) / 4;
    y = (round(ball->y + ball->v.y) - 8) / 16;
	i = x + 5 * y;
	boxes += i;
	if( (*boxes) && (((round(ball->x + ball->v.x) >= 4) && (round(ball->x + ball->v.x) <= 23) && (round(ball->y + ball->v.y) >= 8) &&
 		(round(ball->y + ball->v.y) <= 231))) ) {
		(*boxes)--;
		striker->points += 50;
		gotoxy(1,241);
		printf("Points:");
		gotoxy(2,241);
		printf("%d",striker->points);
		x *= 4;
		x += 4;
		y *= 16;
		y += 8;
		drawBox2(x,y,x + 4,y+16,(*boxes));
		if( ((round(ball->y + ball->v.y) == y && round(ball->x  + ball->v.x) == x) || (round(ball->x + ball->v.x) == x 
			&& round(ball->y + ball->v.y) == (y + 15))) && oldx < round(ball->x  + ball->v.x) ) {
				reflectBallBottomTop(ball);
		}
		else if ( ((round(ball->y + ball->v.y) == y && round(ball->x  + ball->v.x) == (x + 3)) || (round(ball->x + ball->v.x) == (x + 3) 
			&& round(ball->y + ball->v.y) == (y + 15))) && oldx < round(ball->x  + ball->v.x) ) {
				reflectBallSide(ball);
		}
		else if ( ((round(ball->y + ball->v.y) == y && round(ball->x  + ball->v.x) == (x + 3)) || (round(ball->x + ball->v.x) == (x + 3) 
			&& round(ball->y + ball->v.y) == (y + 15))) && oldx > round(ball->x  + ball->v.x) ) {
				reflectBallBottomTop(ball);
		}
		else if ( ((round(ball->y + ball->v.y) == y && round(ball->x  + ball->v.x) == x) || (round(ball->x + ball->v.x) == x 
			&& round(ball->y + ball->v.y) == (y + 15))) && oldx > round(ball->x  + ball->v.x) ) {
				reflectBallSide(ball);	
		}
		else if( round(ball->y + ball->v.y) == y || round(ball->y + ball->v.y) == (y + 15) ) {
			reflectBallSide(ball);
		}
		else if( round(ball->x  + ball->v.x) == x || round(ball->x + ball->v.x) == (x + 3) ) {
			reflectBallBottomTop(ball);
		}
	}
	bgcolor(0);
}

void checkFailure(struct Ball *ball, struct striker_t *striker,unsigned char left, unsigned char right, unsigned char yposs) {
	if(round(ball->x) > 57) {
		striker->lives--;
		if(striker->lives == 0) {
			PEOUT = 0x1F;
			PGOUT = 0x00;
			PEOUT |= 0x80;
			PEOUT &= ~0x80;
		}
		else if(striker->lives == 1) {
			PEOUT = 0x1F;
			PGOUT = 0x00;
			PGOUT |= 0x80;
			PGOUT &= ~0x80;
		}
		else if(striker->lives == 2) {
			PEOUT = 0x1F;
			PGOUT = 0x00;
			PEOUT |= 0x20;
			PEOUT &= ~0x20;
		}
		else if(striker->lives == 3) {
			PEOUT = 0x1F;
			PGOUT = 0x00;
			PEOUT |= 0x40;
			PEOUT &= ~0x40;
		}
		clearLine(striker->ypos,striker->lftend,striker->rghtend);
		gotoxy(ball->x,ball->y);
		printf(" ");
		setStriker1(striker,left,right,yposs);
		initBall(ball);
	}
}

void updateBall(struct Ball* ball, struct striker_t *striker,char *boxes, unsigned char xmin,unsigned char ymin,unsigned char xmax,
				unsigned char ymax, unsigned char oldx) {
	if( round(ball->x + ball->v.x) == (striker->ypos) ) {
		reflectBallStriker(ball,striker);
	}
	boxImpact(ball,boxes,striker,oldx);
	checkWallCollision(ball,xmin,xmax,ymax,ymin);
	progressBall(ball);
}
