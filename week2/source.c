#include <stdio.h>

int main()
{
	FILE *r = fopen("case.c", "r");
	FILE *w = fopen("source.txt", "w+");

	char c;
	int i = 1;
	fprintf(w, "%.2d", i);
	i++;
	
	while((c = fgetc(r)) != EOF){

		if(c == '\n'){
			fprintf(w, "%c%.2d", c, i);
			i++;
		}
		else
			fprintf(w, "%c", c);
	}

	fclose(r);
	fclose(w);

	return 0;
}