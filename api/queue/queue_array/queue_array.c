#include "queue_array.h"

void initQueue(Queue *q){   //NEED TO INITIALIZE QUEUE
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


void printElementQueue(Element_q v){
    printf("%d ", v);
}

void printQueue(Queue q){
    int i, j = q.front;
    for(int i = 0; i < q.counter; i++){
        printElementQueue(q.arr[j]);
        j = (j + 1) % QUEUE_SIZE;
    }
    printf("\n");
}


int enqueue(Queue *q, Element_q v){
    if(!isFullQueue(*q)){
        (*q).arr[q->rear] = v;
        q->rear = (q->rear + 1) % QUEUE_SIZE;
        q->counter++;
        return 1;
    }
    return 0;
}

Element_q dequeue(Queue *q){
    Element_q temp = -9999;
    if(!isEmptyQueue(*q)){
        temp = (*q).arr[q->front];
        q->front = (q->front + 1) % QUEUE_SIZE;
        q->counter--;
    }
    return temp;
}