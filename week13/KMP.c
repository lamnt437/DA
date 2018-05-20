#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
#define SIZE 100

//PREFIX TABLE

int F[MAX_LENGTH];
/*void prefix_table(char P[], int m){
    int i = 1, j = 0;
    F[0] = 0;
    while(i < m){
        if(P[i] == P[j]){
            F[i] = j + 1;
            i++;
            j++;
        }
        else if(j > 0){
            j = F[j - 1];
        }
        else{
            F[i] = 0;
            i++;
        }
        //printf("i - %d: %c\tj - %d: %c\n", i, P[i], j, P[j]);
    }
}*/

void prefix_table(char s[], int m){
	int i = 0, j = 1;
	F[0] = 0;
	while (j < m){
		if(s[j] == s[i])
			F[j++] = ++i;
		else if(i > 0)
			i = F[i - 1];
		else
			F[j++] = 0;
	}
}

/*
int KMP(char T[], int n, char P[], int m){
	int i = 0, j = 0;
	//i points to string T
	//j points to pattern P
	
	prefix_table(P, m);
	while(i < n){
		if(T[i]==P[j]){
			if(j==m-1)
				return i - j;//position found pattern
			else{
				i++;
				j++;
			}
		}
		else if(j > 0){
			j = F[j-1];
		}
		else//j already = 0
			i++;
		}
	return -1;
}
*/

int KMP(char T[], int n, char s[], int m){
	prefix_table(s, m);
	int i = 0, j = 0;
	//i points to T
	//j points to s
	while(i < n){
		if(T[i] == s[j]){
			if(j == m - 1)
				return i - j;
			else{
				i++;
				j++;
			}
		}
		else if(j > 0)
			j = F[j - 1];
		else
			i++;
	}
	return -1;
}

int main(){
	char T[] = "aofjlannvojac ofjocoafoxachvogfhapomcnoueropncnguyen tung lam0jrldasuf fjadsj f020rjfasjdfjas ";
    char s[] = "nguyen tung lam";
    int position = KMP(T, strlen(T), s, strlen(s));
    int i, x;
    for(i = 0, x = strlen(T); i < x; i++){
    	printf("%.2d ", i);
	}
	printf("\n");
	for(i = 0; i < x; i++){
		printf(" %c ", T[i]);
	}
	printf("\n");
	printf("position: %d\n", position);
	
	for(i = 0; i < strlen(s); i++){
		printf("%c", T[position++]);
	}
	printf("\n");
	
	return 0;

    return 0;
}
