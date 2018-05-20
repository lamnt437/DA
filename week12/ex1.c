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

void merge(KeyType arr[], int l, int m, int r, KeyType newArr[]){
	int i = l, j = m + 1, k = l;
	while(i <= m && j <= r){
		if(strcmp(arr[i].name, arr[j].name) < 0)
			newArr[k++] = arr[i++];
		else
			newArr[k++] = arr[j++];
	}
	while(i <= m)
		newArr[k++] = arr[i++];
	while(j <= r)
		newArr[k++] = arr[j++];
	for(int n = l; n <= r; n++)
		arr[n] = newArr[n];
}

void mergeSort(KeyType arr[], int l, int r, KeyType newArr[]){
	if(l < r){
		int m = (l + r)/2;
		mergeSort(arr, l, m, newArr);
		mergeSort(arr, m + 1, r, newArr);
		merge(arr, l, m, r, newArr);
	}
}

int main(int argc, char *argv[]){
	//CHECK ARGUMENTS
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

	//LOAD INPUT
	KeyType arr[100];
	KeyType newArr[100];
	int counter = 0;
	KeyType buff;

	puts("Original list:");
	while(fread(&buff, sizeof(KeyType), 1, read)){
		printf("%25s%25s%25s\n", buff.name, buff.phone, buff.email);
		arr[counter] = buff;
		counter++;
	}
	fclose(read);

	//SORT
	mergeSort(arr, 0, counter - 1, newArr);
	puts("Sorted list:");
	for(int i = 0; i < counter; i++){
		printf("%25s%25s%25s\n", arr[i].name, arr[i].phone, arr[i].email);
		fwrite(&arr[i], sizeof(KeyType), 1, write);
	}
	fclose(write);
	printf("Sorted list has been written to %s!\n", argv[2]);

	return 0;
}