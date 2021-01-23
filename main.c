#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char buf[8192];
	char nazwa[32];

	printf("Podaj nazwe pliku do przekonwertowania: (razem z rozszerzeniem)\n");
	if (scanf("%s", nazwa) != 1)
	{
		printf("Blad wczytywania nazwy pliku!\n");
		system("pause");
		return 1;
	}
	FILE* in = fopen(nazwa, "r");
	if (in == NULL)
	{
		printf("Blad! Nie istnieje taki plik!\n");
		system("pause");
		return 1;
	}

	FILE* out = fopen("wynik.txt", "w");
	if (out == NULL)
	{
		printf("Blad! Nie istnieje taki plik!\n");
		system("pause");
		return 1;
	}

	while (fgets(buf, 8192, in) != NULL)
	{
		int n = strlen(buf);
		fprintf(out,"printf(\"");
		for (int i = 0; i < n-1; i++)
		{
			fprintf(out,"%c", buf[i]);
		}
		fprintf(out,"\\n\");\n");
	}

	printf("Sukces! Plik zostal przekonwertowany do pliku wynik.txt!\n");

	system("pause");

	return 0;
}