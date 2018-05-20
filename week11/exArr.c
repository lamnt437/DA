#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100
#define SIZE 100

typedef struct info{
    char name[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
}Info;

typedef Info KeyType;

int counter = 0;
KeyType arr[100];

void swap(KeyType *a, KeyType *b){
	KeyType temp = *a;
	*a = *b;
	*b = temp;
}

void printArr(){
	for(int i = 0; i < counter; i++)
		printf("%25s%25s%25s\n", arr[i].name, arr[i].phone, arr[i]. email);
}

int partition(int l, int r, int pivot_index){
	if(pivot_index >= l && pivot_index <= r && l < r){
        KeyType pivot = arr[pivot_index];
		swap(&arr[pivot_index], &arr[l]);

		int i = l + 1;
		for(int j = i; j <= r; j++){
			if(strcmp(arr[j].name, pivot.name) < 0){
				swap(&arr[j], &arr[i]);
				i++;
			}
		}

		swap(&arr[l], &arr[i - 1]);
		pivot_index = i - 1;
	}
	return pivot_index;
}

void quicksort(int l, int r){
	if(l < r){
		int pivot_index = l;
		pivot_index = partition(l, r, pivot_index);
		quicksort(l, pivot_index - 1);
		quicksort(pivot_index + 1, r);
	}
}

int main(int argc, char *argv[]){//PROGRAM TAKES 2 ARGUMENTS: INPUT AND OUTPUT FILES
	if(argc != 3){
		puts("Wrong number of arguments!");
		return 1;
	}

	FILE *read = fopen(argv[1], "rb");
	FILE *write = fopen(argv[2], "wb");

	if(read == NULL){
		puts("Input file doesn't exist!");
		return 2;
	}

	KeyType buff;
	while(fread(&buff, sizeof(KeyType), 1, read)){
		arr[counter] = buff;
		counter++;
	}
	fclose(read);

	puts("Original list:");
	printArr();

	quicksort(0, counter - 1);
	puts("Sorted list:");
	printArr();

	return 0;
}