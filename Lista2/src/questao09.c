#include <stdio.h>

int fibonacci(unsigned termo){
  if (termo <= 2)
    return 1;
  else
    return fibonacci(termo-1) + fibonacci(termo-2);
}

int main(){
  unsigned n;
  puts("Digite um número: ");
  scanf("%u", &n);
  printf("A sequencia de fibonacci até o termo %u é: ", n);
  for(unsigned i = 1; i <= n; i++)
    printf("\n%d", fibonacci(i));
  puts("");
  return 0;
}
