#include "../include/Image.h"
#include "../include/Filter.h"

int main (){
  struct Image imagem;
  Image(&imagem, 715, 1024, 1);
  read("mamografia-715x1024.jpg", &imagem);
  filter3x3_average(&imagem);
  write("mamografia-715x1024.bmp", &imagem);
  freeIMG(&imagem);
}
