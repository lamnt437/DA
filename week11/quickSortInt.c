#include <stdio.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r, int pivot_index){
	if(pivot_index >= l && pivot_index <= r && l < r){
	//swap pivot with the first element
        int pivot = arr[pivot_index];
		swap(&arr[pivot_index], &arr[l]);
	//3 regions: <p, >p, unpartitioned
		//beginning: i= j  = 2nd element's index
		int i = l + 1;
		for(int j = i; j <= r; j++){
			//if(arr[j] > pivot) do nothing
			if(arr[j] < pivot){
				swap(&arr[j], &arr[i]);
				i++;
			}
		}
	//move pivot to the right position
		swap(&arr[l], &arr[i - 1]);
		pivot_index = i - 1;
	}
	return pivot_index;
}

void quicksort(int arr[], int l, int r){
    //println();
	if(l < r){
		int pivot_index = (l + r)/2;
		pivot_index = partition(arr, l, r, pivot_index);
		quicksort(arr, l, pivot_index - 1);
		quicksort(arr, pivot_index + 1, r);
	}
}

int main(){
	int arr[100];
	int j = 0;
	for(int i = 20; i >= 11; i--){
		arr[j] = i;
		j++;
	}
	quicksort(arr, 0, j - 1);
	for(int i = 0; i < j; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
