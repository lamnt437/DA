#include "heapSort.h"

//ARRAY FROM 1 TO N
//DEFINE ARR[N + 1]

void swap(Element *a, Element *b){
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void adjust(Element arr[], int root_index, int n){  
    //from 1 to n -> n elements, n - last index =>define arr[n + 1]

    int child_index = root_index *2;
    while(child_index <= n){
        // if(child_index < n && strcmp(arr[child_index].name, arr[child_index + 1].name) < 0)
        if(child_index < n && arr[child_index] < arr[child_index + 1])
            child_index++;
        // if(strcmp(arr[child_index].name, arr[root_index].name) < 0)
        if(arr[child_index] < arr[root_index])
            break;
        else{
            swap(&arr[child_index], &arr[root_index]);
            root_index = child_index;
            child_index *= 2;
        }
    }
}

void heapSort(Element arr[], int n){
    for(int i = n / 2; i > 0; i--){
        adjust(arr, i, n);
    }
    for(int i = n; i > 0; i--){
        swap(&arr[1], &arr[i]);
        adjust(arr, 1, i - 1);
    }
}