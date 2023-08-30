#include <stdio.h>

int maior(int a, int b){
  return(a *(a>b) + b *(b>=a)); 
}
int menor(int a, int b){
  return(a * (a<b) + b *(b<=a));
}

int main(){
  int num, maior_v = 0, menor_v = 0;
  while(1){
    printf("Digite um número: ");
    scanf("%d", &num);
    if (!maior_v) maior_v = num;
    else if (!num) break;
    else maior_v = maior(num, maior_v);
    if (!menor_v) menor_v = num;
    else menor_v = menor(num, menor_v);
    printf("O maior número digitado foi %d\nO menor número digitado foi %d\n", maior_v, menor_v);    
  }
  return 0;
}
