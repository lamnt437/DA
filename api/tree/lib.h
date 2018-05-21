#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

typedef int Content_t;

typedef struct node{
  Content_t data;
  struct node *left, *right;
}NodeTree;

typedef NodeTree *TreeType;


typedef TreeType Element;

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



TreeType makeNodeTree(Content_t v);
TreeType insertNodeTree(TreeType root, NodeTree *newNode);
void preOrder(TreeType root);
void inOrder(TreeType root);
void postOrder(TreeType root);
void BFS(TreeType root);
