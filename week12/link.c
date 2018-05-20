/*Exercise 1*/

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



/*Exercise 2*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100
#define MAX_LENGTH 100

int preceding(char *first, char *second){
	if(*first != '\0' && *second != '\0'){
		if(*first < *second)
			return 1;
		else{
			if(*first > *second)
				return -1;
			else
				return preceding(++first, ++second);
		}
	}
	if(*first == '\0' && *second != '\0')
		return 1;
	if(*first != '\0' && *second == '\0')
		return -1;
	else
		return 0;
}

int setup_nameList(char *namelist[], char *filename){
	FILE *read = fopen(filename, "r");
	if(read == NULL)
		return 0;
	int counter = 0;
	char buff[MAX_LENGTH];
	while(fgets(buff, MAX_LENGTH, read) != NULL){
		if(buff[strlen(buff)-1] == '\n')
			buff[strlen(buff)-1] = '\0';
		namelist[counter] = (char *)malloc(MAX_LENGTH * sizeof(char));
		strcpy(namelist[counter], buff);
		counter++;
	}
	fclose(read);
	return counter;
}

void swap(char **a, char **b){
	char *temp = *a;
	*a = *b;
	*b = temp;
}

int partition(char *namelist[], int l, int r, int pivot_index){
	if(l <= pivot_index && pivot_index <= r && l < r){
		char *pivot = namelist[pivot_index];
		swap(&namelist[l], &namelist[pivot_index]);
		int i = l + 1;
		for(int j = i; j <= r; j++){
			if(preceding(namelist[j], pivot) == 1){
				swap(&namelist[i], &namelist[j]);
				i++;
			}
		}
		pivot_index = i - 1;
		swap(&namelist[l], &namelist[pivot_index]);
	}
	return pivot_index;
}

void qsort_name(char *namelist[], int l, int r){
	if(l < r){
		int pivot_index = (l + r)/2;
		pivot_index = partition(namelist, l, r, pivot_index);
		qsort_name(namelist, l, pivot_index - 1);
		qsort_name(namelist, pivot_index + 1, r);
	}
}

int main(int argc, char *argv[]){//PROGRAM TAKES 1 ARGUMENT: INPUT FILE
	if(argc != 2){
		puts("Wrong number of arguments!");
		return 1;
	}

	char *list[SIZE];
	int counter;

	counter = setup_nameList(list, "input.txt");
	puts("==Original list==");
	for(int i = 0; i < counter; i++)
		printf("%s\n", list[i]);

	qsort_name(list, 0, counter - 1);

	printf("\n==Sorted list==\n");
	for(int i = 0; i < counter; i++){
		printf("%s\n", list[i]);
		free(list[i]);
	}

	return 0;
}