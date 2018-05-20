#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;

typedef struct e{
    KeyType data;
    struct e *next;
}Element;

typedef Element *List;

void printList(List root){
    Element *ptr = root;
    while(ptr != NULL){
        printf("%d ", ptr->data);
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
            if(j->data < pivotValue){
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

void quickSortList(List root, int l, int r){
    if(l < r){
        int pivot_index = (l + r)/2;
        pivot_index = partition(root, l, r, pivot_index);
        quickSortList(root, l, pivot_index - 1);
        quickSortList(root, pivot_index + 1, r);
    }
}

int main(){
    List root = NULL;
    for(int i = 10; i <= 20; i++){
        insertFirst(&root, i);
    }
    printList(root);
    quickSortList(root, 1, listCounter(root));
    printList(root);

    return 0;
}

