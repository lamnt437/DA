#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

typedef int Element_q;

typedef struct q{
	int counter;
	int front;
	int rear;
	void *arr[QUEUE_SIZE];
}Queue;

void initQueue(Queue *q);
int isEmptyQueue(Queue q);
int isFullQueue(Queue q);
/*
void printElement(Element_q *v);
void printQueue(Queue q);
*/
void *makeContentQueue(Element_q v);
int enqueue(Queue *q, Element_q v);
Element_q *dequeue(Queue *q);
