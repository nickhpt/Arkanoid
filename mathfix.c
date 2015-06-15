// =====================================================================
//    Look-Up Tables
//      SIN: sin(x*pi/256)
//
//  Exported by Cearn's excellut v1.0
//  (comments, kudos, flames to daytshen@hotmail.com)
//
// =====================================================================
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routine
#include "mathFix.h"
// -----------------------------------------------------------------------
// SIN: a 512 long LUT of 16bit values in 2.14 format
// sin(x*pi/256)
const signed short SIN[512]=
{
    0x0000,0x00C9,0x0192,0x025B,0x0324,0x03ED,0x04B5,0x057E,
    0x0646,0x070E,0x07D6,0x089D,0x0964,0x0A2B,0x0AF1,0x0BB7,
    0x0C7C,0x0D41,0x0E06,0x0ECA,0x0F8D,0x1050,0x1112,0x11D3,
    0x1294,0x1354,0x1413,0x14D2,0x1590,0x164C,0x1709,0x17C4,
    0x187E,0x1937,0x19EF,0x1AA7,0x1B5D,0x1C12,0x1CC6,0x1D79,
    0x1E2B,0x1EDC,0x1F8C,0x203A,0x20E7,0x2193,0x223D,0x22E7,
    0x238E,0x2435,0x24DA,0x257E,0x2620,0x26C1,0x2760,0x27FE,
    0x289A,0x2935,0x29CE,0x2A65,0x2AFB,0x2B8F,0x2C21,0x2CB2,
 
    0x2D41,0x2DCF,0x2E5A,0x2EE4,0x2F6C,0x2FF2,0x3076,0x30F9,
    0x3179,0x31F8,0x3274,0x32EF,0x3368,0x33DF,0x3453,0x34C6,
    0x3537,0x35A5,0x3612,0x367D,0x36E5,0x374B,0x37B0,0x3812,
    0x3871,0x38CF,0x392B,0x3984,0x39DB,0x3A30,0x3A82,0x3AD3,
    0x3B21,0x3B6D,0x3BB6,0x3BFD,0x3C42,0x3C85,0x3CC5,0x3D03,
    0x3D3F,0x3D78,0x3DAF,0x3DE3,0x3E15,0x3E45,0x3E72,0x3E9D,
    0x3EC5,0x3EEB,0x3F0F,0x3F30,0x3F4F,0x3F6B,0x3F85,0x3F9C,
    0x3FB1,0x3FC4,0x3FD4,0x3FE1,0x3FEC,0x3FF5,0x3FFB,0x3FFF,
 
    0x4000,0x3FFF,0x3FFB,0x3FF5,0x3FEC,0x3FE1,0x3FD4,0x3FC4,
    0x3FB1,0x3F9C,0x3F85,0x3F6B,0x3F4F,0x3F30,0x3F0F,0x3EEB,
    0x3EC5,0x3E9D,0x3E72,0x3E45,0x3E15,0x3DE3,0x3DAF,0x3D78,
    0x3D3F,0x3D03,0x3CC5,0x3C85,0x3C42,0x3BFD,0x3BB6,0x3B6D,
    0x3B21,0x3AD3,0x3A82,0x3A30,0x39DB,0x3984,0x392B,0x38CF,
    0x3871,0x3812,0x37B0,0x374B,0x36E5,0x367D,0x3612,0x35A5,
    0x3537,0x34C6,0x3453,0x33DF,0x3368,0x32EF,0x3274,0x31F8,
    0x3179,0x30F9,0x3076,0x2FF2,0x2F6C,0x2EE4,0x2E5A,0x2DCF,
 
    0x2D41,0x2CB2,0x2C21,0x2B8F,0x2AFB,0x2A65,0x29CE,0x2935,
    0x289A,0x27FE,0x2760,0x26C1,0x2620,0x257E,0x24DA,0x2435,
    0x238E,0x22E7,0x223D,0x2193,0x20E7,0x203A,0x1F8C,0x1EDC,
    0x1E2B,0x1D79,0x1CC6,0x1C12,0x1B5D,0x1AA7,0x19EF,0x1937,
    0x187E,0x17C4,0x1709,0x164C,0x1590,0x14D2,0x1413,0x1354,
    0x1294,0x11D3,0x1112,0x1050,0x0F8D,0x0ECA,0x0E06,0x0D41,
    0x0C7C,0x0BB7,0x0AF1,0x0A2B,0x0964,0x089D,0x07D6,0x070E,
    0x0646,0x057E,0x04B5,0x03ED,0x0324,0x025B,0x0192,0x00C9,
 
    0x0000,0xFF37,0xFE6E,0xFDA5,0xFCDC,0xFC13,0xFB4B,0xFA82,
    0xF9BA,0xF8F2,0xF82A,0xF763,0xF69C,0xF5D5,0xF50F,0xF449,
    0xF384,0xF2BF,0xF1FA,0xF136,0xF073,0xEFB0,0xEEEE,0xEE2D,
    0xED6C,0xECAC,0xEBED,0xEB2E,0xEA70,0xE9B4,0xE8F7,0xE83C,
    0xE782,0xE6C9,0xE611,0xE559,0xE4A3,0xE3EE,0xE33A,0xE287,
    0xE1D5,0xE124,0xE074,0xDFC6,0xDF19,0xDE6D,0xDDC3,0xDD19,
    0xDC72,0xDBCB,0xDB26,0xDA82,0xD9E0,0xD93F,0xD8A0,0xD802,
    0xD766,0xD6CB,0xD632,0xD59B,0xD505,0xD471,0xD3DF,0xD34E,
 
    0xD2BF,0xD231,0xD1A6,0xD11C,0xD094,0xD00E,0xCF8A,0xCF07,
    0xCE87,0xCE08,0xCD8C,0xCD11,0xCC98,0xCC21,0xCBAD,0xCB3A,
    0xCAC9,0xCA5B,0xC9EE,0xC983,0xC91B,0xC8B5,0xC850,0xC7EE,
    0xC78F,0xC731,0xC6D5,0xC67C,0xC625,0xC5D0,0xC57E,0xC52D,
    0xC4DF,0xC493,0xC44A,0xC403,0xC3BE,0xC37B,0xC33B,0xC2FD,
    0xC2C1,0xC288,0xC251,0xC21D,0xC1EB,0xC1BB,0xC18E,0xC163,
    0xC13B,0xC115,0xC0F1,0xC0D0,0xC0B1,0xC095,0xC07B,0xC064,
    0xC04F,0xC03C,0xC02C,0xC01F,0xC014,0xC00B,0xC005,0xC001,
 
    0xC000,0xC001,0xC005,0xC00B,0xC014,0xC01F,0xC02C,0xC03C,
    0xC04F,0xC064,0xC07B,0xC095,0xC0B1,0xC0D0,0xC0F1,0xC115,
    0xC13B,0xC163,0xC18E,0xC1BB,0xC1EB,0xC21D,0xC251,0xC288,
    0xC2C1,0xC2FD,0xC33B,0xC37B,0xC3BE,0xC403,0xC44A,0xC493,
    0xC4DF,0xC52D,0xC57E,0xC5D0,0xC625,0xC67C,0xC6D5,0xC731,
    0xC78F,0xC7EE,0xC850,0xC8B5,0xC91B,0xC983,0xC9EE,0xCA5B,
    0xCAC9,0xCB3A,0xCBAD,0xCC21,0xCC98,0xCD11,0xCD8C,0xCE08,
    0xCE87,0xCF07,0xCF8A,0xD00E,0xD094,0xD11C,0xD1A6,0xD231,
 
    0xD2BF,0xD34E,0xD3DF,0xD471,0xD505,0xD59B,0xD632,0xD6CB,
    0xD766,0xD802,0xD8A0,0xD93F,0xD9E0,0xDA82,0xDB26,0xDBCB,
    0xDC72,0xDD19,0xDDC3,0xDE6D,0xDF19,0xDFC6,0xE074,0xE124,
    0xE1D5,0xE287,0xE33A,0xE3EE,0xE4A3,0xE559,0xE611,0xE6C9,
    0xE782,0xE83C,0xE8F7,0xE9B4,0xEA70,0xEB2E,0xEBED,0xECAC,
    0xED6C,0xEE2D,0xEEEE,0xEFB0,0xF073,0xF136,0xF1FA,0xF2BF,
    0xF384,0xF449,0xF50F,0xF5D5,0xF69C,0xF763,0xF82A,0xF8F2,
    0xF9BA,0xFA82,0xFB4B,0xFC13,0xFCDC,0xFDA5,0xFE6E,0xFF37,
};
 
 
 
