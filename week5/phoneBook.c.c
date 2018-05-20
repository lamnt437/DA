/*Exercise 1 - phoneBook.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

typedef struct address
{
	char name[MAX_LENGTH];
	char phone[MAX_LENGTH];
	char email[MAX_LENGTH];
}Address;

typedef struct aStack
{
	Address add;
	struct aStack *next;
}AddressStack;

int isEmpty(AddressStack *top);
void push(AddressStack **top, Address temp);
Address pop(AddressStack **top);
void printStack(AddressStack *top);
void printNode(AddressStack *ptr);


int main(int argc, char *argv[])
{
	AddressStack *top = NULL;

	if(argc != 3){
		puts("Wrong number of arguments!");
		return 1;
	}

	FILE *read = fopen(argv[1], "r");
	FILE *write = fopen(argv[2], "w+");

	if(read == NULL){
		puts("Source file doesn't exists!");
		return 2;
	}

//READ TO STACK
	Address temp;

	while(fread(&temp, sizeof(Address), 1, read))
		push(&top, temp);

	printStack(top);
	fclose(read);

//WRITE TO FILE
	while(!isEmpty(top))
	{
		temp = pop(&top);
		fwrite(&temp, sizeof(Address), 1, write);
	}

	fclose(write);
	return 0;
}

int isEmpty(AddressStack *top)
{
	return top == NULL;
}

void printNode(AddressStack *ptr)
{
	printf("%-30s%-15s%-15s\n", ptr->add.name, ptr->add.phone, ptr->add.email);
}

void printStack(AddressStack *top)
{
	AddressStack *ptr = top;
	printf("%-30s%-15s%-15s\n\n", "NAME", "PHONE", "EMAIL");
	while(ptr != NULL){
		printNode(ptr);
		ptr = ptr->next;
	}
}

void push(AddressStack **top, Address temp)
{
	AddressStack *new = (AddressStack *)malloc(sizeof(AddressStack));
	new->add = temp;
	new->next = *top;
	*top = new;
}

Address pop(AddressStack **top)
{
	Address out = {NULL, NULL, NULL};
	if(isEmpty(*top))
		return out;

	AddressStack *ptr = *top;
	out = ptr->add;
	*top = ptr->next;
	free(ptr);

	return out;
}