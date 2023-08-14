#include <stdio.h>

int main(){
	int x;
	printf("Digite um número inteiro X: ");
	scanf("%d", &x);
	printf("O sucessor de X é %d e o antecessor de X é %d\n", x+1, x-1);
	return 0;
}
