#include "insertionSort.h"

void swap(Element *a, Element *b){
	Element temp = *a;
	*a = *b;
	*b = temp;
}

void insertionSort(Element arr[], int n){//ascending
	if(n > 1){
		for(int j = 1; j < n; j++){
			int i = j - 1;
			int key = arr[j];
			while(i >= 0 && arr[i] > key){
				swap(&arr[i], &arr[i + 1]);
				i--;
			}
		}
	}
}