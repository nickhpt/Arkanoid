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
 
void rotate(struct TVector *v, int n);
void reflectBallRSidefromBelow(struct Ball *ball);
void reflectBallRSidefromAbove(struct Ball *ball);
void reflectBallLSidefromBelow(struct Ball *ball);
void reflectBallLSidefromAbove(struct Ball *ball);
void reflectBallTopfromRight(struct Ball *ball);
void reflectBallTopfromLeft(struct Ball *ball);



void reflectBallSides(struct TVector *v);
void reflectBallTop(struct TVector *v);
long expand(long i);
void printFix(long i);
long sin(int n);
long cos(int n);
void progressBall(struct Ball *ball);
void checkWallCollision(struct Ball* ball,char xmin, char ymin, char xmax, char ymax );
void updateBall(struct Ball* ball,char xmin, char ymin, char xmax, char ymax );
long round(long n);
