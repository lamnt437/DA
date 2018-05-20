#include <stdio.h>

int binarySearch(int arr[], int first, int last, int key){
	if(first <= last){
		int mid = (first + last)/2;
		if(arr[mid] == key)
			return mid;
		if(key > arr[mid])
			return binarySearch(arr, mid + 1, last, key);
		return binarySearch(arr, first, mid - 1, key);
	}
	return -1;
}

int main(){
	int arr[1000];
	int val = 0, key;

	for(int i = 0; i < 1000; i++){
		arr[i] = val;
		val += 2;
	}

	printf("Enter an integer to search: ");
	scanf("%d", &key);
	puts("Result:");
	val = binarySearch(arr, 0, 999, key);
	if(val == -1)
		puts("Doesn't exist!");
	else
		printf("Place: %d\n", val + 1);

	return 0;
}