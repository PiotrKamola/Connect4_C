int czywygrana(int plansza[][Gkolumny], int kogotura)
{
    int wygrany = 0;
    //PIONOWO
    for(int i = 0; i <= Gwiersze-4; i++)
    {
        for(int j = 0; j < Gkolumny; j++)
        {
            if(plansza[i][j] == kogotura && plansza[i+1][j] == kogotura && plansza[i+2][j] == kogotura && plansza[i+3][j] == kogotura)
            {
                printf("\nWygrana PIONOWO\n");

                if(kogotura == 1)
                    wygrany = 1;
                if(kogotura == 2)
                    wygrany = 2;
            }
        }
    }
    //POZIOMO
    for(int i = 0; i < Gwiersze; i++)
    {
        for(int j = 0; j <= Gkolumny-4; j++)
        {
            if(plansza[i][j] == kogotura && plansza[i][j+1] == kogotura && plansza[i][j+2] == kogotura && plansza[i][j+3] == kogotura)
            {
                printf("\nWygrana POZIOMO\n");
                if(kogotura == 1)
                    wygrany = 1;
                else
                if(kogotura == 2)
                    wygrany = 2;
            }
        }
    }
    //SKOS "\"
    for(int i = 0; i <= Gwiersze-4; i++)
    {
        for(int j = 0; j <= Gkolumny-4; j++)
        {
            if(plansza[i][j] == kogotura && plansza[i+1][j+1] == kogotura && plansza[i+2][j+2] == kogotura && plansza[i+3][j+3] == kogotura)
            {
                printf("\nWygrana SKOS\n");
                if(kogotura == 1)
                    wygrany = 1;
                else
                if(kogotura == 2)
                    wygrany = 2;
            }
        }
    }
    //SKOS "/"
    for(int i = Gwiersze-1; i > Gwiersze-4; i--)
    {
        for(int j = 0; j <= Gkolumny-4; j++)
        {
            if(plansza[i][j] == kogotura && plansza[i-1][j+1] == kogotura && plansza[i-2][j+2] == kogotura && plansza[i-3][j+3] == kogotura)
            {
                printf("\nWygrana SKOS\n");
                if(kogotura == 1)
                    wygrany = 1;
                else
                if(kogotura == 2)
                    wygrany = 2;
            }
        }
    }
    return wygrany;
}
