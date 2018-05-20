#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define SIZE 50
#define MAX_LENGTH 100

typedef struct element{
	char fNumber[MAX_LENGTH];
    char name[MAX_LENGTH];
    time_t bookTime;
    int quantity;
    char type;
}Element;

int front = 0;
int rear = 0;
int counter = 0;

int isFull(int n){
    return n == SIZE;
}

void printQueue(Element eQueue[], int front, int counter){
    int i = front, n;
    for(n = 1; n <= counter; n++){
        printf("%.2d.%-10s%-30s%10d%6d   %c\n", i, eQueue[i].fNumber, eQueue[i].name,
                eQueue[i].bookTime, eQueue[i].quantity, eQueue[i].type);
        i = (i + 1) % SIZE;
    }
}

void enQueue(Element phoneBook[], int *rear, int *counter, Element temp){
    if(*counter < SIZE){
        phoneBook[*rear] = temp;
        *rear = (*rear + 1) % SIZE;
        (*counter)++;
    }
    else
        puts("Queue is full!");
}

Element deQueue(Element phoneBook[], int *front, int *counter){
    Element temp = {"", "", 0, 0, 'e'};
    if(*counter > 0){
        temp = phoneBook[*front];
        *front = (*front + 1) % SIZE;
        (*counter)--;
    }
    else
        puts("Queue is empty!");
    return temp;
}


int main()
{
    Element eQueue[SIZE];
    Element temp = {"MH370", "CAO TUAN DUNG", 0, 10, 'W'};
    for(int i = 1; i <= SIZE + 2; i++){
        enQueue(eQueue, &rear, &counter, temp);
    }


    for(int i = 1; i <= 10; i++){
        temp = deQueue(eQueue, &front, &counter);
    }

    for(int i = 1; i <= 5; i++){
        enQueue(eQueue, &rear, &counter, temp);
    }
    printQueue(eQueue, front, counter);
    printf("front: %d\nrear: %d\ncounter: %d\n", front, rear, counter);
    return 0;
}
