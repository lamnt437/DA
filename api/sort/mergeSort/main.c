#include "mergeSort.h"

int main(){
    Element arr[] = {10, 20, 7, 5, 4, 9, 12, 1 , 6};
    Element arr_temp[9];

    mergeSort(arr, 0, 8, arr_temp);
    for(int i = 0; i < 9; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}