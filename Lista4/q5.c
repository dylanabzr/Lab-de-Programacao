#include <stdio.h>

size_t my_strlen(const char *str){
  size_t i;
  for(i=0;;i++){
    if (*(str+i) == '\0')
      break;
  }
  return i;
}

int main(){
  char *string = "Opaaaa";
  printf("A string \"%s\" tem tamanho %lu\n", string, my_strlen(string));
}
