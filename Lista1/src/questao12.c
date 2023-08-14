#include <stdio.h>

int main (){
	int x, y;
	printf("Digite um número X: ");
	scanf("%d", &x);
	printf("Digite um número Y: ");
	scanf("%d", &y);
	printf("A soma entre X e Y é %d\nO produto entre X e Y é %d\nA diferença entre X e Y é %d\n", x+y, x*y, x-y);
	printf("O quociente da divisão entre X e Y é %d, já o resto, é %d\n", x/y, x%y);
	return 0;
}
