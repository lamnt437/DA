#include <stdio.h>
#include <string.h>
#define SIZE 100
#define MAX_LENGTH 100

typedef struct element{
	char name[MAX_LENGTH];
	char phone[MAX_LENGTH];
	char email[MAX_LENGTH];
}Element;

Element elementArray[101];

void printElement(Element ptr){
	printf("%-30s%-30s%-30s\n", ptr.name, ptr.phone, ptr.email);
}

void printArray(Element arr[], int n){
	printf("%-30s%-30s%-30s\n\n", "NAME", "PHONE", "EMAIL");
	int i = 0;
	while(i < n){
		printElement(arr[i]);
		i++;
	}
}

Element LinearSentinelSearch(Element arr[], int n, char keyName[]){
	strcpy(arr[n].name, keyName);
	int i = 0;
	while(strcmp(arr[i].name, keyName))
		i++;
	return arr[i];
}

Element TransposeSearch(Element arr[], int n, char keyName[]){
	int i;
	Element temp = {"e", "", ""};
	for(i = 0; i < n - 1 && strcmp(arr[i].name, keyName); i++);
	if(!strcmp(arr[i].name, keyName)){
		if(i > 0){
			temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;
		}
	}
	return temp;
}

int input(Element arr[], int n, FILE *read){
	Element buff;
	int i = 0;
	while(fread(&buff, sizeof(Element), 1, read) && i < n){
		arr[i] = buff;
		i++;
	}
	return i;
}

int main(int argc, char *argv[]){
	FILE *read = fopen(argv[1], "rb");
	if(read == NULL){
		puts("No input file!");
		return 1;
	}

	int counter = input(elementArray, 10, read);
	char item[MAX_LENGTH];

	printf("Enter name to search: ");
	fgets(item, MAX_LENGTH - 1, stdin);
	item[strlen(item) - 1] = '\0';

	printArray(elementArray, counter);

	//SEARCH
	Element temp = TransposeSearch(elementArray, 10, item);
	printf("Search result:\n");
	printElement(elementArray[temp]);
	printf("\nNew array:\n");
	printArray(elementArray, counter);

	return 0;
}

