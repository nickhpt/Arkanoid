#include <eZ8.h>
#include <sio.h>

#include "ansi.h"
#include "mathfix.h"
#include "GameSettings.h"

void touch(struct Ball *ball) {
	
}

void reflectStrikerFromLeft(struct Ball *ball, struct striker_t *striker) {
	reflectBallTop(&(ball->v));
	if(ball->y == striker->lftend) {
		rotate(&(ball->v),64);
	}
	else if(ball->y == striker->lftmid) {
		rotate(&(ball->v),32);
	}
	else if(ball->y == striker->rghtmid) {
		rotate(&(ball->v),-32);
	}
	else if(ball->y == striker->rghtend) {
		rotate(&(ball->v),-64);
	}
}

void reflectStrikerFromRight(struct Ball *ball, struct striker_t *striker) {
	reflectBallTop(&(ball->v));
	if(ball->y == striker->rghtend) {
		rotate(&(ball->v),64);
	}
	else if(ball->y == striker->rghtmid) {
		rotate(&(ball->v),32);
	}
	else if(ball->y == striker->lftmid) {
		rotate(&(ball->v),-32);
	}
	else if(ball->y == striker->lftend) {
		rotate(&(ball->v),-64);
	}
}

void checkCollision(struct Ball *ball, struct striker_t *striker) {
	if(ball->v.x > 0 && ball->v.y > 0) {
		
	}
}

//void updateBall(

void moveBall(struct TVector *v, int n) {
	long x1 = v->x; 
	long y1 = v->y;
	v->x = x+cos(n);
	v->y = y+sin(n)

	long afrundetX = round(v.x);
	long afrundetY = round(v.y);

	gotoxy(afrundetX,afrundetY); 
