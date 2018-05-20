/*EXERCISE 1 -phoneBook.c*/

#include <stdio.h>
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

int str_len(char s[]){
	int i = 0;
	while(s[i] != '\0')
		i++;
	return i;
}

void printQueue(Element phoneBook[]){
    int i = front, n;
    for(n = 1; n <= counter; n++){
        printf("%-30s%-15s%-15s\n", phoneBook[i].name, phoneBook[i].phone, phoneBook[i].email);
        i = (i + 1) % SIZE;
    }
}

void printArray(Element phoneBook[], int n){
	for(int i = 0; i < n; i++){
		printf("%-30s%-15s%-15s\n", phoneBook[i].name, phoneBook[i].phone, phoneBook[i].email);
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

void writeBook(FILE *ptr){
	Element new;
	int choice;
	do{
		getchar();
		printf("Enter name: ");
		fgets(new.name, MAX_LENGTH, stdin);
		new.name[str_len(new.name) - 1] = '\0';

		printf("Enter phone: ");
		scanf("%s", new.phone);

		printf("Enter email: ");
		scanf("%s", new.email);

		fwrite(&new, sizeof(Element), 1, ptr);

		printf("1 - continue\n0 - exit\n?");
		scanf("%d", &choice);
	}while(choice != 0);
}

int main(int argc, char *argv[]){//2 ARGUMENTS(ORIGINAL AND DESTINATION FILE)
	int choice;
	int temp_val;
	int id;
	FILE *write;
	FILE *read;
	FILE *ptr;
	Element temp;
    Element phoneBook[SIZE];
    Element arr[SIZE];
    int n;

    if(argc != 3){
    	puts("Wrong number of arguments!");
    	return 1;
    }

    //GET ARRAY
    int counter = 0;
    read = fopen(argv[1], "rb");
    while(!fread(&temp, sizeof(Element), 1, read)){
    	arr[counter] = temp;
    	counter++;
    }
    fclose(read);

    //PRINT ARRAY
    printArray(arr, counter);

	printf("1 - create a phonebook\n2 - edit\n3 - copy phonebook\n?");
	scanf("%d", &temp_val);
	while(temp_val != 1 && temp_val != 2){
		printf("Try again!\n1 - create a phonebook\n2 - edit\n3 - copy phonebook\n?");
		scanf("%d", &temp_val);
	}
	choice = temp_val;

	switch(choice){
		case 1:
			printf("===CREATE PHONEBOOK===\n\n");
			write = fopen(argv[1], "ab");
			writeBook(write);
			fclose(write);
			puts("Successfully created!");
			break;

		case 2:
			printf("===EDIT PHONEBOOK===\n\n");
			printf("Enter number: ");
			scanf("%d", &id);
			ptr = fopen(argv[1], "rb+");
			fseek(ptr, id * sizeof(Element), SEEK_SET);
			getchar();
			printf("Enter name: ");
			fgets(temp.name, MAX_LENGTH -1, stdin);
			temp.name[str_len(temp.name) -  1] = '\0';

			printf("Enter phone: ");
			scanf("%s", temp.phone);

			printf("Enter email: ");
			scanf("%s", temp.email);
			fwrite(&temp, sizeof(Element), 1, ptr);
			puts("Successfully editted");
			fclose(ptr);
			break;


		case 3: 
			printf("===COPY PHONEBOOK===\n\n");
		//READ
		    read = fopen(argv[1], "rb");
		    if(read == NULL){
		    	puts("Original file doesn't exist!");
		    	return 2;
		    }

			while(fread(&temp, sizeof(Element), 1, read))
				enQueue(phoneBook, temp);

		    printQueue(phoneBook);
		    fclose(read);

		//WRITE
		    FILE *write = fopen(argv[2], "wb+");
		    for(n = 1; n <= counter; n++){
		        temp = deQueue(phoneBook);
		        fwrite(&temp, sizeof(Element), 1, write);
		    }
		    fclose(write);
		    puts("Successfully copied!");
			break;
	}
    
    return 0;
}






