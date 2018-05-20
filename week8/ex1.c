/*Exercise 1 - linearSearch.c*/

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
void printArray(Element arr[], int n);
void insertFirst(LinkList **root, Element buff);
int inputList(LinkList **root, FILE *read);
int inputArray(Element arr[], FILE *read);
LinkList *searchMoveToFront(LinkList **first, char key[]);
Element linearSentinelSearchArray(Element arr[], int n, char keyName[]);
void writeBook(FILE *ptr);


//PROGRAM TAKES 2 ARGUMENTS: INPUT FILE AND OUTPUT FILE
int main(int argc, char *argv[]){
	int choice, cont;
	int counter = 0;

	LinkList *temp = NULL;
	LinkList *root = NULL;
	Element elementArray[101];
	Element item;

	char key[MAX_LENGTH];

	FILE *read;
	FILE *write;


	//CHECK ARGUMENTS
	if(argc != 3){
		puts("Wrong number of input!");
		return 1;
	}

	printf("Linear Search\n\n");
	printf("1 - Create input file (if don't have)\n2 - Implement using array\n3 - Implement using list\n?");
	scanf("%d", &choice);
	while(choice != 1 && choice != 2 && choice != 3){
		puts("Try again!");
		printf("1 - Create input file (if don't have)\n2 - Implement using array\n3 - Implement using list\n?");
		scanf("%d", &choice);
	}

	switch(choice){
	//CREATE INPUT FILE TO SEARCH
		case 1:
			printf("===CREATE INPUT FILE===\n\n");
			write = fopen(argv[1], "rb");
			if(write != NULL){
				printf("File already exists! Do you want to overwrite(1 - yes, 0 - no)\n?");
				scanf("%d", &cont);
				while(cont != 0 && cont !=1){
					printf("Do you want to overwrite(1 - yes, 0 - no)\n?");
					scanf("%d", &cont);
				}
				if(cont == 1){
					fclose(write);
					write = fopen(argv[1], "wb");
					writeBook(write);
					printf("Done!\nPlease re-run the program and search!\n");
				}
			}
			else{
				fclose(write);
				write = fopen(argv[1], "wb");
				writeBook(write);
				printf("Done!\nPlease re-run the program and search!\n");
			}
			fclose(write);
			break;

	//IMPLEMENT USING ARRAY
		case 2:
			//LOAD DATA
			read = fopen(argv[1], "rb");
			write = fopen(argv[2], "wb");
			if(read == NULL){
				puts("Input file doesn't exist!");
				return 2;
			}
			printf("===ARRAY===\n\n");
			counter = inputArray(elementArray, read);
			printArray(elementArray, counter);
			getchar();
			printf("Enter name to search: ");
			fgets(key, MAX_LENGTH - 1, stdin);
			key[strlen(key) - 1] = '\0';

			//SEARCH
			item = linearSentinelSearchArray(elementArray, counter, key);
			printf("\n***Search result:\n\n");
			if(!strcmp(item.name, "e"))
				puts("No record!");
			else{
				printElement(item);
				fwrite(&item, sizeof(Element), 1, write);
				printf("Result has been written to %s!\n", argv[2]);
			}
			fclose(read);
			fclose(write);

			break;

	//IMPLEMENT USING LINKED-LIST
		case 3:
			//LOAD DATA
			read = fopen(argv[1], "rb");
			write = fopen(argv[2], "wb");
			if(read == NULL){
				puts("Input file doesn't exist!");
				return 2;
			}
			printf("===LINKED-LIST===\n\n");
			counter = inputList(&root, read);
			printList(root);

			//SEARCH
			do{
				getchar();
				printf("Enter name to search: ");
				fgets(key, MAX_LENGTH - 1, stdin);
				key[strlen(key) - 1] = '\0';

				temp = searchMoveToFront(&root, key);
				printf("\n***Search result:\n\n");
				if(temp == NULL)
					puts("No record!");
				else{
					printElement(temp->data);
					fwrite(&temp->data, sizeof(Element), 1, write);
				}
				printf("\n***New list:\n\n");
				printList(root);

				printf("\n1 - continue to search, 0 - quit ?");
				scanf("%d", &cont);
			}while(cont != 0);
			printf("All search results have been written to %s!\n", argv[2]);
			fclose(read);
			fclose(write);

			break;
	}

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

void printArray(Element arr[], int n){
	printf("%-30s%-30s%-30s\n\n", "NAME", "PHONE", "EMAIL");
	int i = 0;
	while(i < n){
		printElement(arr[i]);
		i++;
	}
}

void insertFirst(LinkList **root, Element buff){
	LinkList *temp = (LinkList *)malloc(sizeof(LinkList));
	temp->data = buff;
	temp->next = *root;
	*root = temp;
}

int inputList(LinkList **root, FILE *read){
	int counter = 0;
	Element buff;
	while(fread(&buff, sizeof(Element), 1, read)){
		insertFirst(root, buff);
		counter++;
	}
	return counter;
}

int inputArray(Element arr[], FILE *read){
	Element buff;
	int i = 0;
	while(fread(&buff, sizeof(Element), 1, read)){
		arr[i] = buff;
		i++;
	}
	return i;
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

Element linearSentinelSearchArray(Element arr[], int n, char keyName[]){
	Element temp = {"e", "e", "e"};
	strcpy(arr[n].name, keyName);
	int i = 0;
	while(strcmp(arr[i].name, keyName))
		i++;
	if(i == n)
		return temp;
	return arr[i];
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