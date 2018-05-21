
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

typedef int Element;

typedef struct q{
	int counter;
	int front;
	int rear;
	void *arr[QUEUE_SIZE];
}Queue;

int isEmpty(Queue q);
int isFull(Queue q);
void printElement(Element *v);
void printQueue(Queue q);
void *makeContent(Element v);
int enqueue(Queue *q, Element v);
Element *dequeue(Queue *q);
