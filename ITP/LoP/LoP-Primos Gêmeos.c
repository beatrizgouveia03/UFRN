#include <stdio.h> 

int primo(int num){
	int divisor = 1;
	for(int x = 1; x<=num; x++){
		if(num%x == 0){divisor *= x;}
	}
	if(num == divisor && num != 1){return 0;}
	else{return 1;}

}

int main(){
	int numero;

	scanf("%d", &numero);

	if(primo(numero) == 0 && primo(numero+2) == 0){printf("Numero forma par de gemeos\n");}
	else{printf("Numero nao forma par de gemeos\n");}
}