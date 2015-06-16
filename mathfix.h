#ifndef mathFix_H
#define mathFix_H
 
// === LUT SIZES ===
#define SIN_SIZE 512
 
// === LUT DECLARATIONS ===
extern const signed short SIN[512];
 
#endif  // LUT_H
 
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
void reflectBallRSidefromBelow(struct Ball *ball);
void reflectBallRSidefromAbove(struct Ball *ball);
void reflectBallLSidefromBelow(struct Ball *ball);
void reflectBallLSidefromAbove(struct Ball *ball);
void reflectBallTopfromRight(struct Ball *ball);
void reflectBallTopfromLeft(struct Ball *ball);
void reflectBallBottomfromRight(struct Ball *ball);
void reflectBallBottomfromLeft(struct Ball *ball);

void rotate(struct TVector *v, int n);
long expand(long i);
void printFix(long i);
long sin(int n);
long cos(int n);
long round(long n);

void progressBall(struct Ball *ball);
void checkWallCollision(struct Ball* ball,unsigned char xmin,unsigned char ymin,unsigned char xmax,unsigned char ymax );
void updateBall(struct Ball* ball,unsigned char xmin,unsigned char ymin,unsigned char xmax,unsigned char ymax);
