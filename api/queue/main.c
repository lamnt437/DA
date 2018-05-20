#include "queue.h"

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

	Queue first;
	char c;

	while((c = fgetc(read)) != EOF){
		enqueue(&first, c);
	}
	fclose(read);

	printQueue(first);
	printf("dequeue:\n\n");
	while(!isEmpty(first)){
		c = dequeue(&first);
		printElement(c);
	}

	c = dequeue(&first);
	printf("\n\n%d\n", c == EOF);

	return 0;
}