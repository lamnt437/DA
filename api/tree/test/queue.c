#include "queue.h"
//edit Element typedef in "queue.h"


int isEmpty(Queue q){
	return q.counter == 0;
}

int isFull(Queue q){
	return q.counter == QUEUE_SIZE;
}

void printElement(Element v){
	//edit according to element content
	printf("%c ", v);//
}

void printQueue(Queue q){
	int i, ptr;
	for(i = 1, ptr = q.front; i <= q.counter; i++, ptr++){
		printElement(q.arr[ptr]);
	}
	printf("\n");
}

int enqueue(Queue *q, Element v){
	if(!isFull((*q))){
		(*q).arr[(*q).rear] = v;
		(*q).rear = ((*q).rear + 1) %	QUEUE_SIZE;
		(*q).counter++;
		return 1;
	}
	return 0;
}

Element dequeue(Queue *q){
	//edit temp value
	Element temp = EOF;//
	if(!isEmpty((*q))){
		temp = (*q).arr[(*q).front];
		(*q).front = ((*q).front + 1) % QUEUE_SIZE;
		(*q).counter--;
	}
	return temp;
}