#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef char Content;

typedef struct e{
	Content data;
	struct e *next;
}Element;

typedef Element *List;


int isEmpty(List stack);
void printContent(Content v);
void printList(Element *root);
Element *makeNode(Content v);
void push(List *stack, Content v);
Content peek(List stack);
Content pop(List *stack);