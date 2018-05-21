#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef int Element_s;

typedef struct stack{
    int top;
    void *arr[STACK_SIZE];
}Stack;



void initStack(Stack *s);

int isEmptyStack(Stack s);

int isFullStack(Stack s);


void printElementStack(Element_s *ptr);

void printStack(Stack s);

void *makeContent(Element_s v);

int push(Stack *s, Element_s v);

Element_s *pop(Stack *s);