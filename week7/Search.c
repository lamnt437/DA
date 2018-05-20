#include <stdlib.h>
#include <string.h>
#define SIZE 100
#define MAX_LENGTH 100

typedef struct element{
	char name[MAX_LENGTH];
	char phone[MAX_LENGTH];
	char email[MAX_LENGTH];
}Element;

int binarySearch(char arr[], int lo, int hi, char key){
	if(lo <= hi){
		int mid = (lo + hi)/2;
		if(arr[mid] == key)
			return mid;
		if(key > arr[mid])
			return binarySearch(arr, mid + 1, hi, key);
		return binarySearch(arr, lo, mid - 1, key);
	}
	return -1;
}

int searchString(char arr[])
