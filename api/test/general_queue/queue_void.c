#include "queue_void.h"

void initQueue(Queue *q){
	q->counter = 0;
	q->front = 0;
	q->rear = 0;
}

int isEmptyQueue(Queue q){
	return q.counter == 0;
}

int isFullQueue(Queue q){
	return q.counter == QUEUE_SIZE;
}

/*
void printElementQueue(Element_q *v){
	//edit according to element content
	printf("%d ", *v);
}

void printQueue(Queue q){
	int i, ptr;
	for(i = 1, ptr = q.front; i <= q.counter; i++){
        printElementQueue((Element_q *)q.arr[ptr]);
        ptr = (ptr + 1) % QUEUE_SIZE;
	}
	printf("\n");
}
*/

void *makeContentQueue(Element_q v){
    Element_q *newContent = malloc(sizeof(Element_q));
    *newContent = v;
    return newContent;
}

int enqueue(Queue *q, Element_q v){
	if(!isFullQueue((*q))){
		(*q).arr[(*q).rear] = makeContentQueue(v);
		(*q).rear = ((*q).rear + 1) % QUEUE_SIZE;
		(*q).counter++;
		return 1;
	}
	return 0;
}

Element_q *dequeue(Queue *q){
	Element_q *temp = NULL;
	if(!isEmptyQueue((*q))){
		temp = (Element_q *)q->arr[q->front];
		q->front = (q->front + 1) % QUEUE_SIZE;
		q->counter--;
	}
	return temp;
}
