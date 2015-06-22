#include <eZ8.h>
#include <sio.h>

#include "ansi.h"
#include "mathfix.h"
#include "GameSettings.h"

void changeDirection(struct TVector *v, int n) {
	v->x = sin(n);
	v->y = cos(n);
}

void progressBall(struct Ball *ball) { 
	bgcolor(0);
	gotoxy(round(ball->x),round(ball->y));
	printf(" ");
	ball->x = ball->x + ball->v.x;
	ball->y = ball->y + ball->v.y;  
	gotoxy(round(ball->x),round(ball->y));
	printf("O");
}

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

void boxImpact(struct Ball *ball, char *boxes) {
	unsigned char i;
	unsigned char x,y;
	x = (round(ball->x + ball->v.x) - 4) / 4;
    y = (round(ball->y + ball->v.y) - 8) / 16;
	i = 14*x + y;
	boxes += i;
	if( (*boxes) && (((round(ball->x + ball->v.x) >= 2) && (round(ball->x + ball->v.x) <= 23) && (round(ball->y + ball->v.y) >= 8) &&
 		(round(ball->y + ball->v.y) <= 231))) ) {
		(*boxes)--;
		x *= 4;
		x += 4;
		y *= 16;
		y += 8;
		drawBox2(x,y,x + 4,y+16,(*boxes));
		if( round(ball->y + ball->v.y) == y || round(ball->y + ball->v.y) == (y + 15) ) {
			reflectBallSide(ball);
		}
		else if( round(ball->x  + ball->v.x) == x || round(ball->x + ball->v.x) == (x + 3) ) {
			reflectBallBottomTop(ball);
		}
	}
	bgcolor(0);
}

void updateBall(struct Ball* ball, struct striker_t *striker,char *boxes, unsigned char xmin,unsigned char ymin,unsigned char xmax,unsigned char ymax) {
	if( round(ball->x + ball->v.x) == (striker->ypos) ) {
		reflectBallStriker(ball,striker);
	}
	boxImpact(ball,boxes);
	checkWallCollision(ball,xmin,xmax,ymax,ymin);
	progressBall(ball);
}