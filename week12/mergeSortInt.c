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
		if(strcmp(arr[i].name, arr[j].name) < 0){//arr[i] < arr[j]){
			newArr[k] = arr[i];
			k++;
			i++;
		}
		else{
			newArr[k] = arr[j];
			k++;
			j++;
		}
	}
	while(i <= m){
		newArr[k] = arr[i];
		k++;
		i++;
	}
	while(j <= r){
		newArr[k] = arr[j];
		k++;
		j++;
	}
	for(int n = l; n <= r; n++){
		arr[n] = newArr[n];
	}
}

void mergeSort(KeyType arr[], int l, int r, KeyType newArr[]){
	if(l < r){
		int m = (l + r)/2;
		mergeSort(arr, l, m, newArr);
		mergeSort(arr, m + 1, r, newArr);
		merge(arr, l, m, r, newArr);
	}
}

int main(){
	KeyType arr[100];
	KeyType newArr[100];
	int counter = 0;
	KeyType buff;
	FILE *read = fopen("input.txt", "rb");
	while(fread(&buff, sizeof(KeyType), 1, read)){
		arr[counter] = buff;
		counter++;
	}
	fclose(read);
	mergeSort(arr, 0, counter - 1, newArr);
	for(int i = 0; i < counter; i++){
		printf("%25s%25s%25s\n", arr[i].name, arr[i].phone, arr[i].email);
	}

	return 0;
}