/*
 * LED_CUBE.c
 *
 * Created: 29.09.2013 12:10:48
 *  Author: Sven
 */ 
#include <avr/io.h>
#include "config.h"
#include "pulse.h"
#include "dimmer.c"
//#include "array.h"


int main(void)
{

    // Insert code
  DDRA = 0b11111111;
  DDRC = 0b11111111;

    warte(Zeit1);
    PORTA = 0b01000100;//Resets auf 1

    while(1)
    {
       dimmer();
        warte(Zeit2);
        pulse(22);
		warte(Zeit2);
    return 0;
	}
}

