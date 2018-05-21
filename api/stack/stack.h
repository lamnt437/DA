#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef char Content_s;

typedef struct e{
	Content_s data;
	struct e *next;
}Element_s;

typedef Element_s *List;
typedef List Stack;


int isEmpty_s(List stack);
void printContent(Content_s v);
void printList(Element_s *root);
Element_s *makeNode(Content_s v);
void push(List *stack, Content_s v);
Content_s peek(List stack);
Content_s pop(List *stack);
