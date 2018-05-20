#include <stdio.h>
#include <string.h>

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

int getPivotMedian(List root, int l, int r){
	KeyType arr[3];
	int arrIndex[3];
	int status[3] = {0}

    KeyType arr[0] = getIndex(List root, l)->data;
    arrIndex[0] = l;

    KeyType arr[1] = getIndex(List root, (l + r)/2)->data;
    arrIndex[1] = (l + r)/2;

    KeyType arr[2] = getIndex(List root, r)->data;
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

void insertFirst(List *root, KeyType v){
    Element *temp = (Element *)malloc(sizeof(Element));
    temp->data = v;
    temp->next = *root;
    *root = temp;
}

void printList(List root){
    Element *ptr = root;
    while(ptr != NULL){
        printf("%20s%20s%20s\n", (ptr->data).name, (ptr->data).phone, (ptr->data).email);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
	List root = NULL;

}