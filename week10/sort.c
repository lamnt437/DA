/*Exercise 1*/

#include <stdio.h>
#include <string.h>
#define SIZE 100
#define MAX_LENGTH 100

typedef struct element{
    char name[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
}Element;

int counter = 0;

void printList(Element arr[], int n){
    for(int i = 1; i <= n; i++){
        printf("%20s%20s%20s\n", arr[i].name, arr[i].phone, arr[i].email);
    }
    printf("\n");
}

void writeFile(Element arr[], int n, FILE *write){
	for(int i = 1; i <= n; i++){
		fwrite(&arr[i], sizeof(Element), 1, write);
	}
}

void swap(Element *a, Element *b){
    Element temp = *a;
    *a = *b;
    *b = temp;
}

//HEAPSORT FUNCTION
void adjust(Element arr[], int root_index, int n){
    int child_index = root_index *2;
    while(child_index <= n){
    	counter++;
        if(child_index < n && strcmp(arr[child_index].name, arr[child_index + 1].name) < 0)
            child_index++;
        counter++;
        if(strcmp(arr[child_index].name, arr[root_index].name) < 0)
            break;
        else{
            swap(&arr[child_index], &arr[root_index]);
            root_index = child_index;
            child_index *= 2;
        }
    }
}

void heapSort(Element arr[], int n){
    for(int i = n / 2; i > 0; i--){
        adjust(arr, i, n);
    }
    for(int i = n; i > 0; i--){
        swap(&arr[1], &arr[i]);
        adjust(arr, 1, i - 1);
    }
}

//INSERTION SORT
void insertionSort(Element arr[], int n){//from 1 to n
	for(int i = 2; i <= n; i++){
		int j = i - 1;
		while(j > 0){
			counter++;
			if(strcmp(arr[j].name, arr[j + 1].name) > 0)
				swap(&arr[j], &arr[j + 1]);
			j--;			
		}
	}
}

//SELECTION SORT
void selectionSort(Element arr[], int n){//from 1 to n
	for(int i = 1; i <= n; i++){
		int temp = i;
		for(int j = i + 1; j <= n; j++){
			counter++;
			if(strcmp(arr[j].name, arr[temp].name) < 0)
				temp = j;
		}
		swap(&arr[i], &arr[temp]);
	}
}

int main(int argc, char *argv[]){//PROGRAM RECEIVES 2 ARGUMENT: INPUT AND OUTPUT FILES
	//LOAD FILE
	if(argc != 3){
		puts("Wrong number of arguments!");
		return 1;
	}

    FILE *read = fopen(argv[1], "rb");
    if(read == NULL){
    	puts("Input file doesn't exist!");
    	return 2;
    }
    FILE *write = fopen(argv[2], "wb");

    //INITIALIZE ARRAY
    Element arr[SIZE];
    Element buff;
    int n, i = 1;
    while(fread(&buff, sizeof(Element), 1, read)){
        arr[i] = buff;
        i++;
    }
    n = i - 1;
    fclose(read);

    puts("Original:");
    printList(arr, n);

    //SORT
    int choice;
    do{
		printf("1 - insertionSort, 2 - selectionSort, 3 - heapSort?");
   		scanf("%d", &choice);
    }while(choice != 1 && choice != 2 && choice != 3);

    switch(choice){
    	case 1:
    		insertionSort(arr, n);
    		break;
    	case 2:
    		selectionSort(arr, n);
    		break;
    	case 3:
    		heapSort(arr, n);
    		break;
    }
    
    puts("Sorted:");
    printList(arr, n);
    printf("counter: %d\n", counter);

    //WRITE OUTPUT
    writeFile(arr, n, write);
    printf("Sorted list has been written to %s!", argv[2]);
    fclose(write);

    return 0;
}
