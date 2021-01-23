#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char buf[8192];
	char znak = '\\';
	char znak2 = 'n';
	char nazwa[32];

	printf("nazwa pliku do przekonwertowania:\n");
	scanf("%s", nazwa);

	FILE* in = fopen(nazwa, "r");

	FILE* out = fopen("wynik.txt", "w");

	while (fgets(buf, 8192, in) != NULL)
	{
		int n = strlen(buf);
		fprintf(out,"printf(\"");
		for (int i = 0; i < n-1; i++)
		{
			fprintf(out,"%c", buf[i]);
		}
		fprintf(out,"%c%c\");\n", znak, znak2);
		//fprintf(out, "printf(\"%s%c%c\");\n", buf, znak, znak2);
	}

	system("pause");
	return 0;
}