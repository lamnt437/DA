#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
#define SIZE 100

typedef struct element{
	char name[MAX_LENGTH];
	char phone[MAX_LENGTH];
	char email[MAX_LENGTH];
}Element;

int binarySearchChar(Element arr[], int lo, int hi, char key[], int index){
	if(lo <= hi){
		int mid = (lo + hi)/2;
		if(arr[mid].name[index] == key[index])
			return mid;
		if(arr[mid].name[index] < key[index])
			return binarySearchChar(arr, mid + 1, hi, key, index);
		return binarySearchChar(arr, lo, mid - 1, key, index);
	}
	return -1;
}

int searchString(Element arr[], int n, char key[]){
    int i = 0, j = n - 1;
    int val;
    int index = 0;
    while(i != j){
        val = binarySearchChar(arr, i, j, key, index);
        if(val == -1)
            return -1;
        i = val;
        while(arr[i - 1].name[index] == key[index])
            i--;

        j = val;
        while(arr[j + 1].name[index] == key[index])
            j++;
        index++;
    }
    return val;
}

void printList(Element phoneBook[]){
    int i ;
    for(i = 0; i < SIZE; i++){
        printf("%-2s\n", phoneBook[i].name);
    }
}

int main(){
	Element arr[SIZE];
	char key[MAX_LENGTH];
	char val1 = 'a';
	char val2 = 'a';
	int counter = 0;

	for(int i = 0; i < SIZE; i++){
		if(counter <= 3){
			arr[i].name[0] = val1;
			arr[i].name[1] = val2;
			val2++;
			counter++;
		}
		else{
			counter = 0;
			val2 = 'a';
			val1++;
			arr[i].name[0] = val1;
			arr[i].name[1] = val2;
			val2++;
			counter++;
		}
	}
	printList(arr);

	printf("Enter to search: ");
	fgets(key, MAX_LENGTH - 1, stdin);
	key[strlen(key) - 1] = '\0';
	printf("Search: %d\n", searchString(arr, SIZE, key));

	return 0;
}
