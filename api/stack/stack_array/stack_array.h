#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

/*typedef Element_s*/

typedef int Element_s;

typedef struct stack{
    int top;
    Element_s arr[STACK_SIZE];
}Stack;



void initStack(Stack *s);

int isEmptyStack(Stack s);

int isFullStack(Stack s);

void printElementStack(Element_s v);

void printStack(Stack s);

int push(Stack *s, Element_s v);

Element_s pop(Stack *s);