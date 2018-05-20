#include "linkedlist.h"

void printContent(Content v)
{
	//edit according to elements of content
	printf("%s%s%d\n", v.id, v.name, v.grade);
}

void printList(Element *root)
{
	Element *ptr = root;
	while(ptr != NULL){
		printContent(ptr->data);
		ptr = ptr->next;
	}
}

Element *makeNode(Content v)
{
	Element *newNode = (Element *)malloc(sizeof(Element));
	newNode->data = v;
	newNode->next = NULL;

	return newNode;
}

void insert(List *root, Content v)
{
	Element *newNode = makeNode(v);
	Element *cur = *root;
	Element *prev = NULL;

	//edit condition of while according to the value being sorted
	while(cur != NULL && v.grade < (cur->data).grade){//
		prev = cur;
		cur = cur->next;
	}
	if(prev == NULL){
		newNode->next = *root;
		*root = newNode;
	}
	else{
		newNode->next = cur;
		prev->next = newNode;
	}
}

void insertFirst(List *root, Content v){
	Element *newNode = makeNode(v);
	newNode->next = *root;
	*root = newNode;
}

Element *search(List root, char key[]){//edit parameter               
	Element *ptr = root;
	while(ptr != NULL){

		//edit condition
		if(!strcmp((ptr->data).id, key))
			return ptr;
		ptr = ptr->next;
	}
	return NULL;
}

int delete(List *root, char key[]){//edit parameter
	Element *cur = *root;
	Element *prev = NULL;

	//edit condition
	while(cur != NULL && strcmp((cur->data).id, key)){
		prev = cur;
		cur = cur->next;
	}
	if(cur != NULL){
		if(prev == NULL){
			*root = cur->next;
			free(cur);
		}
		else{
			prev->next = cur->next;
			free(cur);
		}

		return 1;
	}
	return 0;
}

int change(List *root, char key[]){//edit parameter
	Element *ptr = *root;

	//edit condition strcmp
	while(ptr != NULL && strcmp((ptr->data).id, key)){
		ptr = ptr->next;
	}
	if(ptr != NULL){
		//edit new data
		Content v = ptr->data;
		printf("Enter new grade: ");//
		scanf("%d", &(v.grade));//
		delete(root, key);//
		insert(root, v);
		return 1;
	}
	return 0;
}

int counter(List root){
	int counter = 0;
	Element *ptr = root;
	while(ptr != NULL){
		counter++;
		ptr = ptr->next;
	}
	return counter;
}

void bubbleSort(List root){//descending
	Element *i = root;
	int n = counter(root);
	Content temp;
	if(i == NULL)
		return;
	Element *j = i->next;


	for(int k = 1; k <= n; k++ ){
		while(j != NULL){
			//edit condition
			if((j->data).grade < (i->data).grade){
				temp = j->data;
				j->data = i->data;
				i->data = temp;
			}
			j = j->next;
			i = i->next;
		}
		i = root;
		j = i->next;
	}
}

double average(List root){
	double sum = 0;
	int counter = 0;
	Element *ptr = root;
	while(ptr != NULL){
		sum += (ptr->data).grade;
		ptr = ptr->next;
		counter++;
	}
	return sum/counter;
}