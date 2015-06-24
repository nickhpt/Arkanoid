#include <eZ8.h>
#include <sio.h>
#include "inputfix.h"
#include "ansi.h"
#include "heartarray.h"


char flag = 0;

//Interrupt for timeren
 #pragma interrupt
void timer0int() {
	flag = 1;
} 

char returnflag() {
 return flag;
}
void set_flag0() {
	flag = 0;
}

//Initialiserer timeren6
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



void LEDinit() {
     
    //Sætter hele port E til output
    PEADDR = 0x01;
    PECTL = 0x00;
    PEADDR = 0x00;
     
    //Sætter hele port G til output
    PGADDR = 0x01;
    PGCTL = 0x00;
    PGADDR = 0x00;
 
    //Timer0 sættes
    DI();
    // TEN = 0, TPOL = 0, PRES = 111, TMODE = 001 
    T0CTL = 0x039;
    // Den højeste nibbel sættes til 0
    T0H = 0x000;
    // Den laveste nibbel sættes til 1
    T0L = 0x001;
    //Dette er reload values, som er opdelt i høj og lav
    T0RH = 0x00;
    T0RL = 0x48;
     
    // Interrupt prioriteten sættes
    IRQ0ENH &= ~0x20; //Low priority 
    IRQ0ENL |= 0x20;
   SET_VECTOR(TIMER0,timer0int);
     
    //Timeren enables
    T0CTL |= 0x80;
 
    //Interrput enables
    EI();   
}

void LEDUpdate(char lives) {
    static char digit, column, scroll=0;
    if(flag == 1){
          PEOUT = 0x1F & ~(1 << (4-column)); 
     	  PGOUT = *(&heartarray1[0] + column);
 
        switch(digit){
            case 0:
                PEOUT &= ~(1 << 7);
                PEOUT |=  (1 << 7);
                PEOUT &= ~(1 << 7);
                break;
            case 1:
                PGOUT &= ~(1 << 7);
                PGOUT |=  (1 << 7);
                PGOUT &= ~(1 << 7);
                break;
            case 2:
                PEOUT &= ~(1 << 5);
                PEOUT |=  (1 << 5);
                PEOUT &= ~(1 << 5);
                break;
            case 3:
                PEOUT &= ~(1 << 6);
                PEOUT |=  (1 << 6);
                PEOUT &= ~(1 << 6);
                break; 
        }
     
     
        if(++digit == lives){
            digit = 0;
            if(++column == 5){
                column = 0;
            }
        }
        flag = 0;
    }
}
