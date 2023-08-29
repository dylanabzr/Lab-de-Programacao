#include <stdio.h>

int factorial(int n){
	if (n <= 1) return 1;
	return n * factorial(n-1);
}

int main(){
	int num;
	printf("Digite um número: ");
	scanf("%d", &num);
	printf("O fatorial de %d é %d\n", num, factorial(num));
	return 0;
}
