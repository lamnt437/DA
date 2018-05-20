#include <string.h>
#include <stdio.h>
#define MAX_LENGTH 100
#define SIZE 100		

typedef struct address
{
	char name[MAX_LENGTH];
	char phone[MAX_LENGTH];
	char email[MAX_LENGTH];
}Address;

int main(){
	Address arr[SIZE];
}

/*
*/

int binarySearch(Address arr[], int lo, int hi, char s[], int index){
	if(hi >= lo){
		int mid = (hi + lo)/2;
		if(arr[mid].name[index] == s[index]){/*
			//FIND AROUND
			//find low
			i = mid;
			while(arr[i].name[index] == s[index]){
				i--;
			}
			//find high
			j = mid;
			while(arr[j].name[index] == s[index]){
				counter++;
				j++;
			}
			return binSearchString(arr, i + 1, j - 1, s, index + 1);
			*/
			return mid;
		}

		if(arr[mid].name[index] < s[index])
			return binSearchString(arr, mid + 1, hi, s, index);
		return binSearchString(arr, lo, mid - 1, s, index);
	}

	return -1;
}

int searchString(Address arr[], int n, char key[]){
	int i = 0, j = n - 1, index = 0;
	int val;
	while(i != j){
		val = binarySearch(arr, i, j, key, index);
		//find low
		i = val;
		while(arr[i - 1].name[index] == s[index])
			i--;
		//find high
		j = val;
		while(arr[j + 1].name[index] == s[index])
			j++;
		index++;
	}
	
}