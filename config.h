/*
CUBE config
 */
#include <avr/io.h>
    int Zeit1 = 100;
    int Zeit2 = 1000;
    int countE = 0;
	int countR = 0;
    int i = 0;
    int EC=1;   //zum schieben der ebenen in schleifen
	int RC=1;	//schieben der Reihen
    int f1;     //zähler für funktionen
	int tPWM = 500;
	int ton = 0;
	int set,set2,set3,set4,set5,set6,set7,set8,countdimm;
	uint8_t LED = 0;

void warte(int t)
{
    int iwarte;
    for(iwarte=0;iwarte<t;iwarte++);
}
void Ebeneinit() //Initialisiert die erste Ebene
{
    PORTA = PORTA | 0b00010000;//PORT A4 auf 1 (gibt das high signal, welches mit clock auf A5 geschoben wird)
    PORTA = PORTA | 0b00100000;//Port A5 auf 1 (clock)
    PORTA = PORTA & 0b11011111;//Port A5 auf 0
    PORTA = PORTA & 0b11101111;//PORT A4 auf 0 *

}
void EbeneNext() //schiebt eine Ebene weiter
{
    PORTA = PORTA | 0b00100000;//Port A5 auf 1 (clock)
    PORTA = PORTA & 0b11011111;//Port A5 auf 0
}
void Ebene(int te) //schaltet bis zu der gewünschten ebene
{ //PORTC = 0;  //nur für array gedöns!
    if((te!=countE)||(countE==0))
    {
        if(countE>te)
        {
            PORTA = 0b00000100;//Ebenen shift register reset
            PORTA = 0b01000100;//Ebenen shift register reset ende
            countE=1;
        }
        if((countE<=1)||(countE==8)) //Startet mit der ersten Ebene
        {
            countE=1;
            Ebeneinit();
                while(countE<te)    //Schaltet die Ebenen durch, bis Ebene te erreicht ist
                {
                    EbeneNext();
                    countE++;
                }
        }
        else                        //Schaltet die Ebenen durch, da
        {
            while(countE<te)
            {
                EbeneNext();
                countE++;
            }
        }
    }
}
void ReiheNext() //reihe weiter schalten
{
    PORTA = PORTA | 0b00001000;//Port A3 auf 1
    PORTA = PORTA & 0b11110111;//Port A3 auf 0
}
void Reiheinit() //erste reihe
{
    PORTA = PORTA | 0b00000010;//Port A1 auf 1
    ReiheNext();
    PORTA = PORTA & 0b11111101;//Port A1 auf 0
}
void resetReihe() //setzt Die flipflops zurück, es werden alle reihen durch geschaltet und nullen in die flipflops gegeben
{
    //PORTA = 0b01000000;//shift register reset
    PORTA = 0b01000100;//shift register reset
    PORTC = 0b00000000;//LEDs Aus Schalten
    int iresetReihe=0;
	Reiheinit();	//Testweise hinzugefügt
    while(iresetReihe<7)
    {
        ReiheNext();
        iresetReihe++;
    }
}

// Funktioniert so noch nicht?!
void Reihe(int tr) //schaltet bis zu der gewünschten Reihe
{
	if((tr!=countR)||(countR==0))
	{
		if(countR>tr)
		{
			PORTA = 0b01000100; //shift reset trigger, wird in den anderen funktionen beendet
			countR=1;
		}
		if((countR<=1)||(countR==8)) //Startet mit der ersten Reihe
		{
			countR=1;
			Reiheinit();
			while(countR<tr)    //Schaltet die Ebenen durch, bis Ebene te erreicht ist
			{
				ReiheNext();
				countR++;
			}
		}
		else                        //Schaltet die Ebenen durch, da
		{
			while(countR<tr)
			{
				ReiheNext();
				countR++;
			}
		}
	}
	PORTC=LED;
}