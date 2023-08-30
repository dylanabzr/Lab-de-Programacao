#include <stdio.h>

int main(){
	int x, y = 0;
	printf("Digite um número: ");
	scanf("%d", &x);
	while(!y){
	printf("Digite outro número: ");
	scanf("%d", &y);
	if (!y) 
		printf("Não é possível fazer divisão por zero. ");
	}
	printf("A divisão entre %d e %d é %.2f\n", x, y, x/(float)y);
	return 0;
}
