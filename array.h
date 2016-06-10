// Zuweisung des Array's zu den funktionen.. haha noch nie mit array's gearbeitet

uint8_t cube[8][8] = 
{
	{Ebene(1),Ebene(2), Ebene(3), Ebene(4), Ebene(5) ,Ebene(6), Ebene(7), Ebene(8)}  //Ebene(1) startet die Funktion um auf ebene 1 Zu schalten
	,
	{Reihe(1),Reihe(2),Reihe(3), Reihe(4), Reihe(5), Reihe(6), Reihe(7), Reihe(8)} //Schaltet in die richtige reihe
};


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