#include <stdio.h>

int main (){
	int x;
	printf("Digite o um número na base 10: ");
	scanf("%d", &x);
	printf("Na base 16: %x\nNa base 8: %o\n", x, x);
	return 0;
}
