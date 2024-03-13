#include <stdio.h> 

void CzyszczenieEkranu()
{
	#ifdef _WIN32 
		system("cls");
	#elif __linux__ 
		system("clear");
	#else 
		printf("Problem z czyszczeniem ekranu (dzia³a tylko na systemie Linux i Windows).\n");
	#endif
}