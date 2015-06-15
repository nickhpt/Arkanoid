#include <eZ8.h>
#include <sio.h>
#include "inputfix.h"
#include "ansi.h"

char flag = 0;

//Interrupt for timeren
 #pragma interrupt
void timer0int() {
	flag++;
} 

//Initialiserer timeren
void setTimer() {
	DI();
	// TEN = 0, TPOL = 0, PRES = 111, TMODE = 001 
	T0CTL = 0x039;
	// Den højeste nibbel sættes til 0
	T0H = 0x000;
	// Den laveste nibbel sættes til 1
	T0L = 0x001;
	//Dette er reload values, som er opdelt i høj og lav
	T0RH = 0x05;
	T0RL = 0xA0;
	
	// Interrupt prioriteten sættes
    IRQ0ENH |= 0x20; //High priority 
	IRQ0ENL |= 0x20;
	SET_VECTOR(TIMER0,timer0int);
	
	//Timeren enables
	T0CTL |= 0x80;

	//Interrput enables
	EI();
}

//Initialiserer knapper
char readKey() {
	unsigned char PD3, PF6, PF7;

	PF7 = ~PFIN & 1<<7;
	PF6 = ~PFIN & 1<<6;
	PD3 = ~PDIN & 1<<3;

	return (PD3 >> 1) | (PF6 >> 5) | (PF7 >> 7);
}

//Håndterer input, når timer skal bruges
/* void inputHandler(char present, char next, char x, char y) {
	if(present < next) {
		if(next & 0x01) {
			if(T0CTL & 0x80) {
				T0CTL &= ~0x80;
			} else {
				T0CTL |= 0x80;
			}
		}
		if (next & 0x02) {
			gotoxy(x,y);
			printf("%d:%02d:%02d.%02d",time.h,time.m,time.s,time.hs);
		}
		if (next & 0x04) {
			gotoxy(x+1,y);
			printf("%d:%02d:%02d.%02d",time.h,time.m,time.s,time.hs);
		}
		if (next == 0x06) {
			T0CTL &= ~0x80;
			time.hs = 0;
			time.s = 0;
			time.m = 0;
			time.h = 0;
			gotoxy(x-1,y);
			printf("%d:%02d:%02d.--",time.h,time.m,time.s);
			gotoxy(x+1,y);
			printf("-:--:--.--");
			gotoxy(x,y);
			printf("-:--:--.--");
	    }
	}
} */

//Kan bruges til at finde rising edge
char detectPush(char present, char next) {
	if ( (((present || next) && (!present || !next))) && next)
        return 1;
	else 
		return 0;
}

//Initialiserer display D1 (unit0), søjle 1 (den længste til venstre)
void setUpLDS() {

	//Sætter hele port E til output
	PEADDR = 0x01;
	PECTL = 0x00;
	PEADDR = 0x00;
	
	//Sætter hele port G til output
	PGADDR = 0x01;
	PGCTL = 0x00;
	PGADDR = 0x00;
	
	//Sætter port E til 00001111 og
	//port G til 00000000
	PEOUT = 0x0F;
	PGOUT = 0x00;

	//Laver klokkerne, dvs. E: 00001111 -> 11101111 -> 00001111 og
	//G: 00000000 -> 10000000 -> 00000000
	PEOUT |= 0xE0;
	PGOUT |= 0x80;
	PEOUT &= ~0xE0;
	PGOUT &= ~0x80;	
}

//Viser ouput på den ene søjle på D1 displayet
void flashCounter(unsigned char counter) {
	PGOUT &= ~0x7F;
    PGOUT |= counter & 0x7F;
	PEOUT |= 0x80;
	PEOUT &= ~0x80;
}

