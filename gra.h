int NowaGra(int plansza[][Gkolumny])
{
	int kogotura = 1; // 1 - gracz 1, 2 = gracz 2
	int wybranakolumna = 0;
	int kolumnapelna = 0;
	int maxruchow = 42; // Potrzebne do "break'a"
	int zwyciezca = 0;
    //system("clear");
	system("cls");
    pokaz(plansza);
    char pomocnicza[256];     // Do zamiany na int
    while(maxruchow > 0)
    {
        while(wybranakolumna < 1 || wybranakolumna > Gkolumny)
        {
            printf("\n");
            if(kogotura == 1)
                printf("\t\tTURA GRACZA %d.\n", kogotura);
            else
            if(kogotura == 2)
                printf("\t\tTURA GRACZA %d.\n", kogotura);
            printf("\tPodaj numer kolumny i wcisnij ENTER:\n");

            fgets (pomocnicza, 256, stdin);
            wybranakolumna = atoi(pomocnicza);
            if(wybranakolumna < 1 || wybranakolumna > Gkolumny)
            {
                //system("clear");
				system("cls");
				printf("\n\tPodano niewlasciwa kolumne!\n\n");
                pokaz(plansza);
            }
            else
            //system("clear");
			system("cls");
        }
		int i = Gwiersze-1;
		if(plansza[0][wybranakolumna-1]==0)
		{
			int zmienilem = 0;
			while(zmienilem==0)
			{
				if(plansza[i][wybranakolumna-1] == 0)
				{
					plansza[i][wybranakolumna-1] = kogotura;
					zmienilem = 1;
					maxruchow--;
				}
			i--;
			}
		}
		else
		{
			printf("\n\t\tKolumna pelna.\n\n");
			kolumnapelna = 1;
		}
		zwyciezca = czywygrana(plansza, kogotura);
		if(zwyciezca == 1)
			maxruchow = 0;
		else
		if(zwyciezca == 2)
			maxruchow = 0;
		pokaz(plansza);
		printf("\n\t\tGracz %d wybral kolumne %d\n",kogotura, wybranakolumna);
		if(kogotura == 1 && kolumnapelna == 0)
			kogotura = 2;
		else
		if(kogotura == 2 && kolumnapelna == 0)
			kogotura = 1;
		kolumnapelna = 0;
		wybranakolumna = 0;
	}
	return zwyciezca;
}
