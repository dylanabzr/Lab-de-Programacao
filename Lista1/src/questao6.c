#include <stdio.h>

int main(){
	float altura_metros;
	char sexo;
	char sexos[3] = "MF";
	float peso_ideal;
	printf("Digite sua altura em metros: ");
	scanf("%f", &altura_metros);
	while(1){
		printf("Digite o seu sexo [M/F]: ");
		scanf(" %c", &sexo);
		if ((sexo == sexos[0]) || (sexo == sexos[1])){
			break;
		}
		else{
			printf("Sexo inválido\n");
		}
	}
	if (sexo == sexos[0]){
		peso_ideal = 72.7 * altura_metros - 58;
	}
	else{
		peso_ideal = 62.1 * altura_metros - 44.7; 
	}
	printf("Seu peso ideal (em kgs) é: %.2f\n", peso_ideal);
	return 0;
}
