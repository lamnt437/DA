#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char * my_strcat(char *s1, char * s2);

int main()
{
	char s1[MAX], s2[MAX];
	char *s3;

	printf("Enter string 1: ");
	fgets(s1, MAX, stdin);
	s1[strlen(s1) - 1] = '\n';

	printf("Enter string 2: ");
	fgets(s2, MAX, stdin);
	s2[strlen(s2) - 1] = '\n';

	s3 = my_strcat(s1, s2);
	printf("s3: %s\n", s3);


	return 0;
}

char * my_strcat(char *s1, char * s2)
{
	char *s3; 
	s3 = (char *)malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
	strcpy(s3, s1);
	strcpy(s3 + strlen(s1), s2);

	return s3;
}