#include <stdio.h>

int main(){
  puts("Os quadrados dos números inteiros múltiplos de 4 de 15 a 90 são: ");
  for(int i = 15; i <=90; i++)
    if (!(i%4))
      printf("%d\n", i*i);
  return 0;
}
