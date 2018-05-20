/*Exercise 4 - binarySearchAddress.c*/

#include <stdio.h>
#include <string.h>
#define SIZE 100
#define MAX_LENGTH 100

typedef struct element{
    char name[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
}Element;

int binarySearchChar(Element arr[], int lo, int hi, char key[], int index);
int binarySearchString(Element arr[], int n, char key[]);
void generateList();
void printElement(int index);
void printList();

const char *first[5] = {"Anh ", "Duc ", "Hung ", "Linh ", "Son "};
const char *mid[4] = {"Ngoc ", "Thi ", "Tuan ", "Van "};
const char *last[5] = {"Le", "Ly", "Ngo", "Nguyen", "Tran"};

Element arr[SIZE];

int main(){
	generateList();
	printList();
	char key[MAX_LENGTH];
	int val;

	printf("Enter name to search: ");
	fgets(key, MAX_LENGTH - 1, stdin);
	key[strlen(key) - 1] = '\0';
	val = binarySearchString(arr, SIZE, key);
	puts("Search result:");
	printElement(val);

	return 0;
}

void generateList(){
	int temp, counter = 0;
    for(int i= 0; i < 5; i++){
    	for(int j = 0; j < 4; j++){
    		for(int k = 0; k < 5; k++){
    			strcpy(arr[counter].name, first[i]);
    			temp = strlen(arr[counter].name);
    			strcpy(&arr[counter].name[temp], mid[j]);
    			temp = strlen(arr[counter].name);
    			strcpy(&arr[counter].name[temp], last[k]);
    			strcpy(arr[counter].phone, "0123456789");
    			strcpy(arr[counter].email, "anonymous@gmail.com");
    			counter++;
    		}
    	}
    }
}

void printElement(int index){
	printf("%-7d%-30s%-15s%-15s\n", index + 1, arr[index].name, arr[index].phone, arr[index].email);
}

void printList(){
	for(int i = 0; i < SIZE; i++){
		printf("%-7d%-30s%-15s%-15s\n", i + 1, arr[i].name, arr[i].phone, arr[i].email);
	}
}

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

int binarySearchString(Element arr[], int n, char key[]){
    int i = 0, j = n - 1;
    int prev_i = i, prev_j = j;
    int val;
    int index = 0;
    while(i != j){
        val = binarySearchChar(arr, i, j, key, index);
        if(val == -1)
            return -1;
        i = val;
        while(arr[i - 1].name[index] == key[index] && i - 1 >= prev_i)
            i--;
        prev_i = i;
        j = val;
        while(arr[j + 1].name[index] == key[index] && j + 1 <= prev_j)
            j++;
        prev_j = j;
        index++;
    }
    if(!strcmp(arr[val].name, key))
        return val;
    return -1;
}