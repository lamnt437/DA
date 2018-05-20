#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100
#define MAX_LENGTH 100

int preceding(char *first, char *second){
	if(*first != '\0' && *second != '\0'){
		if(*first < *second)
			return 1;
		else{
			if(*first > *second)
				return -1;
			else
				return preceding(++first, ++second);
		}
	}
	if(*first == '\0' && *second != '\0')
		return 1;
	if(*first != '\0' && *second == '\0')
		return -1;
	else
		return 0;
}

int setup_nameList(char *namelist[], char *filename){
	FILE *read = fopen(filename, "r");
	if(read == NULL)
		return 0;
	int counter = 0;
	char buff[MAX_LENGTH];
	while(fgets(buff, MAX_LENGTH, read) != NULL){
		if(buff[strlen(buff)-1] == '\n')
			buff[strlen(buff)-1] = '\0';
		namelist[counter] = (char *)malloc(MAX_LENGTH * sizeof(char));
		strcpy(namelist[counter], buff);
		counter++;
	}
	fclose(read);
	return counter;
}

void swap(char **a, char **b){
	char *temp = *a;
	*a = *b;
	*b = temp;
}

int partition(char *namelist[], int l, int r, int pivot_index){
	if(l <= pivot_index && pivot_index <= r && l < r){
		char *pivot = namelist[pivot_index];
		swap(&namelist[l], &namelist[pivot_index]);
		int i = l + 1;
		for(int j = i; j <= r; j++){
			if(preceding(namelist[j], pivot) == 1){
				swap(&namelist[i], &namelist[j]);
				i++;
			}
		}
		pivot_index = i - 1;
		swap(&namelist[l], &namelist[pivot_index]);
	}
	return pivot_index;
}

void qsort_name(char *namelist[], int l, int r){
	if(l < r){
		int pivot_index = (l + r)/2;
		pivot_index = partition(namelist, l, r, pivot_index);
		qsort_name(namelist, l, pivot_index - 1);
		qsort_name(namelist, pivot_index + 1, r);
	}
}

int main(){
	char *list[SIZE];
	int counter;
	counter = setup_nameList(list, "input.txt");
	for(int i = 0; i < counter; i++)
		printf("%s\n", list[i]);

	qsort_name(list, 0, counter - 1);

	printf("\nNew:\n");
	for(int i = 0; i < counter; i++){
		printf("%s\n", list[i]);
		free(list[i]);
	}

	return 0;
}