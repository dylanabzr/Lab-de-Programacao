#include <stdio.h>

int main(){
	int a, b;
	printf("Digite um valor para a variável A: ");
	scanf("%d", &a);
	printf("Digite um valor para a variável B: ");
	scanf("%d", &b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("Agora o valor de A é %d e o valor de B é %d\n", a, b);
}
