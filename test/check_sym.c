#include "stack.h"
#include "queue.h"

int check_sym(Stack *s, Queue *q){
	Content_s vs, vq;
	while(*s != NULL && !isEmpty_q(*q)){
		vs = pop(s);
		vq = dequeue(q);
		printf("vs: %c - vq: %c\n", vs, vq);
		if(vs != vq)
			return 0;
	}
	printf("stack: %d - queue: %d\n", *s == NULL, isEmpty_q(*q));
	printf("queue counter: %d\n", q->counter);
	printf("last: %d", dequeue(q));
	if(*s == NULL && isEmpty_q(*q))
		return 1;
	return 0;
}

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

	Content_s v;
	Stack s1 = NULL;
	Queue q1;
	q1.counter = 0;
	q1.rear = 0;
	q1.front = 0;
	
	/*
	while((v = fgetc(read)) != EOF){
		if(v != '\n'){
			push(&s1, v);
			enqueue(&q1, v);
		}
	}
*/
	fclose(read);

	char string[] = "abcdcba";
	int ptr = 0;
	while(string[ptr] != '\0'){
		enqueue(&q1, string[ptr]);
		push(&s1, string[ptr]);
		ptr++;
	}	
	int status = check_sym(&s1, &q1);
	printf("Status: %d\n", status);

	return 0;
}
