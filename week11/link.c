/*Exercise 1 - quick sort using linked list*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_LENGTH 100

typedef struct info{
    char name[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
}Info;

typedef Info KeyType;

typedef struct e{
    KeyType data;
    struct e *next;
}Element;

typedef Element *List;

void printList(List root);

void insertFirst(List *root, KeyType v);

int listCounter(List root);

Element *getIndex(List root, int i);

void swapList(Element *a, Element *b);

int getPivotFirst(int l, int r);

int getPivotRandom(int l, int r);

int getPivotMedian(List root, int l, int r);

int partition(List root, int l, int r, int pivot_index);

void quickSortListFirst(List root, int l, int r);
void quickSortListRandom(List root, int l, int r);
void quickSortListMedian(List root, int l, int r);

void freeList(List *root);

int main(int argc, char *argv[]){//PROGRAM TAKES 2 ARGUMENTS: INPUT AND OUTPUT FILES
	//CHECK ARGUMENT
	if(argc != 3){
		puts("Wrong number of arguments!");
		return 1;
	}
	FILE *read = fopen(argv[1], "rb");
	FILE *write = fopen(argv[2], "wb");
	if(read == NULL){
		puts("Input file doesn't exist!");
		return 2;
	}

    List root = NULL;
    KeyType buff;
    int choice;

    //LOAD INPUT
    while(fread(&buff, sizeof(KeyType), 1, read))
        insertFirst(&root, buff);
    fclose(read);

    printf("Original List:\n");
    printList(root);

    //SORT
    do{
    printf("1 - first as pivot\n2 - random as pivot\n3 - median as pivot\n?");
    scanf("%d", &choice);
    }while(choice != 1 && choice != 2 && choice != 3);

    switch(choice){
    	case 1:
    		quickSortListFirst(root, 1, listCounter(root));
    		break;
    	case 2:
    		quickSortListRandom(root, 1, listCounter(root));
    		break;
    	case 3:
    		quickSortListMedian(root, 1, listCounter(root));
    		break;
    }
    
    printList(root);

    //WRITE TO OUTPUT FILE
    Element *ptr = root;
    while(ptr != NULL){
    	fwrite(&(ptr->data), sizeof(KeyType), 1, write);
    	ptr = ptr->next;
    }
    fclose(write);
    printf("Sorted list has been written to %s\n", argv[2]);
    freeList(&root);

    return 0;
}

void printList(List root){
    Element *ptr = root;
    while(ptr != NULL){
        printf("%25s%25s%25s\n", 
            (ptr->data).name, 
            (ptr->data).phone, 
            (ptr->data).email);
        ptr = ptr->next;
    }
    printf("\n");
}
void insertFirst(List *root, KeyType v){
    Element *temp = (Element *)malloc(sizeof(Element));
    temp->data = v;
    temp->next = *root;
    *root = temp;
}
int listCounter(List root){
    int counter = 0;
    Element *ptr = root;
    while(ptr != NULL){
        counter++;
        ptr = ptr->next;
    }
    return counter;
}
Element *getIndex(List root, int i){
    if(i < 1 || i > listCounter(root))
        return NULL;
    else{
    int counter = 1;
    Element *ptr = root;
    while(ptr != NULL){
        if(counter < i){
            ptr = ptr->next;
            counter++;
        }
        else
            break;
    }
    return ptr;
    }
}
void swapList(Element *a, Element *b){
    KeyType temp = a->data;
    a->data = b->data;
    b->data = temp;
}
int getPivotFirst(int l, int r){
    return l;
}
int getPivotRandom(int l, int r){
    srand(time(NULL));
    return l + rand() % (r - l + 1);
}
int getPivotMedian(List root, int l, int r){
    KeyType arr[3];
    int arrIndex[3];
    int status[3] = {0};

    arr[0] = getIndex(root, l)->data;
    arrIndex[0] = l;

    arr[1] = getIndex(root, (l + r)/2)->data;
    arrIndex[1] = (l + r)/2;

    arr[2] = getIndex(root, r)->data;
    arrIndex[2] = r;

    int minIndex = 0;
    for(int i = 1; i <= 2; i++){
        if(strcmp(arr[i].name, arr[minIndex].name) < 0)
            minIndex = i;
    }
    status[minIndex] = 1;

    int maxIndex = 2;
    for(int i = 0; i < 2; i++){
        if(strcmp(arr[i].name, arr[maxIndex].name) > 0)
            maxIndex = i;
    }
    status[maxIndex] = 1;
    
    for(int i = 0; i <= 2; i++){
        if(status[i] == 0)
            return arrIndex[i];
    }
}
int partition(List root, int l, int r, int pivot_index){
    if(l <= pivot_index && pivot_index <= r && l < r){
        Element *pivotPtr = getIndex(root, pivot_index);
        KeyType pivotValue = pivotPtr->data;

        Element *leftPtr = getIndex(root, l);
        Element *rightPtr = getIndex(root, r);
        swapList(pivotPtr, leftPtr);
    //partition
        Element *i = leftPtr->next;
        int i_index = l + 1;
        for(Element *j = i; j != rightPtr || j == rightPtr; j = j->next){
            if(strcmp((j->data).name, pivotValue.name) < 0){
                swapList(i, j);
                i = i->next;
                i_index++;
            }
            if(j == rightPtr)
                break;
        }
        pivot_index = i_index - 1;
        pivotPtr = getIndex(root, pivot_index);
        swapList(leftPtr, pivotPtr);
    }
    return pivot_index;
}
void quickSortListFirst(List root, int l, int r){
    if(l < r){
        int pivot_index = getPivotFirst(l, r);
        pivot_index = partition(root, l, r, pivot_index);
        quickSortListFirst(root, l, pivot_index - 1);
        quickSortListFirst(root, pivot_index + 1, r);
    }
}

void quickSortListRandom(List root, int l, int r){
    if(l < r){
        int pivot_index = getPivotRandom(l, r);
        pivot_index = partition(root, l, r, pivot_index);
        quickSortListRandom(root, l, pivot_index - 1);
        quickSortListRandom(root, pivot_index + 1, r);
    }
}

void quickSortListMedian(List root, int l, int r){
    if(l < r){
        int pivot_index = getPivotMedian(root, l, r);
        pivot_index = partition(root, l, r, pivot_index);
        quickSortListMedian(root, l, pivot_index - 1);
        quickSortListMedian(root, pivot_index + 1, r);
    }
}

void freeList(List *root){
	Element *ptr = *root;
	while(ptr != NULL){
		*root = ptr->next;
		free(ptr);
		ptr = *root;
	}
}

/*Exercise 2 - quick sort using array*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100
#define SIZE 100

typedef struct info{
    char name[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
}Info;

typedef Info KeyType;

int counter = 0;
KeyType arr[100];

void swap(KeyType *a, KeyType *b){
    KeyType temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(){
    for(int i = 0; i < counter; i++)
        printf("%25s%25s%25s\n", arr[i].name, arr[i].phone, arr[i]. email);
}

int partition(int l, int r, int pivot_index){
    if(pivot_index >= l && pivot_index <= r && l < r){
        KeyType pivot = arr[pivot_index];
        swap(&arr[pivot_index], &arr[l]);

        int i = l + 1;
        for(int j = i; j <= r; j++){
            if(strcmp(arr[j].name, pivot.name) < 0){
                swap(&arr[j], &arr[i]);
                i++;
            }
        }

        swap(&arr[l], &arr[i - 1]);
        pivot_index = i - 1;
    }
    return pivot_index;
}

void quicksort(int l, int r){
    if(l < r){
        int pivot_index = l;
        pivot_index = partition(l, r, pivot_index);
        quicksort(l, pivot_index - 1);
        quicksort(pivot_index + 1, r);
    }
}

int main(int argc, char *argv[]){//PROGRAM TAKES 2 ARGUMENTS: INPUT AND OUTPUT FILES
    if(argc != 3){
        puts("Wrong number of arguments!");
        return 1;
    }

    FILE *read = fopen(argv[1], "rb");
    FILE *write = fopen(argv[2], "wb");

    if(read == NULL){
        puts("Input file doesn't exist!");
        return 2;
    }

    KeyType buff;
    while(fread(&buff, sizeof(KeyType), 1, read)){
        arr[counter] = buff;
        counter++;
    }
    fclose(read);

    puts("Original list:");
    printArr();

    quicksort(0, counter - 1);
    puts("Sorted list:");
    printArr();

    return 0;
}