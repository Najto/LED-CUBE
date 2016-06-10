void LEDan()
{
	int tan;
	for(tan=0;tan<ton;tan++)
	{
		Ebene(EC);
		PORTC = 255;
		Reiheinit();
		ReiheNext();
		ReiheNext();
		ReiheNext();
		PORTC = 0;
		ReiheNext();
		ReiheNext();
		ReiheNext();
		ReiheNext();
		warte(Zeit1);
		resetReihe();
		EC++;
		if(EC==9)
		{
			EC = 1;
		}
	}
}
void LEDaus()
{
	int tan;
	for(tan=0;tan<tPWM-ton;tan++)
	{
		Ebene(EC);
		PORTC = 0;
		Reiheinit();
		ReiheNext();
		ReiheNext();
		ReiheNext();
		PORTC = 255;
		ReiheNext();
		ReiheNext();
		ReiheNext();
		ReiheNext();
		warte(Zeit1);
		resetReihe();
		EC++;
		if(EC==9)
		{
			EC = 1;
		}
	}
}
void wartedimmer(int idimmer)
{
	while(idimmer>0)
	{
		idimmer--;
	}
}
void dimmer()
{
	while(tPWM>ton)
	{
		LEDan();
		LEDaus();
		ton=ton+5;
		
	}
	set2--;
	while(ton>0)
	{
		LEDan();
		LEDaus();
		ton=ton-5;
	}
	set++;
	if(set2==0)
	{
		set2=255;
	}
	if (set==255)
	{
		set=1;
	}
}
