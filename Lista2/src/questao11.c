#include <stdio.h>
#include <stdlib.h>


int main(){
  unsigned a, b;
  puts("Forneça dois numeros: ");
  scanf("%u", &a);
  scanf("%u", &b);
  unsigned maior = a, menor = b;
  if(a < b){
    menor = a;
    maior = b;
  }
  printf("O quadrado dos números multiplos de 4 entre %d e %d são: \n", a, b);
  for (int i = menor; i <= maior; i++){
    if(!(i%4))
     printf("%d\n", i *i); 
  }

}
