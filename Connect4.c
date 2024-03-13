#include <stdio.h>
#include <stdlib.h>
#include <string.h> //dla memset, (zerowanie tablicy)
#include <time.h> //dla aktualnej daty

#define Gkolumny 7 //globalne kolumny (Wystarczy zmieniæ do powiekszenia planszy gry)
#define Gwiersze 6 //globalne wiersze (Wystarczy zmieniæ do powiekszenia planszy gry)

#include "funkcje.h" //Implementacja funkcji
#include "gra.h" //Aktualna gra
#include "pokaz.h" //Wyswietlenie planszy
#include "SprawdzenieWygranego.h" //Sprawdzenie czy jest wygrany
#include "CzyszczenieBufora.h" //Czyszcznie bufora
#include "CzyszczenieEkranu.h" //Czyszcznie ekranu

struct gracz
{
   char imie[10];
   char nick[10];
};
void main()
{	
	struct gracz Gracz1;
	struct gracz Gracz2;
	printf("Podaj imie pierwszego gracza.(max 10 znakow)\n");
		scanf("%9s", Gracz1.imie);
		CzyszczenieBufora();
	printf("Podaj nick pierwszego gracza.(max 10 znakow)\n");
		scanf("%9s", Gracz1.nick);
		CzyszczenieBufora();
	printf("Podaj imie drugiego gracza.(max 10 znakow)\n");
		scanf("%9s", Gracz2.imie);
		CzyszczenieBufora();
	printf("Podaj nick drugiego gracza.(max 10 znakow)\n");
		scanf("%9s", Gracz2.nick);
		CzyszczenieBufora();		
    int plansza[Gwiersze][Gkolumny] = {}; // Uzupelnenie tablicy zerami
    int WyborCoRobic=1;
    char PomocniczaDoWyboru[256];
	CzyszczenieEkranu();
    while(WyborCoRobic != 4)
	{
		printf("Co chcesz zrobic?\n 1. Zasady gry.\n 2. Nowa gra.\n 3. Zobacz wyniki.\n 4. Wyjscie.\n");
		fgets (PomocniczaDoWyboru, 256, stdin); //Aby switcha nie zapetlic na literce.
        WyborCoRobic = atoi(PomocniczaDoWyboru);
        switch(WyborCoRobic)
        {
			case 1:
            {
				char buforinstrukcji[256];
				CzyszczenieEkranu();
                FILE *instrukcja = fopen("instrukcja", "r");
                if(instrukcja == NULL)
					printf("Nie udalo sie znalezc instrukcji.\n");
				else
				{
					while(fgets(buforinstrukcji, 256, instrukcja))
						printf("%s", buforinstrukcji);
					printf("\n");
					fclose(instrukcja);
                }
                break;
            }
            case 2:
            {
                int zwyciezca = NowaGra(plansza);
				time_t data;
				struct tm * datagry;
				time(&data);
                datagry = localtime(&data);
				FILE * wyniki = fopen("wyniki", "a");
				if(wyniki)
				{
					if(zwyciezca == 0)
					{
						fprintf(wyniki, "Remis miedzy graczem %s(%s) a %s(%s) byl dnia %s\n",Gracz1.imie, Gracz1.nick, Gracz2.imie, Gracz2.nick, asctime(datagry));
						fclose(wyniki);
						printf("\n\tRemis\n");
					}
					if(zwyciezca == 1)
					{
						fprintf(wyniki, "Gracz 1, %s(%s) wygral dnia %s\n", Gracz1.imie, Gracz1.nick, asctime(datagry));
						fclose(wyniki);
						printf("\n\tWygral gracz 1, %s(%s)!\n", Gracz1.imie, Gracz1.nick);
					}
					if(zwyciezca == 2)
					{
						fprintf(wyniki, "Gracz 2, %s(%s) wygral dnia %s\n", Gracz2.imie, Gracz2.nick,asctime(datagry));
						fclose(wyniki);
						printf("\n\tWygral gracz 1, %s(%s)!\n", Gracz2.imie, Gracz2.nick);
					}
				}
				else 
					printf("Nie udalo sie wczytac pliku.");
                
                memset(plansza, 0, Gkolumny*Gwiersze*sizeof(int)); //Ponowne zapelnienie tablicy zerami aby ponownie mozna bylo zaczac gre.
                printf("Wcisnij Enter aby kontynuowac.");
					getchar();
				CzyszczenieEkranu();
                break;
            }
            case 3:
            {
				char buforwynikow[256];
				CzyszczenieEkranu();
                FILE *wyniki = fopen("wyniki", "r");
                if(wyniki == NULL)
					printf("Nie bylo jeszcze zadnej gry.\n");
				else
				{
					while(fgets(buforwynikow, 256, wyniki))
						printf("%s", buforwynikow);
					printf("\n");
					fclose(wyniki);
                }
                break;
            }
            default:
            {
				CzyszczenieEkranu();
                printf("Podano niewlasciwa wartosc.\n");
                break;
            }
        }
    }
	CzyszczenieEkranu();
}
