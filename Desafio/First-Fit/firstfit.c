#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct MemSpace{
  unsigned start_address;
  size_t size;
  int isOccupied;
  struct MemSpace *next_space;
};

void createRandomMemorySpace(struct MemSpace *first, unsigned start, unsigned end);
void printLinkedList(struct MemSpace *first);
int addProcess(struct MemSpace *head, size_t size);
void freeLinkedList(struct MemSpace *head);

int main(){
  srand(time(NULL));
  struct MemSpace head;
  createRandomMemorySpace(&head, 0, 1000);
  printLinkedList(&head);
  int qtd = 1;
  while(qtd){
    printf("Digite o quando de memoria você deseja alocar (0 para sair): ");
    scanf("%d", &qtd);
    if(qtd){
      if(!(addProcess(&head, qtd))) puts("Não foi possível alocar em nenhum espaço.");
      puts("Lista atualizada: ");
      printLinkedList(&head);
    }
  }
  freeLinkedList(&head);
}

void printLinkedList(struct MemSpace *first){
  int quantity = 0;
  for (struct MemSpace *i = first; i != NULL; i=i->next_space){
    quantity++;
    printf("O endereço inicial do item %d da lista é: %u. Já o tamanho do item é %lu e ele ", quantity, i->start_address, i->size);
    i->isOccupied?puts("está ocupado"):puts("não está ocupado");
  }
  printf("A quantidade de itens na lista é de %d\n", quantity);
}

void createRandomMemorySpace(struct MemSpace *first, unsigned start, unsigned end){
  first->start_address = start;
  first->size = rand()%end/2;
  struct MemSpace* firstcopy = first;
  while(firstcopy->size + firstcopy->start_address < end){
    struct MemSpace *n = malloc(sizeof(struct MemSpace));
    firstcopy->next_space = n;
    n->start_address = firstcopy->start_address + firstcopy->size;
    n->size = rand()%end/2;
    n->isOccupied = firstcopy->isOccupied?rand()%2:1;
    if ((n->size + n->start_address) >= end) {
      n->size -= (n->size + n->start_address) - end;
      n->next_space = NULL;
    }
    firstcopy = n;
  }
}

int addProcess(struct MemSpace *head, size_t size){
  for (struct MemSpace *i = head; i != NULL; i=i->next_space){
    if (!(i->isOccupied)){
      if (size < i->size){
        struct MemSpace *n = malloc(sizeof(struct MemSpace));
        n->next_space = i->next_space;
        i->next_space = n;
        n->size = i->size - size;
        i->size = size;
        n->start_address = i->start_address + i->size;
        i->isOccupied = 1;
        n->isOccupied = 0;
        return 1;
      }
      if (size == i->size){
        i->isOccupied = 1;
        return 1;
      }
    }
  }
  return 0;
}

void freeLinkedList(struct MemSpace *head){
  struct MemSpace * next_ptr = head->next_space;
  for (struct MemSpace *i = next_ptr; i !=NULL; i = next_ptr){
    next_ptr = next_ptr->next_space;
    free(i);
  }
}
