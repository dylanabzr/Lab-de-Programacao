#include <stdio.h>

int main(){
	int horas, minutos, segundos;
	printf("Digite uma quantidade de horas: ");
	scanf("%d", &horas);
	printf("Digite uma quantidade de minutos: ");
	scanf("%d", &minutos);
	printf("Digite uma quantidade de segundos: ");
	scanf("%d", &segundos);
	printf("O total de segundos é: %d\n", ((horas*60)+minutos)*60 + segundos);
	return 0;
}
