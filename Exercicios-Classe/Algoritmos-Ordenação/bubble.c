#include <stdio.h>
#define TAMANHO 11
void bubbleSort(int *lista, size_t size){
	while(size){
		size--;
		for(int i = 0; i < size; i++){
			if(lista[i] > lista[i+1]){
				lista[i] = lista[i] ^ lista[i+1];
				lista[i+1] = lista[i] ^ lista[i+1];
				lista[i] = lista[i] ^ lista[i+1];
			}
		}
	}
}

int main(){
	int lista[TAMANHO] = {9 , 8,7,3, 2, 4, 5, 1, 15, 21, 32};
	bubbleSort(lista, TAMANHO);
	for (int i = 0; i < TAMANHO; i++)
		printf("%d\n", lista[i]);
}
