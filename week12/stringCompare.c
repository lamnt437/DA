#include <stdio.h>

int preceding(char *first, char *second){
	if(*first != '\0' && *second != '\0'){
		printf("first: %c, second: %c\n", *first, *second);
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

int main(){
	char s1[] = "nguyen";
	char s2[] = "nguyen ";
	printf("%d", preceding(s1, s2));
	//char *first = s1;
	//first++;
	//printf("%c", *first);

	return 0;
}