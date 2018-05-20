#include "linked_list.h"

int main()

{

	Student *root = NULL;

	Student *ptr = NULL;

	char id_temp[ID_LENGTH];

	char name_temp[NAME_LENGTH];

	int grade_temp;

	int choose;



	printf("MENU:\n1 - Insert\n2 - Search\n3 - Delete\n4 - Change grade\n5 - Exit\nChoose....");

	scanf("%d", &choose);



	while(choose != 5){

		switch(choose){

			case 1://Insert

				printf("\nINSERT\n\nEnter id: ");

				scanf("%s", id_temp);



				getchar();

				printf("Enter name: ");

				fgets(name_temp, NAME_LENGTH, stdin);

				name_temp[my_strlen(name_temp) - 1] = '\0';



				printf("Enter grade: ");

				scanf("%d", &grade_temp);



				insert2(&root, id_temp, name_temp, grade_temp);



				printList(root);



				break;



			case 2://Search

				printf("\nSEARCH\n\nEnter ID: ");

				scanf("%s", id_temp);



				ptr = search(root, id_temp);



				if(ptr == NULL)

					printf("No record!\n");

				else

					printStudent(ptr);



				break;



			case 3://Delete

				printf("\nDELETE\n\nEnter ID: ");

				scanf("%s", id_temp);

				root = delete(root, id_temp);

				printList(root);



				break;



			case 4://Change grade

				printf("\nCHANGE GRADE\n\nEnter ID: ");

				scanf("%s", id_temp);

				printf("Enter new grade: ");

				scanf("%d", &grade_temp);

				root = change(root, id_temp, grade_temp);

				printList(root);



				break;



			default:

				printf("Error!\n");

				break;

		}

		printf("\nMENU:\n1 - Insert\n2 - Search\n3 - Delete\n4 - Change grade\n5 - Exit\nChoose....");

	 	scanf("%d", &choose);	

	}



	freeList(&root);

	printf("\nEXIT\n");



	return 0;

}