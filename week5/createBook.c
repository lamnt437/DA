#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

typedef struct address
{
	char name[MAX_LENGTH];
	char phone[MAX_LENGTH];
	char email[MAX_LENGTH];
}Address;

void writeBook(FILE *ptr)
{
	Address new;
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
		//printf("email: %s\n", new->email);

		fwrite(&new, sizeof(Address), 1, ptr);

		printf("1 - continue\n0 - exit\n?");
		scanf("%d", &choice);
	}

	fclose(ptr);
}

int main()
{
    writeBook();
}
