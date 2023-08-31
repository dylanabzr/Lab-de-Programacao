#include <stdio.h>

int main (){
	int x;
	printf("Digite um valor inteiro X: ");
	scanf("%d", &x);
	printf("O triplo de X é %d\nO quadrado de X é %d\nA metade de X é %.3f\n", 3*x, x*x, (float)x/2);
	return 0;
}
