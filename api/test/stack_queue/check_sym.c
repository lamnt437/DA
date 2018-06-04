#include "stack.h"
#include "queue.h"

int check_sym(FILE *read);

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

	int status = check_sym(read);
	printf("Status: %d\n", status);

	fclose(read);

	return 0;
}

int check_sym(FILE *read){
	Stack s1 = NULL;
	Queue q1; 
	q1.counter = 0;
	q1.front = 0;
	q1.rear = 0;

	Content_s v, vs, vq;

	while((v = fgetc(read)) != EOF){
		if(v != '\n'){
			enqueue(&q1, v);
			push(&s1, v);
		}
	}

	while(!isEmpty_s(s1) && !isEmpty_q(q1)){
		vs = pop(&s1);
		vq = dequeue(&q1);
		if(vs != vq)
			return 0;
	}
	if(isEmpty_s(s1) && isEmpty_q(q1))
		return 1;
	return 0;
}
