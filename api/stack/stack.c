#include "stack.h"

//edit Element typedef in "stack.h"

int isEmpty(List stack)
{
	return stack == NULL;
}

void printContent(Content v)
{
	//edit according to elements of content
	printf("%c", v);//
}

void printList(Element *root)
{
	Element *ptr = root;
	while(ptr != NULL){
		printContent(ptr->data);
		ptr = ptr->next;
	}
}

Element *makeNode(Content v)
{
	Element *newNode = (Element *)malloc(sizeof(Element));
	newNode->data = v;
	newNode->next = NULL;

	return newNode;
}

void push(List *stack, Content v)
{
	Element *newNode = makeNode(v);
	newNode->next = *stack;
	*stack = newNode;
}

Content peek(List stack)
{
	if(stack != NULL)
		return stack->data;
	//edit default return value
	return EOF;//
}

Content pop(List *stack)
{
	//edit temp value
	Content temp = EOF;//
	if((*stack) != NULL){
		Element *ptr = *stack;
		temp = ptr->data;
		*stack = (*stack)->next;
		free(ptr);
	}
	return temp;
}