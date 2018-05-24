#include "heapSort.h"

int main(){
    Element arr[10] = {0, 9,8, 6, 1, 11, 4,5, 23, 15};
    heapSort(arr, 9);

    for(int i = 1; i <= 9; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}