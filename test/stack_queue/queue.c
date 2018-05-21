#include "queue.h"
//edit Element typedef in "queue.h"


int isEmpty_q(Queue q){
	return q.counter == 0;
}

int isFull(Queue q){
	return q.counter == QUEUE_SIZE;
}

void printElement(Element_q v){
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

int enqueue(Queue *q, Element_q v){
	if(!isFull((*q))){
		(*q).arr[(*q).rear] = v;
		(*q).rear = ((*q).rear + 1) %	QUEUE_SIZE;
		(*q).counter++;
		return 1;
	}
	return 0;
}

Element_q dequeue(Queue *q){
	//edit temp value
	Element_q temp = EOF;//
	if(!isEmpty_q((*q))){
		temp = (*q).arr[(*q).front];
		(*q).front = ((*q).front + 1) % QUEUE_SIZE;
		(*q).counter--;
	}
	return temp;
}
