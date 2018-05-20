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
			//CHECK IF FILE ALREADY EXISTS
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
					puts("Done!");
				}
			}
			else{
				fclose(write);
				write = fopen(argv[1], "wb");
				writeBook(write);
				puts("Done!");
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
			//SEARCH
			getchar();
			printf("Enter name to search: ");
			fgets(key, MAX_LENGTH - 1, stdin);
			key[strlen(key) - 1] = '\0';

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
	Element temp = {"e", "e", "e"};//default item
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


/*Exercise 3 - recursiveBinarySearch.c*/

#include <stdio.h>

int recursiveBinarySearch(int arr[], int first, int last, int key){
	if(first <= last){
		int mid = (first + last)/2;
		if(arr[mid] == key)
			return mid;
		if(key > arr[mid])
			return binarySearch(arr, mid + 1, last, key);
		return binarySearch(arr, first, mid - 1, key);
	}
	return -1;
}

int main(){
	int arr[1000];
	int val = 0, key;

	for(int i = 0; i < 1000; i++){
		arr[i] = val;
		val += 2;
	}

	printf("Enter an integer to search: ");
	scanf("%d", &key);
	puts("Result:");
	val = recursiveBinarySearch(arr, 0, 999, key);
	if(val == -1)
		puts("Doesn't exist!");
	else
		printf("Place: %d\n", val + 1);

	return 0;
}


/*Exercise 4 - binarySearchAddress.c*/

#include <stdio.h>
#include <string.h>
#define SIZE 100
#define MAX_LENGTH 100

typedef struct element{
    char name[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
}Element;

int binarySearchChar(Element arr[], int lo, int hi, char key[], int index);
int binarySearchString(Element arr[], int n, char key[]);
void generateList();
void printElement(int index);
void printList();

const char *first[5] = {"Anh ", "Duc ", "Hung ", "Linh ", "Son "};
const char *mid[4] = {"Ngoc ", "Thi ", "Tuan ", "Van "};
const char *last[5] = {"Le", "Ly", "Ngo", "Nguyen", "Tran"};

Element arr[SIZE];

int main(){
	generateList();
	printList();
	char key[MAX_LENGTH];
	int val;

	printf("Enter name to search: ");
	fgets(key, MAX_LENGTH - 1, stdin);
	key[strlen(key) - 1] = '\0';
	val = binarySearchString(arr, SIZE, key);
	puts("Search result:");
	printElement(val);

	return 0;
}

void generateList(){
	int temp, counter = 0;
    for(int i= 0; i < 5; i++){
    	for(int j = 0; j < 4; j++){
    		for(int k = 0; k < 5; k++){
    			strcpy(arr[counter].name, first[i]);
    			temp = strlen(arr[counter].name);
    			strcpy(&arr[counter].name[temp], mid[j]);
    			temp = strlen(arr[counter].name);
    			strcpy(&arr[counter].name[temp], last[k]);
    			strcpy(arr[counter].phone, "0123456789");
    			strcpy(arr[counter].email, "anonymous@gmail.com");
    			counter++;
    		}
    	}
    }
}

void printElement(int index){
	printf("%-7d%-30s%-15s%-15s\n", index + 1, arr[index].name, arr[index].phone, arr[index].email);
}

void printList(){
	for(int i = 0; i < SIZE; i++){
		printf("%-7d%-30s%-15s%-15s\n", i + 1, arr[i].name, arr[i].phone, arr[i].email);
	}
}

int binarySearchChar(Element arr[], int lo, int hi, char key[], int index){
	if(lo <= hi){
		int mid = (lo + hi)/2;
		if(arr[mid].name[index] == key[index])
			return mid;
		if(arr[mid].name[index] < key[index])
			return binarySearchChar(arr, mid + 1, hi, key, index);
		return binarySearchChar(arr, lo, mid - 1, key, index);
	}
	return -1;
}

int binarySearchString(Element arr[], int n, char key[]){
    int i = 0, j = n - 1;
    int prev_i = i, prev_j = j;
    int val;
    int index = 0;
    while(i != j){
        val = binarySearchChar(arr, i, j, key, index);
        if(val == -1)
            return -1;
        i = val;
        while(arr[i - 1].name[index] == key[index] && i - 1 >= prev_i)
            i--;
        prev_i = i;
        j = val;
        while(arr[j + 1].name[index] == key[index] && j + 1 <= prev_j)
            j++;
        prev_j = j;
        index++;
    }
    if(!strcmp(arr[val].name, key))
        return val;
    return -1;
}