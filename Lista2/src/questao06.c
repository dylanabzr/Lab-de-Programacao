#include <stdio.h>

#define NUMC1 5
#define NUMC2 7

void votos(int voto, int *candidato1, int *candidato2, int *nulo, int *brancos){
  switch(voto){
    case NUMC1:
      ++*candidato1;
      break;
    case NUMC2:
      ++*candidato2;
      break;
    case 0:
      ++*brancos;
    default:
      ++*nulo;
      break;
    }
  }

int main(){
	int tmp, candidato1 = 0, candidato2 = 0, nulo = 0, brancos = 0;
	char SN[3] = "sS";
	char SouN;
	while(1){
		tmp = 0;
		printf("Digite seu voto: ");
		scanf("%d", &tmp);
		printf("Tem certeza [s/n]? ");
		scanf(" %c", &SouN);
		if (!(SouN==SN[0] || SouN==SN[1])) continue; 
		if (tmp<0) break;
		else votos(tmp, &candidato1, &candidato2, &nulo, &brancos);
        }
	int votostotais = candidato1 + candidato2 + nulo + brancos;
	printf("%.2f%% dos votos foram para Paulo, %.2f%% para Renata, %.2f%% foram votos brancos, %.2f%% foram votos nulos\n", (float)candidato1/votostotais*100, (float)candidato2/votostotais*100, (float)brancos/votostotais*100, (float)nulo/votostotais*100);
	if (candidato1 != candidato2)
		printf("O(a) vencedor(a) foi %s\n", candidato1>candidato2?"Paulo":"Renata");
	else
		printf("Os candidatos empataram!\n");
	return 0;
}


