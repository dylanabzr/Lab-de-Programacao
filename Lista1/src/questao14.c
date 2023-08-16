#include <stdio.h>

int main(){
  int celcius;
  printf("Digite uma temperatura em graus Celcius: ");
  scanf("%d", &celcius);
  printf("%d graus Celcius correspondem a %.2f graus Fahrenheit\n", celcius, ((9 * (float) celcius + 160)/5));
}
