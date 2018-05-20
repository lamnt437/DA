#include "linkedlist.h"

int main(int argc, char *argv[]){
	if(argc != 2){
		puts("Wrong number of arguments!");
		return 1;
	}

	FILE *read = fopen(argv[1], "r");
	if(read == NULL){
		puts("Input file doesn't exist!");
		return 2;
	}


	Content value;
	char sTemp[MAX_LENGTH];
	char id_temp[MAX_LENGTH];
	char name_temp[MAX_LENGTH];
	char grade_char_temp[10];
	int grade_temp;
	int choice;
	char *breakpoint = NULL;
	List root = NULL;

	/*
	printf("1 - continue, 0 - quit...");
	scanf("%d", &choice);

	while(choice ==1){
		printf("Enter id:");
		scanf("%s", value.id);

		getchar();
		printf("Enter name: ");
		fgets(sTemp, MAX_LENGTH -1, stdin);
		sTemp[strlen(sTemp) - 1] = '\0';
		strcpy(value.name, sTemp);

		printf("Enter grade: ");
		scanf("%d", &(value.grade));

		insertFirst(&root, value);

		printf("1 - continue, 0 - quit...");
		scanf("%d", &choice);
	}
	*/

	// printf("%s%s%d\n", (root->data).id, (root->data).name, (root->data).grade);

	//load file with fgets

	//tokenize

	while(fgets(sTemp, MAX_LENGTH - 1, read) != NULL){
		breakpoint = strtok(sTemp, "/");
		strcpy(value.id, breakpoint);
		breakpoint = strtok(NULL, "/");
		strcpy(value.name, breakpoint);
		breakpoint = strtok(NULL, "/");
		//strcpy(grade_char_temp, breakpoint);
		value.grade = atoi(breakpoint);
		//printf("%s%s%s", id_temp, name_temp, grade_char_temp);
		insert(&root, value);
	}

	printList(root);
	printf("Search key: ");
	scanf("%s", sTemp);
	Element *ptr = search(root, sTemp);
	if(ptr != NULL)
		printContent(ptr->data);
	printf("Search key: ");
	scanf("%s", sTemp);
	int status = delete(&root, sTemp);
	if(status == 1)
		puts("Successfully deleted!");
	else
		puts("Failed!");
	printList(root);
	printf("Change key: ");
	scanf("%s", sTemp);
	status = change(&root, sTemp);
	if(status == 1){
		puts("Successfully changed!");
	}
	else{
		puts("Failed!");
	}
	printList(root);
	bubbleSort(root);
	printf("\nSorted:\n\n");
	printList(root);
	printf("The average grade is %.2lf\n", average(root));

	return 0;
}