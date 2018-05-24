#include "bubbleSort.h"

int main(){
    Element arr[] = {20, 10, 30, 2, 7,5, 4,1};
    bubbleSort(arr, 2);
    for(int i = 0; i < 2; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}