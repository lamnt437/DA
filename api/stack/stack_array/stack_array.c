#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

/*typedef Element_s*/

typedef int Element_s;

typedef struct stack{
    int top;
    Element_s arr[STACK_SIZE];
}Stack;

void initStack(Stack *s){   //NEED TO INITIALIZE STACK
    s->top = 0;
}

int isEmptyStack(Stack s){
    return s.top == 0;
}

int isFullStack(Stack s){
    return s.top == STACK_SIZE;
}

void printElementStack(Element_s v){
    printf("%d ", v);
}

void printStack(Stack s){
    for(int i = s.top - 1; i >= 0; i--){
        printElementStack(s.arr[i]);
    }
    printf("\n");
}

int push(Stack *s, Element_s v){
    if(!isFullStack(*s)){
        (*s).arr[s->top] = v;
        s->top++;
        return 1;
    }
    return 0;
}

Element_s pop(Stack *s){
    Element_s temp = -9999;
    if(!isEmptyStack(*s)){
        temp = (*s).arr[s->top - 1];
        s->top--;
    }
    return temp;
}