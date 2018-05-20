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

int my_strlen(char s[]){
	int i = 0;

	while(s[i] != '\0')
		i++;
	return i;
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

LinkList *TransposeSearch(LinkList *root, char key[]){
	LinkList *prev = NULL;
	LinkList *cur = root;
	while(cur != NULL && strcmp(cur->data.name, key)){
		prev = cur;
		cur = cur->next;
	}
	if(cur != NULL){
		if(prev != NULL){//ALREADY AT FIRST PLACE
			strcpy(cur->data.name, prev->data.name);
			strcpy(prev->data.name, key);
			return prev;
		}
		else
			return cur;
	}
	return NULL;
}

int main(int argc, char *argv[]){
	FILE *read = fopen(argv[1], "rb");
	LinkList *root = NULL;
	int counter = input(&root, read);
	printList(root);
	char key[MAX_LENGTH];

	printf("Enter key to search: ");
	fgets(key, MAX_LENGTH - 1, stdin);
	key[my_strlen(key) - 1] = '\0';

	LinkList *temp = TransposeSearch(root, key);
	puts("Search result:");
	if(temp == NULL)
		puts("No record!");
	else
		printElement(temp->data);
	printf("\nNew list:\n");
	printList(root);
}

