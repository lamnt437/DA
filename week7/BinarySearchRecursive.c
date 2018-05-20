#include <stdio.h>

int binSearch(int arr[], int head, int tail, int val);

int main(){
	int arr[1000];
	int value = 1;
	int s;
	for(int i = 0; i < 1000; i++){
		arr[i] = value;
		value += 2;
	}
	printf("Enter value: ");
	scanf("%d", &s);
	printf("binSearch: %d\n", binSearch(arr, 0, 999, s));
}

int binSearch(int arr[], int head, int tail, int val){
	printf("head: %d, tail: %d\n", head, tail);
	int r = -1;
	if(head <= tail){
		//base case when head == tail
			
			int mid = (head + tail)/2;
			if(arr[mid] == val)
				r = mid;
			else{
				if(val > arr[mid])
					r = binSearch(arr, mid + 1, tail, val);
				else
					r = binSearch(arr, head, mid - 1, val);
			
		}
	}
	return r;
}

int binSearchString()