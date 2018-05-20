#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define QUEUE_SIZE 100

typedef char Element;

typedef struct q{
	int counter;
	int front;
	int rear;
	Element arr[QUEUE_SIZE];
}Queue;

int isEmpty(Queue q);
int isFull(Queue q);
void printElement(Element v);
void printQueue(Queue q);
int enqueue(Queue *q, Element v);
Element dequeue(Queue *q);