#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
#define CHAR_NUMBER 256

int max(int a, int b){
	return a > b? a : b;
}

int F[CHAR_NUMBER];

void last_appear(char s[], int n){//n pattern's length
	int i;
	for(i = 0; i < CHAR_NUMBER; i++){
		F[i] = -1;
	}
	for(i = n - 1; i >= 0; i--){
		F[(char) s[i]] = i;
	}
}

int search(char t[], int m, char s[], int n){
	int i = n - 1, j = n - 1, last_found;	//i points to t, j points to s
	while(i < m){
		//match 
		printf("%c ?? %c\n", t[i], s[j]);
		if(t[i] == s[j]){
			if(j == 0)
				return i;
			else{
				i--;
				j--;
			}
		}
		//not match ->realign
		last_found = F[(int) t[i]];
		else if(last_found != -1 && last_found != i){
			i = i + j - F[(int) t[i]];
			j = n - 1;	
		}
		else{
			i = i + n;
			j = n - 1;
		}
		printf("i: %d	j: %d\n", i, j);
	}
	return -1;
}

int main(){
	int i;
	int a = 2;
	int b = 1;
	char t1[] = "1nguyen tung lam";
	char s1[] = "nguyen tung lam";
	printf("max: %d\n", max(a, b));
	for(i = 0; i < MAX_LENGTH; i++){
		F[i] = -1;
	}
	last_appear(s1, strlen(s1));
	a = strlen(s1);
	for(i = 0; i < a; i++){
		printf("%d ", F[i]);
	}
	printf("\n");
	
	int x = search(t1, strlen(t1), s1, strlen(s1));
	
	printf("%d\n", x);
	return 0;
}
