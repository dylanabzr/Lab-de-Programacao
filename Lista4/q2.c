#include <stdio.h>
#include <stdlib.h>

void swapint(int *a, int *b){
  *a = *a^*b;
  *b = *a^*b;
  *a = *a^*b;
}

int main(){
  int a = 10, b = 5;
  printf("Valor de a e b antes da troca são, respectivamente, %d e %d\n", a, b);
  swapint(&a, &b);
  printf("Valor de a e b após a troca são, respectivamente, %d e %d\n", a, b);
}
