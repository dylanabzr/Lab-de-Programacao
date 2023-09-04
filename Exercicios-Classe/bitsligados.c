#include <stdio.h>
#define BITS 8

int main(){
  unsigned char x = 0b11000110, y;
  for(unsigned char i = BITS; i>0;i--){
    y = x << 1;
    y >>= 1;
    if (y != x)
      printf("ligado = %d\n", i);
    x = x << 1;
  }
  return 0;
}
