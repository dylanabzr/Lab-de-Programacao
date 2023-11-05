#include <stdio.h>

char * my_strcat (char *dest, const char *src){
  int i, j;
  for(i = 0; *(dest+i) != 0; i++){}
  for(j = 0; *(src + j) != 0; j++){
    *(dest+i+j) = *src;
  }
  *(dest + i + j) = '\0'; 
  return dest;
}
