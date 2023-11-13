#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
  int x, y;
  struct Node *next;
};

struct Node * menor_diferenca(struct Node *);
void createNode(struct Node *, int, int, struct Node *);

int main(){
  srand(time(NULL));
  struct Node h, n1, n2, n3, n4;
  h.next = &n1;
  createNode(&n1, rand()%11, rand()%11, &n2); 
  createNode(&n2, rand()%11, rand()%11, &n3);
  createNode(&n3, rand()%11, rand()%11, &n4);
  createNode(&n4, rand()%11, rand()%11, NULL);
  printf("n1: %d, %d e seu endereço é %p\n", n1.x, n1.y, &n1);
  printf("n2: %d, %d e seu endereço é %p\n", n2.x, n2.y, &n2);
  printf("n3: %d, %d e seu endereço é %p\n", n3.x, n3.y, &n3);
  printf("n4: %d, %d e seu endereço é %p\n", n4.x, n4.y, &n4);
  printf("O endereço da estrutura com a menor diferença é %p\n", menor_diferenca(&h));
}


struct Node * menor_diferenca(struct Node *head){
  struct Node *endereco = head->next;
  int menor = abs(head->next->x - head->next->y);
  for(struct Node* i = head->next->next; i != NULL; i=i->next){
    if (abs(i->x - i->y) < menor){
      endereco = i;
      menor = abs(i->x - i->y);
    }
  }
  return endereco;
}

void createNode(struct Node * node, int x, int y, struct Node * next){
  node->x = x;
  node->y = y;
  node->next = next;
}
