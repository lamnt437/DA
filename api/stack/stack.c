#include "stack.h"

//edit Element typedef in "stack.h"

int isEmpty_s(List stack)
{
	return stack == NULL;
}

void printContent(Content_s v)
{
	//edit according to elements of content
	printf("%c", v);//
}

void printList(Element_s *root)
{
	Element_s *ptr = root;
	while(ptr != NULL){
		printContent(ptr->data);
		ptr = ptr->next;
	}
}

Element_s *makeNode(Content_s v)
{
	Element_s *newNode = (Element_s *)malloc(sizeof(Element_s));
	newNode->data = v;
	newNode->next = NULL;

	return newNode;
}

void push(List *stack, Content_s v)
{
	Element_s *newNode = makeNode(v);
	newNode->next = *stack;
	*stack = newNode;
}

Content_s peek(List stack)
{
	if(stack != NULL)
		return stack->data;
	//edit default return value
	return EOF;//
}

Content_s pop(List *stack)
{
	//edit default temp value
	Content_s temp = EOF;//
	if((*stack) != NULL){
		Element_s *ptr = *stack;
		temp = ptr->data;
		*stack = (*stack)->next;
		free(ptr);
	}
	return temp;
}
