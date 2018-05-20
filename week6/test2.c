#include <stdio.h>
#include <string.h>
#define SIZE 100
#define MAX_LENGTH 100

typedef struct element{
	char name[MAX_LENGTH];
	char phone[MAX_LENGTH];
	char email[MAX_LENGTH];
}Element;

int front = 0;
int rear = 0;
int counter = 0;

void printQueue(Element phoneBook[]){
    int i = front, n;
    for(n = 1; n <= counter; n++){
        printf("%.2d%-30s%-15s%-15s\n", i, phoneBook[i].name, phoneBook[i].phone, phoneBook[i].email);
        i = (i + 1) % SIZE;
    }
}

void enQueue(Element phoneBook[], Element temp){
    if(counter < SIZE){
        phoneBook[rear] = temp;
        rear = (rear + 1) % SIZE;
        counter++;
    }
    else
        puts("Queue is full!");
}

Element deQueue(Element phoneBook[]){
    Element temp = {"", "", ""};
    if(counter > 0){
        temp = phoneBook[front];
        front = (front + 1) % SIZE;
        counter--;
    }
    else
        puts("Queue is empty!");
    return temp;
}

/*void writeBook(FILE *ptr)
{
	Element new;
	int choice;
	printf("1 - continue\n2 - exit\n?");
	scanf("%d", &choice);
	while(choice != 0){
		getchar();
		printf("Enter name: ");
		fgets(new.name, MAX_LENGTH, stdin);
		new.name[strlen(new.name) - 1] = '\0';
		printf("name: %s\n", new.name);

		printf("Enter phone: ");
		scanf("%s", new.phone);

		printf("Enter email: ");
		scanf("%s", new.email);

		fwrite(&new, sizeof(Element), 1, ptr);

		printf("1 - continue\n0 - exit\n?");
		scanf("%d", &choice);
	}

	fclose(ptr);
}
*/

int main(int argc, char *argv[])
{
    Element phoneBook[SIZE];
    FILE *f = fopen(argv[1], "wb+");
    Element test = {"NGUYEN LAM", "840230482", "LAMNT@GMAIL.COM"};

    for(int i = 1; i <= SIZE + 100; i++){
        enQueue(phoneBook, test);
    }
    

    for(int i = 1; i <= 10; i++){
        test = deQueue(phoneBook);
    }

    for(int i = 1; i <= 5; i++){
        enQueue(phoneBook, test);
    }
    printQueue(phoneBook);

    printf("Counter: %d\nFront: %d\nRear: %d\n", counter, front, rear);

    /*
    //READ
    FILE *ptr = fopen(argv[1], "rb");
    if(ptr == NULL){
        puts("Source file doesn't exists!");
        return 1;
    }

    Element temp;
    int n;

	while(fread(&temp, sizeof(Element), 1, ptr))
		enQueue(phoneBook, temp);

    printQueue(phoneBook);
    fclose(ptr);

    //WRITE
    FILE *write = fopen(argv[2], "wb+");
    for(n = 1; n <= counter; n++){
        temp = deQueue(phoneBook);
        fwrite(&temp, sizeof(Element), 1, write);
    }
    fclose(write);
*/
    return 0;
}