#include <stdio.h>

int main (){
	float x;
	printf("Digite um valor real: ");
	scanf("%f", &x);
	printf("Com apenas uma casa decimal ele fica: %.1f\n", x);
	return 0;
}
