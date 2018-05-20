#include "linked_list.h"

int my_strlen(char s[])

{

	int i = 0;

	while(s[i] != '\0')

		i++;

	return i;

}



void printStudent(Student *ptr)

{

	printf("%-12s%-30s%d\n", ptr->id, ptr->name, ptr->grade);

}



void printList(Student *root)

{

	Student *cur = root;

	printf("%-12s%-30s%s\n\n", "ID", "NAME", "GRADE");

	while(cur != NULL){

		printStudent(cur);

		cur = cur->next;

	}

}



Student *insert(Student *root, char id_ins[], char name_ins[], int grade_ins)

{

	Student *new = (Student *)malloc(sizeof(Student));

	strcpy(new->id, id_ins);

	strcpy(new->name, name_ins);

	new->grade = grade_ins;



	Student *prev = NULL;

	Student *cur = root;



	while(cur != NULL && grade_ins < cur->grade){

		prev = cur;

		cur = cur->next;

	}



	if(prev == NULL){

		new->next = root;

		root = new;

	}



	else{

		new->next = prev->next;

		prev->next = new;

	}



	return root;

}

void insert2(Student **root, char id_ins[], char name_ins[], int grade_ins)

{

	Student *new = (Student *)malloc(sizeof(Student));

	strcpy(new->id, id_ins);

	strcpy(new->name, name_ins);

	new->grade = grade_ins;



	Student *prev = NULL;

	Student *cur = *root;



	while(cur != NULL && grade_ins < cur->grade){

		prev = cur;

		cur = cur->next;

	}



	if(prev == NULL){

		new->next = *root;

		*root = new;

	}



	else{

		new->next = prev->next;

		prev->next = new;

	}

}



Student *search(Student *root, char id_temp[])

{

	Student *cur = root;

	while(cur != NULL){

		if(!strcmp(id_temp, cur->id))

			return cur;

		cur = cur->next;

	}



	return NULL;

}



Student *get_prev(Student *root, Student *ptr){

	Student *prev = NULL;

	Student *cur = root;

	while(cur != ptr){

		prev = cur;

		cur = cur->next;

	}

	return prev;

}



Student *delete(Student *root, char id_temp[])

{

	Student *prev = NULL;

	Student *ptr = search(root, id_temp);



	if(ptr == NULL)

		printf("No record!\n\n");

	else{

		prev = get_prev(root, ptr);



		if(prev == NULL){

			root = root->next;

			free(ptr);

		}



		else{

			prev->next = ptr->next;

			free(ptr);

		}

	}



	return root;

}



Student *change(Student *root, char id_temp[], int grade_temp)

{

	Student *ptr = search(root, id_temp);

	char name_temp[NAME_LENGTH];

	strcpy(name_temp, ptr->name);



	root = delete(root, id_temp);

	root = insert(root, id_temp, name_temp, grade_temp);



	return root;

}



void freeList(Student **root)

{

	Student *ptr = *root;

	while(ptr != NULL){

		*root = (*root)->next;

		free(ptr);

		ptr = *root;

	}

}



