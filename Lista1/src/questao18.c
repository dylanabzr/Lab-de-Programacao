#include <stdio.h>

int main (){
  int raio;
  const float pi = 3.14159;
  float circunferencia, area;

  printf("Digite o comprimento do raio do círculo (em cm): ");
  scanf("%d", &raio);
  printf("O diâmetro do círculo é: %.0f cm.\nO tamanho da circunferência é: %.2f cm.\nA área da circunferência é: %.2f cm quadrados.\n", 
         (float)raio*2, 2*pi*raio, pi*raio*raio);
  return 0;

}
