#include <stdio.h>

#include <stdlib.h>

#include <string.h>



#define ID_LENGTH 9

#define NAME_LENGTH 30

typedef struct Student_t{

	char id[ID_LENGTH];

	char name[NAME_LENGTH];

	int grade;

	struct Student_t *next;

}Student;

int my_strlen(char s[]);
void printStudent(Student *ptr);
void printList(Student *root);
Student *insert(Student *root, char id_ins[], char name_ins[], int grade_ins);
void insert2(Student **root, char id_ins[], char name_ins[], int grade_ins);
Student *search(Student *root, char id_temp[]);
Student *get_prev(Student *root, Student *ptr);
Student *delete(Student *root, char id_temp[]);
Student *change(Student *root, char id_temp[], int grade_temp);
void freeList(Student **root);