#include "../include/Image.h"
#include "../include/Filter.h"

int main (){
  struct Image imagem = readPGM("lena.pgm");
  filter3x3_average(&imagem);
  savePGM("teste.pgm", &imagem);
}
