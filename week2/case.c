#include <stdio.h>
#include <ctype.h>

int main()
{
	FILE *r =  fopen("lab1.txt", "r");
	FILE *w = fopen("case.txt", "w+");
	char c;

	while((c = fgetc(r)) != EOF){
		if(islower(c))
			c = toupper(c);
		else
			if(isupper(c))
				c = tolower(c);

		fprintf(w, "%c", c);
	}

	fclose(r);
	fclose(w);

	return 0;
}