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
 
void rotate(struct TVector *v, int n);
void reflectBallSides(struct TVector *v,int n);
void reflectBallTop(struct TVector *v,int n);
long expand(long i);
void printFix(long i);
long sin(int n);
long cos(int n);
struct Ball{
       long x;
       long y;
       long x1;
       long y1;

	   struct TVector v;
	  
};
