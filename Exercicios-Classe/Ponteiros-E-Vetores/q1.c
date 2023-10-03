#include <stdio.h>
#include <stdlib.h>

void criarVetorAleatorio(int *vetor, size_t tamanho){
	for (int i = 0; i < tamanho; i++){
		*(vetor+i) = rand()%100;
	}
}

int *enderecoMaiorInteiro(int *vetor, size_t tamanho){
	int maior = *vetor;
	int *maior_endereco = NULL;
	for (int i = 1; i < tamanho; i++){
		if(*(vetor+i) >= maior) {
			maior = *(vetor + i);
			maior_endereco = vetor+i;
		}
	}
	return maior_endereco;
}

int *enderecoMenorInteiro(int *vetor, size_t tamanho){
	int menor = *vetor;
	int *menor_endereco = NULL;
	for (int i = 1; i < tamanho; i++){
		if(*(vetor+i) <= menor) {
			menor = *(vetor + i);
			menor_endereco = vetor+i;
		}
	}
	return menor_endereco;
}
int main(){
	int n;
	printf("Digite o tamanho do vetor; ");
	scanf("%d", &n);
	int *ptr = malloc(sizeof(int) * n);
	if (!ptr){
		fprintf(stderr, "Erro, tamanho escolhido é muito grande.\n");
		exit(1);
	}
	criarVetorAleatorio(ptr, n);
	for (int i = 0; i < n; i++){
		printf("%d ", *(ptr+i));
	}
	puts("");
	int *maior_ptr = enderecoMaiorInteiro(ptr, n); 
	int *menor_ptr = enderecoMenorInteiro(ptr, n);
	printf("O maior inteiro no vetor é: %d e seu endereço é %p\n", *maior_ptr, maior_ptr);
	printf("O menor inteiro no vetor é: %d e seu endereço é %p\n", *menor_ptr, menor_ptr);

}
