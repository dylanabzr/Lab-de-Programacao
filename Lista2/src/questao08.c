#include <stdio.h>

int main(){
  float preco = 0, valor_entrada = 0;
  int prestacao = 0;

  puts("Digite o preço do produto que deseja comprar: ");
  scanf("%f", &preco);
  prestacao = (int)preco/3;
  valor_entrada = preco - 2*prestacao;
  printf("O valor da entrada é R$%.2f e o valor de cada uma das duas prestações é R$%d\n", valor_entrada, prestacao);
  return 0;
}
