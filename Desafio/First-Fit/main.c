#include "firstfit.h"

int main(){
  srand(time(NULL));
  struct MemSpace head;
  int max_address = 2000;
  createRandomMemorySpace(&head, 0, max_address);
  printLinkedList(&head);
  int (*addProcess[2])(struct MemSpace *head, size_t size, unsigned end) = {addProcess_firstfit, addProcess_bestfit};
  int qtd = 1;
  int index = -1;
  while (index != 1 && index){
    puts("Digite qual algoritmo deseja usar: [0: FirstFit; 1: BestFit]");
    scanf("%d", &index);
    if (index != 1 && index){
      puts("Algoritmo inválido, insira novamente.");
    }
  }
  while(qtd){
    printf("Digite o quando de memoria você deseja alocar (0 para sair): ");
    scanf("%d", &qtd);
    if(qtd){
      if(!(addProcess[index](&head, qtd, max_address))) puts("\n\t\tNão foi possível alocar em nenhum espaço.");
      puts("Lista atualizada: ");
      printLinkedList(&head);
    }
  }
  freeLinkedList(&head);
}


