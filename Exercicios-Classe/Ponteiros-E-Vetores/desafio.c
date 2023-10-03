#include <stdio.h>
#include <stdlib.h>

void selectionSort(int * array, size_t size){
	for (int i = 0; i < size; i++){
    		for (int j = (i+1); j < size; j++){
      			if (array[i] < array[j]){
        			array[i]= array[i] ^ array[j];
        			array[j] = array[i] ^ array[j];
        			array[i] = array[i] ^ array[j];
      }
    }
  }
}

void criarVetorAleatorio(int *vetor, size_t tamanho){
	for (int i = 0; i < tamanho; i++){
		*(vetor+i) = rand()%100;
	}
}

int main(){
	int n;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	int *ptr = malloc(sizeof(int) * n);
	if(!ptr){
		fprintf(stderr, "Erro, tamanho escolhido é muito grande.");
		exit(1);
	}
	criarVetorAleatorio(ptr, n);
	selectionSort(ptr, n);
	int *enderecos[n];
	for (int i = 0; i < n; i++){
		enderecos[i] = ptr+i;
	}
	puts("O vetor organizado é: ");
	for (int i = 0; i < n; i++){
		printf("[%p] %d\n", (ptr+i), *(ptr+i));
	}
	puts("\nOs endereços organizados são: ");
	for (int i = 0; i < n; i++){
		printf("[%p]\n", enderecos[i]);
	}
	return 0;
}
