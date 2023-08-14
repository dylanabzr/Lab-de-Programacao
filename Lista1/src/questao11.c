#include <stdio.h>

int main(){
	float dolar, reais;
	printf("Digite a cotação atual do dólar: ");
	scanf("%f", &dolar);
	printf("Digite quantos reais você deseja converter para dolar: ");
	scanf("%f", &reais);
	printf("Você terá %.2f dólares caso converta\n", reais/dolar);
	return 0;
}
