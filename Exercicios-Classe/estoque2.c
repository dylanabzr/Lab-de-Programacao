#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 20

struct Produto{
  float preco;
  char *nome;
  char *uuid;
};

struct Estoque{
  struct Produto *produtos;
  int *qtd_por_produto;
};

struct Produto *maior_preco(struct Estoque, int);
void criarestoque(struct Estoque *, int);

int main(){
  int n;
  struct Estoque estoque;
  printf("Insira a quantidade de produtos: ");
  scanf("%d", &n);
  criarestoque(&estoque, n);
  struct Produto * maior = maior_preco(estoque, n);
  printf("O de maior preço é %s, que custa R$%.2f, está no endereço %p\n", maior->nome, maior->preco, maior); 
  for(int i = 0; i < n; i++) 
    free(estoque.produtos[i].nome);
  free(estoque.produtos);
}

struct Produto *maior_preco(struct Estoque estoque, int tamanho){
  struct Produto *maior = estoque.produtos;
  for (int i = 1; i < tamanho; i++)
    maior = maior->preco>estoque.produtos[i].preco?maior:&estoque.produtos[i];
  return maior;
}

char* gerarUUID(){
    char *buffer = NULL;
    size_t buffer_size = 0;
    if(!(buffer = malloc(sizeof(char) * 40))) exit(1);
    FILE *pipe = popen("uuidgen -r", "r");
    if (pipe == NULL) {
        perror("popen");
        exit(1);
    }
    ssize_t read;
    while ((read = getline(&buffer, &buffer_size, pipe)) != -1) {
        if (read > 0 && buffer[read - 1] == '\n') {
            buffer[read - 1] = '\0';
        }
    }
    pclose(pipe);
    return buffer;
}

void criarestoque(struct Estoque *estoque, int tamanho){
  if(!(estoque->produtos = malloc(sizeof(struct Produto) * tamanho))) exit(1);
  if(!(estoque->qtd_por_produto = calloc(sizeof(int), tamanho))) exit(1);
  for (int i = 0; i < tamanho; i++){
    if(!(estoque->produtos[i].nome = malloc(sizeof(char) * MAX_NAME_SIZE))) exit(1);
    printf("Digite o nome do produto %d: ", i+1);
    scanf("%s", estoque->produtos[i].nome);
    printf("Digite o preço em reais do produto %d: ", i+1);
    scanf("%f", &estoque->produtos[i].preco);
    printf("Digite a quantidade de %s no estoque: ", estoque->produtos[i].nome);
    scanf("%d", &estoque->qtd_por_produto[i]);
    estoque->produtos[i].uuid = gerarUUID();
    printf("UUID gerado: %s\n", estoque->produtos[i].uuid);
  }
}
