#include <eZ8.h>
#include <sio.h>
#include "ansi.h"




#pragma interrupt
void timer0int();

//Initialiserer timeren
void setTimer(); 

//Initialiserer knapper
char readKey(); 

//Håndterer input, når timer skal bruges
void inputHandler(char present, char next, char x, char y); 


//Initialiserer display D1 (unit0), søjle 1 (den længste til venstre)
void setUpLDS();



void LEDinit();
void LEDUpdate(char lives);

char returnflag();

void set_flag0();


