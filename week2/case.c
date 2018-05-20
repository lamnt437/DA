#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  if(argc != 3){
    puts("Wrong number of arguments!");
    return 1;
  }
	FILE *r =  fopen(argv[1], "r");
	if(r == NULL){
	  puts("Input file doesn't exist!");
	  return 2;
	}
	FILE *w = fopen(argv[2], "w+");
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
