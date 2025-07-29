#include <stdio.h>

int main()
{
	double salario_atual;
	double acrescimo;
	int incremento;

	scanf("%lf", &salario_atual);

	if (salario_atual >= 0.0 && salario_atual <= 400.00){
		incremento = 15;
		acrescimo = salario_atual*0.15;
	}
	else if(salario_atual > 400 && salario_atual <= 800.00){
		incremento = 12;
		acrescimo = salario_atual*0.12;
	}
	else if(salario_atual > 800.00 && salario_atual <= 1200.00){
		incremento = 10;
		acrescimo = salario_atual*0.1;
	}
	else if(salario_atual > 1200.00 && salario_atual <= 2000.00){
		incremento = 7;
		acrescimo = salario_atual*0.07;
	}
	else if(salario_atual > 2000.00){
		incremento = 4;
		acrescimo = salario_atual*0.04;
	}

	printf("Novo salario: %.2lf\n", salario_atual+acrescimo);
	printf("Reajuste ganho: %.2lf\n", acrescimo);
	printf("Em percentual: %d %%\n", incremento);

	return 0;
}