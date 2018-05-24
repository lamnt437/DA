#include "quickSort.h"

int partition(Element arr[], int l, int r, int pivot_index){
	if(pivot_index >= l && pivot_index <= r && l < r){
        Element pivot = arr[pivot_index];
		swap(&arr[pivot_index], &arr[l]);

		int i = l + 1;
		for(int j = i; j <= r; j++){
			// if(strcmp(arr[j].name, pivot.name) < 0){
            if(arr[j] < pivot){
				swap(&arr[j], &arr[i]);
				i++;
			}
		}

		swap(&arr[l], &arr[i - 1]);
		pivot_index = i - 1;
	}
	return pivot_index;
}

void quickSort(Element arr[], int l, int r){
	if(l < r){
		int pivot_index = l;
		pivot_index = partition(arr, l, r, pivot_index);
		quickSort(arr, l, pivot_index - 1);
		quickSort(arr, pivot_index + 1, r);
	}
}
