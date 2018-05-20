#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100
#define MAX_LENGTH 100

typedef struct element{
	char name[MAX_LENGTH];
	char phone[MAX_LENGTH];
	char email[MAX_LENGTH];
}Element;

typedef struct list{
	Element data;
	struct list *next;
}LinkList;

void printElement(Element ptr);
void printList(LinkList *root);
void insertFirst(LinkList **root, Element buff);
int input(LinkList **root, FILE *read);
LinkList *searchMoveToFront(LinkList **first, char key[]);



int main(int argc, char *argv[]){
	FILE *read = fopen(argv[1], "rb");
	LinkList *root = NULL;
	int counter = input(&root, read);
	printList(root);
	char key[MAX_LENGTH];

	printf("Enter key to search: ");
	fgets(key, MAX_LENGTH - 1, stdin);
	key[strlen(key) - 1] = '\0';

	LinkList *temp = searchMoveToFront(&root, key);
	puts("Search result:");
	if(temp == NULL)
		puts("No record!");
	else
		printElement(temp->data);
	printf("\nNew list:\n");
	printList(root);
	fclose(read);

	return 0;
}


void printElement(Element ptr){
	printf("%-30s%-30s%-30s\n", ptr.name, ptr.phone, ptr.email);
}

void printList(LinkList *root){
	LinkList *cur = root;
	printf("%-30s%-30s%-30s\n\n", "NAME", "PHONE", "EMAIL");
	while(cur != NULL){
		printElement(cur->data);
		cur = cur->next;
	}
}

void insertFirst(LinkList **root, Element buff){
	LinkList *temp = (LinkList *)malloc(sizeof(LinkList));
	temp->data = buff;
	temp->next = *root;
	*root = temp;
}

int input(LinkList **root, FILE *read){
	int counter = 0;
	Element buff;
	while(fread(&buff, sizeof(Element), 1, read)){
		insertFirst(root, buff);
		counter++;
	}
	return counter;
}

LinkList *searchMoveToFront(LinkList **first, char key[]){
	LinkList *cur = *first;
	LinkList *prev = NULL;
	while(cur != NULL){
		if(!strcmp(cur->data.name, key))
			break;
		else{
			prev = cur;
			cur = cur->next;
		}
	}
	
	if(prev != NULL){
		if(cur != NULL){
			prev->next = cur->next;
			cur->next = *first;
			*first = cur;
		}
	}

	return cur;
}


