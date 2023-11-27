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
int addProcess_firstfit(struct MemSpace *head, size_t size, unsigned end);
int addProcess_bestfit(struct MemSpace *head, size_t size, unsigned end);
void freeLinkedList(struct MemSpace *head);


