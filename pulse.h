/*
Kanten des Würfels leuchten, in der mitte fährt ein block 2x2x2 hoch und runter
*/
void pulse (int tpulse)
{
    int ipulse;
    int a = 1;
    int b = 8;
	int ab = 1;
    for(ipulse=0;ipulse<tpulse;ipulse++)
    {
        f1 = 0;
        EC = 1;
        while(f1<96)
        {
            if(EC==a)
            {
				for (i=0;i<25;i++)
				{
					Ebene(EC);
					PORTC = 0b11111111;
					Reiheinit();
					PORTC = 0b10000001;
					ReiheNext();
					ReiheNext();
					PORTC = 0b10011001;
					ReiheNext();
					PORTC = 0b10011001;
					ReiheNext();
					PORTC = 0b10000001;
					ReiheNext();
					ReiheNext();
					PORTC = 0b11111111;
					ReiheNext();
					resetReihe();			
				}
				EC++;
				if (EC==9)
				{
					EC=1;
					f1++;
				}
            }
            else
            {
				for (i=0;i<25;i++)
				{
					Ebene(EC);
					PORTC = 0b11111111;
					Reiheinit();
					PORTC = 0b10000001;
					ReiheNext();
					ReiheNext();
					ReiheNext();
					ReiheNext();
					ReiheNext();
					ReiheNext();
					PORTC = 0b11111111;
					ReiheNext();
					resetReihe();
				}
				EC++;
				if (EC==9)
				{
					EC=1;
					f1++;
				}
            }
        }
		if (ab==1)
		{
			a++;
			b--;
			if (a==8)
			{
				ab=2;
			}
		}
		if (ab==2)
		{
			a--;
			b++;
			if (a==1)
			{
				ab=1;
			}
		}
    }
}
