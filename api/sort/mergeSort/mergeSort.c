#include "mergeSort.h"

void merge(Element arr[], int l, int m, int r, Element arr_temp[]){
    if(l <= m && m <= r && l < r){
        int i = l, j = m + 1, k = l;
        
        while(i <= m && j <= r){
            arr_temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
        }
        while(i <= m){
            arr_temp[k++] = arr[i++];
        }
        while(j <= r){
            arr_temp[k++] = arr[j++];
        }
        for(k = l; k <= r; k++){
            arr[k] = arr_temp[k];
        }
    }
}

void mergeSort(Element arr[], int l, int r, Element arr_temp[]){
    if(l < r){
        int m = (l + r)/2;
        mergeSort(arr, l, m, arr_temp);
        mergeSort(arr, m + 1, r, arr_temp);
        merge(arr, l, m, r, arr_temp);
    }
}