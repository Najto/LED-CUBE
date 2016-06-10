/*
Kanten des Würfels läuchten, in der mitte fährt ein block hoch und runter
*/
void loadanim (int tpulse)
{
    int ipulse;
    int a = 1;
	int ab = 1;
    for(ipulse=0;ipulse<tpulse;ipulse++)
    {
        f1 = 0;
        EC = 1;
        while(f1<96)
        {
            if(EC==a)
            {
                Ebene(EC);
					PORTC = 0b00000000;
					Reiheinit();
					ReiheNext();
					ReiheNext();
					ReiheNext();
					ReiheNext();
					ReiheNext();
					ReiheNext();
					ReiheNext();
					warte(Zeit2);
					resetReihe();
                EC++;
                if (EC==9)
                {
                    EC=1;
                    f1++;
                }
            }
            else
            {
                Ebene(EC);
                PORTC = 0b11111111;
                Reiheinit();
                ReiheNext();
                ReiheNext();
                ReiheNext();
                ReiheNext();
                ReiheNext();
                ReiheNext();
                warte(Zeit1);
                resetReihe();
                EC++;
                if (EC==9)
                {
                    EC=1;
                    f1++;
                }
            }
        }
        f1 = 0;
        EC = 1;
		if (ab==1)
		{
			a++;
			if (a==7)
			{
				ab=2;
			}
		}
		if (ab==2)
		{
			a--;
			if (a==1)
			{
				ab=1;
			}
		}
    }
}
