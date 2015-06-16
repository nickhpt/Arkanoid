#include <eZ8.h>
#include <sio.h>
#include "ansi.h"



struct TTime {
	char h, m, s, hs; 
};

#pragma interrupt
void timer0int();

//Initialiserer timeren
void setTimer(); 

//Initialiserer knapper
char readKey(); 

//Håndterer input, når timer skal bruges
void inputHandler(char present, char next, char x, char y); 

//Kan bruges til at finde rising edge
char detectPush(char present, char next); 

//Initialiserer display D1 (unit0), søjle 1 (den længste til venstre)
void setUpLDS();

//Viser ouput på den ene søjle på D1 displayet
void flashCounter(unsigned char counter);

char returnflag();

void set_flag0();


