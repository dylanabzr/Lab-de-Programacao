#include <stdio.h>

int main(){
	int altura_centimetros[3], centimetros_por_ano[3], maior = 0, anos = 0;
	char nome_pessoa[2][30];
	for (int i = 0; i<2; i++){
	  printf("Digite o nome da pessoa %d: ", i+1);
	  scanf("%s", nome_pessoa[i]);
	  printf("Digite a altura em centímetros do %s: ", nome_pessoa[i]);
	  scanf("%d", &altura_centimetros[i]);
	  printf("Digite quantos centímetros ele cresce por ano: ");
	  scanf("%d", &centimetros_por_ano[i]);
	}
	if (centimetros_por_ano[1] > centimetros_por_ano[0]) maior = 1;
	for (anos = 0; (altura_centimetros[!maior] + centimetros_por_ano[!maior] * anos) >= (altura_centimetros[maior] + centimetros_por_ano[maior] * anos); anos++);
	printf("em %d anos %s irá passar a altura de %s\n", anos, nome_pessoa[maior], nome_pessoa[!maior]);

}
