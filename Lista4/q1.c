#include <stdio.h>
#include <stdlib.h>

void sum(int *n1, int *n2, int *destination){
  *destination = *n1 + *n2;
}

int main(){
  int a = 5, b = 10;
  int res;
  sum(&a, &b, &res);
  printf("O resultado da soma entre %d e %d é: \n", a, b);
  printf("[%p] %d\n", &res, res);
}
