#include <stdio.h>

int ckn(int k, int n){
	if(k == 0 || k == n)
		return 1;
	return ckn(k - 1, n - 1) + ckn(k, n - 1);
}

int main(){
	int n, int k;
	printf("Enter n: ");
	scanf("%d", &n);
	printf("Enter k: ");
	scanf("%d", &k);

	printf("ckn: %d", ckn(k, n));
	return 0;
}