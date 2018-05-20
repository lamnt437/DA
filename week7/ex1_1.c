/*Exercise 1.1 - linearSearchArray.c*/

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
	Element temp = {"e", "e", "e"};
	strcpy(arr[n].name, keyName);
	int i = 0;
	while(strcmp(arr[i].name, keyName))
		i++;
	if(i == n)
		return temp;
	return arr[i];
}

int input(Element arr[], FILE *read){
	Element buff;
	int i = 0;
	while(fread(&buff, sizeof(Element), 1, read)){
		arr[i] = buff;
		i++;
	}
	return i;
}

int main(int argc, char *argv[]){
	if(argc != 3){
		puts("Wrong number of input!");
		return 1;
	}

	FILE *read = fopen(argv[1], "rb");
	if(read == NULL){
		puts("No input file!");
		return 2;
	}

	FILE *write = fopen(argv[2], "wb");

	int counter = input(elementArray, read);
	char item[MAX_LENGTH];

	printArray(elementArray, counter);
	printf("Enter name to search: ");
	fgets(item, MAX_LENGTH - 1, stdin);
	item[strlen(item) - 1] = '\0';

	//SEARCH
	Element temp = LinearSentinelSearch(elementArray, 10, item);
	puts("Search result:");
	if(!strcmp(temp.name, "e"))
		puts("No record!");
	else{
		printElement(temp);
		fwrite(&temp, sizeof(Element), 1, write);
		printf("Result has been written to %s!\n", argv[2]);
	}

	fclose(read);
	fclose(write);

	return 0;
}

