#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criarVetorAleatorio(int *vetor, size_t tamanho){
	srand(time(NULL));
	for (int i = 0; i < tamanho; i++){
		*(vetor+i) = rand()%100;
	}
}

void criarVetorMedia(int *src, int *dest, size_t size){
	*dest = 0;
	*(dest + size -1) = 0;
	for (int i = 1; i < size-1; i++){
		*(dest+i) = (*(src + i - 1) + *(src+i) + *(src + i + 1))/3;
	}
}

int main(){
	int n;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	int *X = malloc(sizeof(int) * n);
	int *Y = malloc(sizeof(int) * n);
	if(!X || !Y){
		fprintf(stderr, "Erro, tamanho do array é muito grande.\n");
		exit(1);
	}
	criarVetorAleatorio(X, n);
	puts("O vetor X é:");
	for(int i = 0; i < n; i++){
		printf("%d ", *(X+i));	
	}
	criarVetorMedia(X, Y, n);
	puts("\nO vetor Y é:");
	for(int i = 0; i < n; i++){
		printf("%d ", *(Y+i));	
	}
	puts("");
}
