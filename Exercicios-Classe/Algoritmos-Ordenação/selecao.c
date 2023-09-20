#include <stdio.h>
#define TAMANHO 7
float mediana(int *lista, size_t size){
	if(size%2)
		return(lista[size/2]);
	return (lista[size/2 -1] + lista[size/2])/(float)2;
}

void selectionSort(int * lista, size_t size){
	for (int i = 0; i < size; i++){
                for (int j = (i+1); j < size; j++){
                        if (lista[i] < lista[j]){
                                lista[i]= lista[i] ^ lista[j];
                                lista[j] = lista[i] ^ lista[j];
                                lista[i] = lista[i] ^ lista[j];
                        }
                }
        }
}
int main(){
	int lista[TAMANHO] = {10, 2, 21, 1, 3, 4, 11};
	selectionSort(lista, TAMANHO);
	for(int i = 0; i < TAMANHO; i++){
		printf("%d\n", lista[i]);
	}
	printf("a mediana é %.2f\n", mediana(lista, TAMANHO));
}
