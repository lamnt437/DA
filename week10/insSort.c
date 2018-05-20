#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertionSort(int arr[], int n){//0 -> n - 1
	for(int j = 1; j < n; j++){
		int key = arr[j];
		int i = j - 1;
		while(i >= 0 && arr[i] > key){
			swap(&arr[i], &arr[i + 1]);
			i--;
		}
	}
}

void printArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int arr[1] = {9};
	insertionSort(arr, 1);
	printArr(arr, 1);

	return 0;
}