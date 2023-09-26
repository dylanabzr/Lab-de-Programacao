#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MASK 1
char verificar(char armario, char pos){
	return ((armario>>pos) & MASK);
}

int main (){
	unsigned char armarios = 0, done = 1, x, y;
  srand(time(NULL));
	while(done){
    system("clear");
    for (unsigned char i = 0; i < 8; i++){
      if (verificar(armarios, i))
        printf("Armário %hhu está ocupado\n", i);
      else
        printf("Armário %hhu está desocupado\n", i);
    }
    puts("Você tem 3 opções: \n 1. Ocupar um armário aleatório\n 2. Liberar um armário a sua escolha\n 3. Sair");
    scanf("%hhu", &x);
    switch(x){
      default:
        puts("Opção inválida tente novamente");
        break;
      case 1:
        y = rand()%8;
        if (!verificar(armarios, y))
          armarios ^= MASK << y;
        break;
      case 2:
        puts("Escolha um armário para liberar: ");
          scanf("%hhu", &y);
          if (verificar(armarios, y))
            armarios ^= MASK << y;
        break;
      case 3:
        done = 0;
        break;
    }
	}
  system("clear");
  return 0;
}
