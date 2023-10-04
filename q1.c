#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criarVetorAleatorio(int *vetor, size_t tamanho){
  srand(time(NULL));
	for (int i = 0; i < tamanho; i++){
		*(vetor+i) = rand()%100;
	}
}

int** enderecoMaiorMenor(int *vetor, size_t tamanho){
	int **enderecos = NULL;
  if(!(enderecos = malloc(sizeof(int*) * 2))){
    fprintf(stderr, "Erro");
    exit(1);
  }

  *enderecos = *(enderecos+1) = vetor;
	for (int i = 0; i < tamanho; i++){
		if(*(vetor+i) <= *(*enderecos)) *enderecos = vetor+i;
    if(*(vetor+i) >= *(*(enderecos+1))) *(enderecos+1) = vetor+i;
	}
  return enderecos;
}
int main(){
	int n;
	printf("Digite o tamanho do vetor; ");
	scanf("%d", &n);
	int *ptr = NULL;
	if (!(ptr = malloc(sizeof(int) * n))){
		fprintf(stderr, "Erro, tamanho escolhido é muito grande.\n");
		exit(1);
	}
	criarVetorAleatorio(ptr, n);
	for (int i = 0; i < n; i++){
		printf("%d ", *(ptr+i));
	}
	puts("");
	int **enderecos = enderecoMaiorMenor(ptr, n);
	printf("O maior inteiro no vetor é: %d e seu endereço é %p\n", *(*(enderecos+1)), *(enderecos+1));
	printf("O menor inteiro no vetor é: %d e seu endereço é %p\n", *(*enderecos), *enderecos);

}
