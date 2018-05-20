#include <stdio.h>
#define MAX 10

int main(int argc, char *argv[])
{
	FILE *r = fopen(argv[1], "r");
	FILE *w = fopen(argv[2], "w+");

	char s[MAX];

	while((fgets(s, MAX, r)) != NULL)
	{
		fprintf(w, "%s", s);
	}

	fclose(r);
	fclose(w);

	return 0;
}
