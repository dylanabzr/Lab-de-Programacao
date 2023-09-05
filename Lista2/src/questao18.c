#include <stdio.h>

int main (){
  unsigned long x = 1, soma = 0;
  for (unsigned i = 0; i < 64; i++)
    soma += x << i;
  printf("%lu\n", soma);
}
