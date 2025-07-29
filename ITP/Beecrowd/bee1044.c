#include <stdio.h>

int main()
{
	int num1;
	int num2;
	int resto;

	scanf("%d %d", &num1, &num2);

	resto = num2%num1;

	if (resto == 0){
		printf("Sao Multiplos\n");
	}
	else{
		printf("Nao sao Multiplos\n");
	}

	return 0;
}
/* Erro de formamtação na saída a ser descoberto*/