#include <stdio.h>

int main(){
	int numdia = 0;
	char dias[8][14] = {"Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sábado"};
	do{
	printf("Digite um número: ");
	scanf("%d", &numdia);
	if ((numdia <= 7) && (numdia > 0))
		printf("%s\n", dias[numdia-1]);
	else if (!numdia)
		continue;
	else
		printf("Valor inválido.\n");
	}
	while(numdia);
}