long expand(long i) {
 return i << 2;
}
 
void printFix(long i) {
     if ((i & 0x80000000) != 0) {
       printf("-");
        i = ~i+1;
      }
      printf("%ld.%04ld", i >> 16, 10000 * (unsigned long) (i & 0xffff) >> 16); 
}
 
long sin(int n) {
  return SIN[n & 0x01ff];
}
 
long cos(int n) {
    return sin(n + 0x0080);
}
 
void rotate(struct TVector *v, int n) {
    long x1 = v->x;
    long y1 = v->y;
    v->x = x1*cos(n) - y1*sin(n);
    v->y = x1*sin(n) + y1*cos(n);

}

//Metode til at reflektere bolden fra en side
void reflectBallSides(struct TVector *v, int n){
     long x1 = v->x;
	 long y1 = v->y;
	 v->x = -x1;  
     v->y = y1;
}
//Metode til at reflektere bolden fra toppen 
void reflectBallTop(struct TVector *v, int n){
	long x1 = v->x;
	long y1 = v->y;
	v->x = x1;
	v->y = y1;
}




// checking for ball collision with wall and ceiling
void checkWallCollision(struct Ball* ball) {

	// Venstre væg
	if (ball->x < (xmin) {
       reflectBallSides(ball.v);
		
	}
	// Højre væg
	else if (ball->x > (xmax)) {
		reflectBallSides(ball.v);
	}

	// Øverste væg
	if (ball->y < (ymax)) {
		reflectBallTop(ball.v);
	}

	else if (ball->y > (( tabskriterie))) { 
		// Der mistes et liv, hvis kriteriet opfyldes -- Tabskriteret er når y < y_striker_min
		//player.hp -- 
		
	}

}
