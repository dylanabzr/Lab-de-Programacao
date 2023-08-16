#include <stdio.h>

int main(){
  float salario_dia = 50.25;
  int dias_trabalhados;
  float valor_a_ser_pago;
  printf("Quantos dias o vendedor trabalhou? ");
  scanf("%d", &dias_trabalhados);
  valor_a_ser_pago = salario_dia * dias_trabalhados;
  if ((dias_trabalhados > 10) && (dias_trabalhados <= 20)){
    valor_a_ser_pago *= 1.2;
  }
  if (dias_trabalhados > 20){
    valor_a_ser_pago *= 1.3;
  }
  valor_a_ser_pago *= 0.9;
  printf("O valor a ser pago para o vendedor é de R$%.2f\n", valor_a_ser_pago);
}
