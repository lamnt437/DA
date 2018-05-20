#include <stdio.h>
#define MAX 10

int main()
{
	FILE *r = fopen("lab1.txt", "r");
	FILE *w = fopen("line.txt", "w+");

	char s[MAX];

	while((fgets(s, MAX, r)) != NULL)
	{
		fprintf(w, "%s", s);
	}

	fclose(r);
	fclose(w);

	return 0;
}