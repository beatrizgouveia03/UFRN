#include<stdio.h>
 
int l1, l2 ,l3;

int valido(int l1, int l2, int l3){
	if(l1>=l2+l3 || l2 >= l1+l3 || l3 >= l1+l2){return 0;}
	else{return 1;}
}

int tipo(int l1, int l2, int l3){
	if(l1 == l2 && l2 == l3){return 0;}
	else if(l1 == l2 || l2 == l3 || l1 == l3){return 1;}
	else{return 2;}
}

int retangulo(int l1, int l2, int l3){
	if(l1>l2 && l1 > l3 && l1*l1 == l2*l2+l3*l3){
		return 0;}
	else if(l2>l1 && l2>l3 && l2*l2 == l1*l1+l3*l3){
		return 0;}
	else if(l3>l1 && l3>l2 & l3*l3 == l1*l1 + l2*l2){
		return 0;
	}
}

int main(){
	scanf("%d %d %d", &l1 ,&l2, &l3);

	switch(valido(l1,l2,l3)){
		case 0: printf("Invalido\n"); break;
		case 1: switch(tipo(l1,l2,l3)){
			case 0: printf("Valido-Equilatero\n"); break;
			case 1: printf("Valido-Isoceles\n"); break;
			case 2: printf("Valido-Escaleno\n"); break;
		}
		if(retangulo(l1,l2,l3) == 0){printf("Retangulo: S\n");}
		else{printf("Retangulo: N\n");}
	}
}