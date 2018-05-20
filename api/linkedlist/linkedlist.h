#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

typedef struct Student_t{

	char id[MAX_LENGTH];

	char name[MAX_LENGTH];

	int grade;

}Student;

typedef Student Content;

typedef struct e{
	Content data;
	struct e *next;
}Element;

typedef Element *List;

void printContent(Content elm);
void printList(Element *root);
Element *makeNode(Content v);
void insert(List *root, Content v);
void insertFirst(List *root, Content v);
Element *search(List root, char key[]);
int delete(List *root, char key[]);
int change(List *root, char key[]);
void bubbleSort(List root);
double average(List root);
