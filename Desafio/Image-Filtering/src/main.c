#include "../include/Image.h"

int main (){
  struct Image imagem;
  Image(&imagem, 715, 1024, 1);
  read("mamografia-715x1024.jpg", &imagem);
  write("mamografia-715x1024.png", &imagem);
  freeIMG(&imagem);
}
