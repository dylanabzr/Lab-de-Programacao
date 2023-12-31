#include "firstfit.h"

void printLinkedList(struct MemSpace *first){
  int quantity = 0;
  for (struct MemSpace *i = first; i != NULL; i=i->next_space){
    quantity++;
    printf("O endereço inicial do item %d da lista é: %u. Já o tamanho do item é %lu e ele ", quantity, i->start_address, i->size);
    i->isOccupied?puts("está ocupado"):puts("está LIVRE");
  }
  printf("A quantidade de itens na lista é de %d\n", quantity);
}

void createRandomMemorySpace(struct MemSpace *first, unsigned start, unsigned end){
  first->start_address = start;
  first->size = rand()%end/3;
  struct MemSpace* firstcopy = first;
  while(firstcopy->size + firstcopy->start_address < end){
    struct MemSpace *n = malloc(sizeof(struct MemSpace));
    firstcopy->next_space = n;
    n->start_address = firstcopy->start_address + firstcopy->size;
    n->size = rand()%end/3;
    n->isOccupied = firstcopy->isOccupied?rand()%3:1;
    n->isOccupied = n->isOccupied%2;
    if ((n->size + n->start_address) >= end) {
      n->size -= (n->size + n->start_address) - end;
      n->next_space = NULL;
    }
    firstcopy = n;
  }
}

int addProcess_firstfit(struct MemSpace *head, size_t size, unsigned end){
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

int addProcess_bestfit(struct MemSpace *head, size_t size, unsigned end) {
  if (size > end) return 0;
  struct MemSpace *bestFit = NULL;
  size_t menor = end;

  for (struct MemSpace *i = head; i != NULL; i = i->next_space) {
    if (!(i->isOccupied) && i->size >= size) {
      size_t diferenca = i->size - size;
      if (diferenca < menor) {
        menor = diferenca;
        bestFit = i;
      }
    }
  }

  if (bestFit != NULL) {
    if (menor > 0) {
      struct MemSpace *newSpace = malloc(sizeof(struct MemSpace));
      newSpace->next_space = bestFit->next_space;
      bestFit->next_space = newSpace;
      newSpace->size = menor;
      newSpace->start_address = bestFit->start_address + size;
      newSpace->isOccupied = 0;
    }
    bestFit->size = size;
    bestFit->isOccupied = 1;
    return 1;
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
