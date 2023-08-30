#include <stdio.h>

#define NUMC1 5
#define NUMC2 7

void votos(int voto, int *candidato1, int *candidato2, int *nulo){
        switch(voto){
	case NUMC1:
		*candidato1+=1;
		break;
	case NUMC2:
		*candidato2+=1;
		break;
	default:
		*nulo+=1;
		break;
	}
}

int main(){
	int tmp, candidato1 = 0, candidato2 = 0, nulo = 0;
	while(1){
		tmp = 0;
		printf("Digite seu voto: ");
		scanf("%d", &tmp);
		if (tmp<0) break;
		else votos(tmp, &candidato1, &candidato2, &nulo);
        }
	int votostotais = candidato1 + candidato2 + nulo;
	printf("%.2f%% dos votos foram para Paulo, %.2f%% para Renata e %.2f%% foram votos nulos\n", (float)candidato1/votostotais*100, (float)candidato2/votostotais*100, (float)nulo/votostotais*100);
	if (candidato1 != candidato2)
		printf("O(a) vencedor(a) foi %s\n", candidato1>candidato2?"Paulo":"Renata");
	else
		printf("Os candidatos empataram!\n");
	return 0;
}
