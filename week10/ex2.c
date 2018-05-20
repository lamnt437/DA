/*Exercise 2*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 500

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//INSERTION SORT
void insertionSort(int arr[], int n){//1 -> n
	for(int j = 2; j <= n; j++){
		int i = j - 1;
		while(i > 0 && arr[i] > arr[i + 1]){
			swap(&arr[i], &arr[i + 1]);
			i--;
		}
	}
}

//HEAP SORT
void adjust(int arr[], int root_index, int n){
    int child_index = root_index * 2;
    while(child_index <= n){
        if(child_index < n && arr[child_index] < arr[child_index + 1])
            child_index++;
        if(arr[root_index] > arr[child_index])
            break;
        else{
            swap(&arr[root_index], &arr[child_index]);
            root_index = child_index;
            child_index *= 2;
        }
    }
}

void heapSort(int arr[], int n){
    for(int i = n / 2; i > 0; i--)
        adjust(arr, i, n);
    for(int i = n; i > 0; i--){
        swap(&arr[1], &arr[i]);
        adjust(arr, 1, i - 1);
    }
}

void printArr(int arr[], int n){
	for(int i = 1; i <= n; i++){
		printf("%d\n", arr[i]);
	}
}

int main(){
    int arr1[SIZE + 1];
    int arr2[SIZE + 1];
    time_t t1, t2;
    srand(time(NULL));
    for(int i = 1; i <= SIZE; i++){
        arr1[i] = 1 + rand() % 100000;
        arr2[i] = arr1[i];
    }
    time(&t1);
    heapSort(arr1, SIZE);
    time(&t2);
    printArr(arr1, SIZE);
    printf("Time heap sort: %d\n", (int)t2 - t1);
    time(&t1);
    insertionSort(arr2, SIZE);
    time(&t2);
    printf("Time insertion sort: %d\n", (int)t2 - t1);

    return 0;
}
