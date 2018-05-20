/*EXERCISE 2 - flight.c*/

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

void printElement(Element temp);
void printQueue(Element eQueue[], int front, int counter);
void enQueue(Element phoneBook[], int *rear, int *counter, Element temp);
Element deQueue(Element phoneBook[], int *front, int *counter);
int str_len(char s[]);

int main(int argc, char *argv[]){//ENTER OUTPUT FILE NAME AS ARGUMENT
    if(argc != 2){
        puts("Wrong number of arguments!");
        return 1;
    }
    puts("TICKET MANAGEMENT PROGRAM");

    int choice, choice2, cont, temp_val, a, i, n;
    char temp_char;
    Element temp;
//REQUEST QUEUE
    Element requestQueue[SIZE];
    int front_request = 0;
    int rear_request = 0;
    int counter_request = 0;
//PROCESS QUEUE
    Element processQueue[SIZE];
    int front_process = 0;
    int rear_process = 0;
    int counter_process = 0;
//ACCEPT QUEUE
   	Element acceptQueue[SIZE];
   	int front_accept = 0;
   	int rear_accept = 0;
   	int counter_accept = 0;

    FILE *write;
    FILE *read;

    printf("1 - send request\n2 - process request\n?");
    scanf("%d", &choice);

    switch(choice){
        case 1://REQUESTING
       	//ADD REQUEST TO QUEUE AND STORE TO A FILE
       		printf("===SEND REQUEST===\n\n");
        	write = fopen(argv[1], "wb+");
            do{
                puts("SEND REQUEST");
            //GET FLIGHT NUMBER
                printf("Enter flight number: ");
                scanf("%s", temp.fNumber);
            //GET NAME
                getchar();
                printf("Enter name: ");
                fgets(temp.name, MAX_LENGTH - 1, stdin);
                temp.name[str_len(temp.name) - 1] = '\0';
            //GET TIME
                time(&(temp.bookTime));
            //GET QUANTITY
                printf("Enter quantity: ");
                scanf("%d", &temp_val);
                while(temp_val < 1){
                    printf("Enter quantity: ");
                    scanf("%d", &temp_val);
                }
                temp.quantity = temp_val;
            //GET TYPE
                getchar();
                printf("Enter type (W-C-N): ");
                scanf("%c", &temp_char);
                temp_char = toupper(temp_char);
                while(temp_char != 'W' && temp_char != 'C' && temp_char != 'N'){
                    printf("Enter type (W-C-N): ");
                    scanf("%c", &temp_char);
                    temp_char = toupper(temp_char);
                }
                temp.type = temp_char;
            //ENQUEUE
                enQueue(requestQueue, &rear_request, &counter_request, temp);
            //CONTINUE
                printf("continue?\n1 - yes\n0 - no...");
                scanf("%d", &temp_val);
                while(temp_val != 0 && temp_val != 1){
                    printf("continue?\n1 - yes\n0 - no...");
                    scanf("%d", &temp_val);
                }
                cont = temp_val;
            }while(cont != 0);
            printQueue(requestQueue, front_request, counter_request);
        //WRITE TO FILE
            i = front_request;
            for(a = 1; a <= counter_request; a++){
                fwrite(&requestQueue[i], sizeof(Element), 1, write);
                i++;
            }
            fclose(write);
            break;

        case 2://PROCESS
        //READ DATA FROM SOURCE FILE INTO PROCESSING QUEUE
            read = fopen(argv[1], "rb");
            if(read == NULL){
                puts("File doesn't exists!");
                return 2;
            }

            while(fread(&temp, sizeof(Element), 1, read)){
            	enQueue(processQueue, &rear_process, &counter_process, temp);
            }
            //printQueue(processQueue, front_process, counter_process);
        //CHECKING
            printf("===CHECKING REQUEST===\n\n");
            while(counter_process > 0){
               	temp = deQueue(processQueue, &front_process, &counter_process);
            	printElement(temp);
            	printf("1 - accept, 2 - reject?");
            	scanf("%d", &choice2);
            	switch(choice2){
            		case 1:
            			enQueue(acceptQueue, &rear_accept, &counter_accept, temp);
            			puts("Accepted!");
            			break;
            		case 2: 
            			puts("Rejected!");
            			break;
            		default:
            			puts("Try again!");
            			break;
            	}
            }
            fclose(read);
            printf("\nAccepted requests:\n");
            printQueue(acceptQueue, front_accept, counter_accept);

            break;
        default:
        	puts("Try again!");
            break;
    }
    printf("\nEXIT\n");
    return 0;
}

void printElement(Element temp){
	printf("%-10s%-30s%10d%6d   %c\n", temp.fNumber, temp.name,
           temp.bookTime, temp.quantity, temp.type);
}

void printQueue(Element eQueue[], int front, int counter){
    int i = front, n;
    for(n = 1; n <= counter; n++){
        printElement(eQueue[i]);
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

int str_len(char s[]){
    int i = 0;
    while(s[i] != '\0')
        i++;
    return i;
}



