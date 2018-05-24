#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 100

/*typedef Element_q*/

typedef int Element_q;

typedef struct q{
    int counter;
    int front;
    int rear;
    Element_q arr[QUEUE_SIZE];
}Queue;



void initQueue(Queue *q);	//NEED TO INITIALIZE QUEUE

int isFullQueue(Queue q);
/*
void printElementQueue(Element_q v);

void printQueue(Queue q);
*/
int enqueue(Queue *q, Element_q v);

Element_q dequeue(Queue *q);