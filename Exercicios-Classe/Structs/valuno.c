#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_ALUNOS 5
#define QTD_NOTAS 3

struct Aluno {
  char matricula[12];
  double nota[QTD_NOTAS];
};

double media_do_aluno (struct Aluno, size_t size);

int main(){
  srand(time(NULL));
  struct Aluno alunos[QTD_ALUNOS];
  for (int i = 0; i < QTD_ALUNOS; i++){
    for (int j = 0; j < QTD_NOTAS; j++){
      alunos[i].nota[j] = ((float)rand()/RAND_MAX) * 10;
    }
    printf("A média do aluno %d é: %.1lf\n", i+1, media_do_aluno(alunos[i], QTD_NOTAS));
  }
  return 0;
}

double media_do_aluno (struct Aluno aluno, size_t size){
  double sum = 0;
  for (int i = 0; i < size; i++)
    sum += aluno.nota[i];
  return sum/size;
}

