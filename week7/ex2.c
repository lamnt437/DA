/*Exercise 2 - transposeSearchList.c*/

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
LinkList *TransposeSearch(LinkList *root, char key[]);
void writeBook(FILE *ptr);

//PROGRAM TAKE 1 ARGUMENT: INPUT FILE
int main(int argc, char *argv[]){
	int choice, counter;
	char key[MAX_LENGTH];
	FILE *read;
	FILE *write;
	LinkList *root = NULL;

	if(argc != 2){
		puts("Wrong number of arguments!");
		return 1;
	}

	printf("1 - create input file and search\n2 - search only(if input file already exists)\n?");
	scanf("%d", &choice);

	if(choice == 1){
		write = fopen(argv[1], "wb");
		writeBook(write);
		fclose(write);
	}
	
	read = fopen(argv[1], "rb");
	if(read == NULL){
		puts("Input file doesn't exist!");
		return 2;
	}

	counter = input(&root, read);
	printList(root);

	do{
		getchar();
		printf("Enter key to search: ");
		fgets(key, MAX_LENGTH - 1, stdin);
		key[strlen(key) - 1] = '\0';

		LinkList *temp = TransposeSearch(root, key);
		printf("\n***Search result:\n");
		if(temp == NULL)
			puts("No record!");
		else
			printElement(temp->data);

		printf("\n***New list:\n\n");
		printList(root);

		printf("1 - continue, 0 - quit?");
		scanf("%d", &choice);
	}while(choice != 0);

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

void writeBook(FILE *ptr){
	Element new;
	int choice;
	do{
		getchar();
		printf("Enter name: ");
		fgets(new.name, MAX_LENGTH, stdin);
		new.name[strlen(new.name) - 1] = '\0';

		printf("Enter phone: ");
		scanf("%s", new.phone);

		printf("Enter email: ");
		scanf("%s", new.email);

		fwrite(&new, sizeof(Element), 1, ptr);

		printf("1 - continue\n0 - exit\n?");
		scanf("%d", &choice);
	}while(choice != 0);
}