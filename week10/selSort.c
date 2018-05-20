#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int arr[], int n){
	for(int i = 0; i < n; i++){
		int temp = i;
		for(int j = i + 1; j < n; j++){
			if(arr[j] < arr[temp])
				temp = j;
		}
		swap(&arr[i], &arr[temp]);
	}
}

void printArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int arr[5] = {9,8,7,6,5};
	selectionSort(arr, 5);
	printArr(arr, 5);
}