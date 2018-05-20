#include <stdio.h>

int main(int argc, char *argv[])
{
	int line_count1, line_count2;
	int last1, last2;
	int count, name;
	char c1, c2;

	//OPEN FILE
	if(argc != 3){
		puts("Wrong number of arguments!");
		return 1;
	}

	FILE *f1 = fopen(argv[1], "r");
	FILE *f2 = fopen(argv[2], "r");

	if(f1 == NULL || f2 == NULL){
		puts("Files don't exist!");
		return 2;
	}

	//COUNT LINE //COUNT LAST LINE CHARACTER
	line_count1 = count_line(f1, &last1);
	printf("line: %d\nlast: %d\n", line_count1, last1);

	//CHECK LINE BY LINE

	return 0;
}

int count_line(FILE *f, int *last)	//Count lines and number of character in the last line
{
	int line, n;
	char c = fgetc(f);
	if(c == EOF){
		line = 0;
		n = 0;
	}
	else{
		line = 1;
		n = 1;

		while((c = fgetc(f)) != EOF){
			if(c == '\n'){
				line++;
				n = 0;
			}
			else{
				n++;
			}

		}
	}

	*last = n;

	return line;
}