void pokaz(int wydrykplanszy[][Gkolumny]) //drukowanie planszy gry
{
	for(int i = 0; i < Gwiersze; i++)
    {
		printf("\t\t");
        for(int j = 0; j < Gkolumny; j++)
        {
			printf("%d ", wydrykplanszy[i][j]);
        }
        printf("\n");
	}
    printf("\n\t\t");
    for(int i = 1; i < Gkolumny+1; i++)
		printf("%d ", i);
}
