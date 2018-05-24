#include "bubbleSort.h"

void swap(Element *a, Element *b){
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Element arr[], int n){
    if(n > 1){
        for(int i = n - 1; i > 0; i--){
            for(int j = 0; j < i; j++){
                if(arr[j] > arr[j + 1])
                    swap(&arr[j], &arr[j+1]);
            }
        }
    }
}