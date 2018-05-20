#include "stack.h"

int main(int argc, char *argv[]){
	if(argc != 2){
		puts("Wrong number of arguments!");
		return 1;
	}
	FILE *read = fopen(argv[1], "r");
	if(read == NULL){
		puts("Input file doesn't exist!");
		return 2;
	}

	List stack = NULL;
	char c;
	while((c = fgetc(read)) != EOF){
		push(&stack, c);
	}
	fclose(read);

	printList(stack);

	while(!isEmpty(stack)){
		c = pop(&stack);
	}
	c = pop(&stack);
	if(c == EOF)
		printf("\n1\n");

	return 0;
}