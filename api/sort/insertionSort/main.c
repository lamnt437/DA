#include "insertionSort.h"

int main(){
	int arr[7];
	int n = 10;
	for(int i = 0; i < 7; i++){
		arr[i] = n;
		n--;
	}
	insertionSort(arr, 7);
	for(int i = 0; i < 7; i++){
		printf("%d ", arr[i]);
	}
}