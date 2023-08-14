#include <stdio.h>

int main(){
	int comprimento, altura, largura;
	printf("Digite o comprimento da caixa em cm: ");
	scanf("%d", &comprimento);
	printf("Digite a altura da caixa em cm: ");
	scanf("%d", &altura);
	printf("Digite a largura da caixa em cm: ");
	scanf("%d", &largura);
	printf("O volume da caixa é de %d centimetros cúbicos\n", comprimento*altura*largura);
	return 0;
}
