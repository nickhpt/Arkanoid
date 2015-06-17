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

void reflectBallRSidefromBelow(struct Ball *ball) {
	int n = 512 - ball->angle;
	ball->angle = 256 + n;
	changeDirection(&(ball->v),ball->angle);	
}

void reflectBallRSidefromAbove(struct Ball *ball) {
	ball->angle = 256 - ball->angle;
	changeDirection(&(ball->v),ball->angle);
}

void reflectBallLSidefromBelow(struct Ball *ball) {
	int n = ball->angle - 256;
	ball->angle = 512 - n;
	changeDirection(&(ball->v),ball->angle);
}

void reflectBallLSidefromAbove(struct Ball *ball) {
	ball->angle = 256 - ball->angle;
	changeDirection(&(ball->v),ball->angle);
}

void reflectBallTopfromRight(struct Ball *ball) {
	int n = ball->angle - 256;
	ball->angle = 256 - n;
	changeDirection(&(ball->v),ball->angle);
}

void reflectBallTopfromLeft(struct Ball *ball) {
	ball->angle = 512 - ball->angle;
    changeDirection(&(ball->v),ball->angle);
}

void reflectBallBottomfromRight(struct Ball *ball) {
	int n = 256 - ball->angle;
	ball->angle = 256 + n;
	changeDirection(&(ball->v),ball->angle);
}

void reflectBallBottomfromLeft(struct Ball *ball) {
	ball->angle = 512 - ball->angle;
	changeDirection(&(ball->v),ball->angle);
}
 
// checking for ball collision with wall and ceiling
void checkWallCollision(struct Ball* ball,unsigned char xmin,unsigned char ymin,unsigned char xmax,unsigned char ymax ) {
	if(ball->v.x >= 0 && ball->v.y >= 0) {
		if( round(ball->x + ball->v.x) == xmax) {
			reflectBallBottomfromRight(ball);
		}
		if( round(ball->y + ball->v.y) == ymin) {
			reflectBallRSidefromAbove(ball);
		}
	}
	if(ball->v.x >= 0 && ball->v.y < 0) {
		if( round(ball->x + ball->v.x) == xmax ) {
			reflectBallBottomfromLeft(ball);
		}
		if( round(ball->y + ball->v.y) == ymax) {
			reflectBallLSidefromAbove(ball);
		}
	}
	if(ball->v.x < 0 && ball->v.y <= 0) {
		if( round(ball->x + ball->v.x) == xmin ) {
			reflectBallTopfromLeft(ball);
		}
		if( round(ball->y + ball->v.y) == ymax) {
			reflectBallLSidefromBelow(ball);
		}
	}
	if(ball->v.x < 0 && ball->v.y > 0) {
		if( round(ball->x + ball->v.x) == xmin ) {
			reflectBallTopfromRight(ball);
		}
		if( round(ball->y + ball->v.y) == ymin) {
			reflectBallRSidefromBelow(ball);
		}
	}			
}

void reflectBallStrikerfromLeft(struct Ball *ball, struct striker_t *striker) {
	int n; 
	if( round(ball->y) >= striker->lftend && round(ball->y) <= (striker->lftend + 2) ) {
		n = ball->angle/2;
		reflectBallBottomfromLeft(ball);
		ball->angle -= n;
		changeDirection(&(ball->v),ball->angle);
	}
	else if( round(ball->y) >= (striker->lftend + 3) && round(ball->y) <= (striker->lftend + 5) ) {
		n = ball->angle/3;
		reflectBallBottomfromLeft(ball);
		ball->angle -= n;
		changeDirection(&(ball->v),ball->angle);
	}
    else if( round(ball->y) >= (striker->lftend + 6) && round(ball->y) <= (striker->rghtend - 6) ) {
		reflectBallBottomfromLeft(ball);
	}
	else if( round(ball->y) >= (striker->rghtend - 5) && round(ball->y) <= (striker->rghtend - 3) ) {
		n = ball->angle/3;
		reflectBallBottomfromLeft(ball);
		ball->angle += n;
		changeDirection(&(ball->v),ball->angle);
	}
	else if( round(ball->y) >= (striker->rghtend - 2) && round(ball->y) <= striker->rghtend ) {
		n = ball->angle/2;
		reflectBallBottomfromLeft(ball);
		ball->angle += n;
		changeDirection(&(ball->v),ball->angle);
	} 
}

void reflectBallStrikerfromRight(struct Ball *ball, struct striker_t *striker) {
	int n; 
	if( round(ball->y) >= striker->lftend && round(ball->y) <= (striker->lftend + 2) ) {
		n = (256 - ball->angle) /2;
		reflectBallBottomfromRight(ball);
		ball->angle -= n;
		changeDirection(&(ball->v),ball->angle);
	}
	else if( round(ball->y) >= (striker->lftend + 3) && round(ball->y) <= (striker->lftend + 5) ) {
		n = (256 - ball->angle) /3;
		reflectBallBottomfromRight(ball);
		ball->angle -= n;
		changeDirection(&(ball->v),ball->angle);
	}
    else if( round(ball->y) >= (striker->lftend + 6) && round(ball->y) <= (striker->rghtend - 6) ) {
		reflectBallBottomfromRight(ball);
	}
	else if( round(ball->y) >= (striker->rghtend - 5) && round(ball->y) <= (striker->rghtend - 3) ) {
		n = (256 - ball->angle) /3;
		reflectBallBottomfromRight(ball);
		ball->angle += n;
		changeDirection(&(ball->v),ball->angle);
	}
	else if( round(ball->y) >= (striker->rghtend - 2) && round(ball->y) <= striker->rghtend ) {
		n = (256 - ball->angle) /2;
		reflectBallBottomfromRight(ball);
		ball->angle += n;
		changeDirection(&(ball->v),ball->angle);
	} 
}

void updateBall(struct Ball* ball,struct striker_t *striker,unsigned char xmin,unsigned char ymin,unsigned char xmax,unsigned char ymax) {
	if( round(ball->x + ball->v.x) == (striker->ypos - 1) ) {
		if( ball->v.y > 0 ) { 
			reflectBallStrikerfromLeft(ball,striker);
   	    }
		else if( ball->v.y < 0 ) {
			reflectBallStrikerfromRight(ball,striker);
		}
	}
	checkWallCollision(ball,xmin,xmax,ymax,ymin);
	progressBall(ball);
}
