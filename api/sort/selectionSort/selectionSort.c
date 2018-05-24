#include "selectionSort.h"

void swap(Element *a, Element *b){
	Element temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(Element arr[], int n){
    if(n > 1){
        for(int i = 0; i < n - 1; i++){
            int temp = i;
            for(int j = i + 1; j < n; j++){
                if(arr[j] < arr[temp])
                    temp = j;
            }
            swap(&arr[i], &arr[temp]);
        }
    }
}