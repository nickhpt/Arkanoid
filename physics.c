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
	gotoxy(round(ball->x),round(ball->y));
	printf(" ");
	ball->x = ball->x + ball->v.x;
	ball->y = ball->y + ball->v.y;  
	gotoxy(round(ball->x),round(ball->y));
	printf("o");
}

void reflectBallRSide(struct Ball *ball) {
	ball->angle = 256 - ball->angle;
	ball->angle %= 512;
	changeDirection(&(ball->v),ball->angle);
}

void reflectBallLSide(struct Ball *ball) {
	ball->angle = 256 - ball->angle;
	ball->angle %= 512;
	changeDirection(&(ball->v),ball->angle);
}

void reflectBallTop(struct Ball *ball) {
	ball->angle = 512 - ball->angle;
	ball->angle %= 512;
    changeDirection(&(ball->v),ball->angle);
}

void reflectBallBottom(struct Ball *ball) {
	ball->angle = 512 - ball->angle;
	ball->angle %= 512;
	changeDirection(&(ball->v),ball->angle);
}
 
// checking for ball collision with wall and ceiling
void checkWallCollision(struct Ball* ball,unsigned char xmin,unsigned char ymin,unsigned char xmax,unsigned char ymax ) {
	if( round(ball->x + ball->v.x) == xmax) {
		reflectBallBottom(ball);
	}
	if( round(ball->y + ball->v.y) == ymin) {
		reflectBallRSide(ball);
	}
	if( round(ball->y + ball->v.y) == ymax) {
	reflectBallLSide(ball);
	}
	if( round(ball->x + ball->v.x) == xmin ) {
		reflectBallTop(ball);
	}		
}

void reflectBallStriker(struct Ball *ball, struct striker_t *striker) {
	int n; 
	if( ball->v.y > 0 ) {
		if( round(ball->y) >= striker->lftend && round(ball->y) <= (striker->lftend + 2) ) {
			n = ball->angle/2;
			reflectBallBottom(ball);
			ball->angle -= n;
			changeDirection(&(ball->v),ball->angle);
		}
		else if( round(ball->y) >= (striker->lftend + 3) && round(ball->y) <= (striker->lftend + 5) ) {
			n = ball->angle/3;
			reflectBallBottom(ball);
			ball->angle -= n;
			changeDirection(&(ball->v),ball->angle);
		}
	    else if( round(ball->y) >= (striker->lftend + 6) && round(ball->y) <= (striker->rghtend - 6) ) {
			reflectBallBottom(ball);
		}
		else if( round(ball->y) >= (striker->rghtend - 5) && round(ball->y) <= (striker->rghtend - 3) ) {
			n = ball->angle/3;
			reflectBallBottom(ball);
			ball->angle += n;
			changeDirection(&(ball->v),ball->angle);
		}
		else if( round(ball->y) >= (striker->rghtend - 2) && round(ball->y) <= striker->rghtend ) {
			n = ball->angle/2;
			reflectBallBottom(ball);
			ball->angle += n;
			changeDirection(&(ball->v),ball->angle);
		} 
	}
	else if ( ball->v.y < 0 ) {
		if( round(ball->y) >= striker->lftend && round(ball->y) <= (striker->lftend + 2) ) {
			n = (256 - ball->angle) /2;
			reflectBallBottom(ball);
			ball->angle -= n;
			changeDirection(&(ball->v),ball->angle);
		}
		else if( round(ball->y) >= (striker->lftend + 3) && round(ball->y) <= (striker->lftend + 5) ) {
			n = (256 - ball->angle) /3;
			reflectBallBottom(ball);
			ball->angle -= n;
			changeDirection(&(ball->v),ball->angle);
		}
	    else if( round(ball->y) >= (striker->lftend + 6) && round(ball->y) <= (striker->rghtend - 6) ) {
			reflectBallBottom(ball);
		}
		else if( round(ball->y) >= (striker->rghtend - 5) && round(ball->y) <= (striker->rghtend - 3) ) {
			n = (256 - ball->angle) /3;
			reflectBallBottom(ball);
			ball->angle += n;
			changeDirection(&(ball->v),ball->angle);
		}
		else if( round(ball->y) >= (striker->rghtend - 2) && round(ball->y) <= striker->rghtend ) {
			n = (256 - ball->angle) /2;
			reflectBallBottom(ball);
			ball->angle += n;
			changeDirection(&(ball->v),ball->angle);
		} 	
	} 
}

void updateBall(struct Ball* ball,struct striker_t *striker,unsigned char xmin,unsigned char ymin,unsigned char xmax,unsigned char ymax) {
	if( round(ball->x + ball->v.x) == (striker->ypos - 1) ) {
		reflectBallStriker(ball,striker);
	}
	checkWallCollision(ball,xmin,xmax,ymax,ymin);
	progressBall(ball);
}
