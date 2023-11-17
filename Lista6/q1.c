#include <stdio.h>
#include <stdlib.h>

struct Aluno{
  float notas[2];
  float media;
};

int main(){
  struct Aluno fabio;
  puts("Digite a primeira nota do aluno: ");
  scanf("%f", fabio.notas);
  puts("Digite a segunda nota do aluno: ");
  scanf("%f", fabio.notas +1);
  fabio.media = (fabio.notas[0] + fabio.notas[1])/2;
  printf("Média do Fábio é: %.2f\n", fabio.media);
}
