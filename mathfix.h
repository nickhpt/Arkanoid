// =====================================================================
//
//  Exported by Cearn's excellut v1.0
//  (comments, kudos, flames to daytshen@hotmail.com)
//
// =====================================================================
 
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
long expand(long i);
void printFix(long i);
long sin(int n);
long cos(int n);