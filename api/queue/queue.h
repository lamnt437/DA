#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define QUEUE_SIZE 100

typedef char Element_q;

typedef struct q{
	int counter;
	int front;
	int rear;
	Element_q arr[QUEUE_SIZE];
}Queue;

//need initialize q value

int isEmpty_q(Queue q);
int isFull(Queue q);
void printElement(Element_q v);
void printQueue(Queue q);
int enqueue(Queue *q, Element_q v);
Element_q dequeue(Queue *q);
