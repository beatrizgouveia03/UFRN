#include <stdio.h>

int main()
{
	double nota1;
	double nota2;
	double nota3;
	double nota4;
	double media;
	double nota_exame;

	scanf("%lf %lf %lf %lf", &nota1, &nota2, &nota3, &nota4);

	media = (nota1*2 + nota2*3 + nota3*4 + nota4)/10;

	printf("Media: %.1lf\n", media);

	if(media >= 7.0){ printf("Aluno aprovado.\n");}

	else if(media < 5.0){printf("Aluno reprovado.\n");}

	else {
		printf("Aluno em exame.\n");

		scanf("%lf", &nota_exame);

		printf("Nota do exame: %.1lf\n", nota_exame);

		media = (media+nota_exame)/2;

		if(media >= 5.0){printf("Aluno aprovado.\n");}
		else if(media <=4.9){printf("Aluno reprovado.\n");}

		printf("Media final: %.1lf\n", media);
	}


	return 0;
}