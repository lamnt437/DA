#include <stdio.h>

int main()
{
	FILE *w = fopen("lab1.txt", "w+");
	fprintf(w, "%s", "lsafjalc rajlfc la flaorieojao! ()ajfla");
	fclose(w);

	w = fopen("lab1w.txt", "w+");
	FILE *r = fopen("lab1.txt", "r");

	char c;

	while((c = fgetc(r)) != EOF){
		fputc(c, w);
	}

	fclose(w);
	fclose(r);

	return 0;
}