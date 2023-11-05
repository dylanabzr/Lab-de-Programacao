#include <stdio.h>

char *my_strcpy(char *dest, const char *src){
  int i;
  for (i = 0; *(src+i) != '\0'; i++){
    *(dest+i) = *(src+i);
  }
  *(dest+i) = '\0';
  return dest;
}

int main(){
  char *a = "opa";
  char b[4] = "aii";
  printf("a: %s e b: %s\n", a, b);
  my_strcpy(b, a);
  printf("Pós strcpy: a: %s e b: %s\n", a, b);
  return 0;
}
