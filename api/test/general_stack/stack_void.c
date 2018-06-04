#include "stack_void.h"

void initStack(Stack *s){
    s->top = 0;
}

int isEmptyStack(Stack s){
    return s.top == 0;
}

int isFullStack(Stack s){
    return s.top == STACK_SIZE;
}
/*
void printElementStack(Element_s *ptr){
    printf("%d ", *ptr);
}

void printStack(Stack s){
    for(int i = s.top - 1; i >= 0; i--){
        printElementStack(s.arr[i]);
    }
    printf("\n");
}
*/
void *makeContent(Element_s v){
    Element_s *newContent = malloc(sizeof(Element_s));
    *newContent = v;
    return newContent;
}

int push(Stack *s, Element_s v){
    if(!isFullStack(*s)){
        (*s).arr[(*s).top] = makeContent(v);
        s->top++;
        return 1;
    }
    return 0;
}

Element_s *pop(Stack *s){
    Element_s *temp = NULL;
    if(!isEmptyStack(*s)){
        temp = (*s).arr[s->top - 1];
        s->top--;
    }
    return temp;
}
