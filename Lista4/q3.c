#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(){
  int *input = malloc(sizeof(int)), *menor = malloc(sizeof(int));
  *menor = INT_MAX;
  while(1){
    printf("Digite um número inteiro(0 para sair): ");
    scanf("%d", input);
    if (!(*input)) break;
    *menor = *input<*menor?*input:*menor;
    printf("O menor número digitado foi %d\n", *menor);
  }
  free(input);
  free(menor);
  return 0;
}
