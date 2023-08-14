#include <stdio.h>

int main(){
	float conta;
	printf("Digite o valor da conta: ");
	scanf("%f", &conta);
	printf("O valor a ser pago é: %.2f\n", conta*1.1);
	return 0;
}
