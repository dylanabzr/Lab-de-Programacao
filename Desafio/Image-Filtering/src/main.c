#include "../include/Image.h"
#include "../include/Filter.h"
#include "../include/SCM.h"

int main (){
  struct Image imagem = readPGM("lena.pgm");
  struct Image filtrada = filter3x3_average(&imagem);
  savePGM("lena_filtered.pgm", &filtrada);
  unsigned char **matriz = CreateSCM(imagem, filtrada, 8);
  printMatrix(matriz, 8);
}
