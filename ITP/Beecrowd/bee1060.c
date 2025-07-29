#include<stdio.h>

int main(){
	float numero;
	int positivos = 0;

	for(int i = 0; i<6; i++){
		scanf("%f", &numero);
		if(numero>0){positivos++;}
	}
	printf("%d valores positivos\n", positivos);
}