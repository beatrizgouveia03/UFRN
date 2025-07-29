#include <stdio.h>

double calcNota(double n1, double n2, double n3){
	double soma = n1 + n2 + n3, aux;
	if(n1>=3 && n2>=3 && n3>=3 && soma <15){
		return 15-(n1+n2);
	}
	else{return -1;}
}

int main(){
	double nota1, nota2, nota3, aux;

	scanf("%lf %lf %lf", &nota1, &nota2, &nota3);

	if(nota1<nota2){aux=nota1;nota1=nota2;nota2=aux;}
	if(nota2<nota3){aux=nota2;nota2=nota3;nota3=aux;}
	if(nota1<nota3){aux=nota1;nota1=nota3;nota3=aux;}

	if(calcNota(nota1,nota2,nota3) != -1){
		printf("Final\n%.1lf\n", calcNota(nota1,nota2,nota3));
	}
	else{printf("Nao faz prova final\n");}
}