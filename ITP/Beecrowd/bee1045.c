#include <stdio.h>
#include <math.h>

int main(){
	double a;
	double b;
	double c;
	double lado_a;
	double lado_b; 
	double lado_c;

	scanf("%lf %lf %lf", &a, &b, &c);

	if(a<=b && a<=c){
		lado_c = a;
		if (b<=c){
			lado_b = b;
			lado_a = c;
		}
		else{
			lado_b = c;
			lado_a = b;
		}
	}
	else if(b<=a && b<=c){
		lado_c = b;
		if (a<=c){
			lado_b = a;
			lado_a = c;
		}
		else{
			lado_b = c;
			lado_a = a;
		}
	}
	else if(c<=a && c<=b){
		lado_c = c;
		if (a<=b){
		 	lado_b = a;
		 	lado_a = b;
		 } 
		else{
			lado_b = a;
			lado_a = b;
		}
	}

	if (lado_a >= (lado_b+lado_c)){
		printf("NAO FORMA TRIANGULO\n");

	}
	else {
		if (pow(lado_a,2) == pow(lado_b,2)+pow(lado_c,2)){
			printf("TRIANGULO RETANGULO\n");
		}
		if (pow(lado_a,2) > pow(lado_b,2)+pow(lado_c,2)){
			printf("TRIANGULO OBTUSANGULO\n");
		}
		if (pow(lado_a,2) < pow(lado_b,2)+pow(lado_c,2)){
			printf("TRIANGULO ACUTANGULO\n");
		}
		if (lado_a==lado_b && lado_b==lado_c){
			printf("TRIANGULO EQUILATERO\n");
		}
		if (lado_a==lado_b && lado_b!=lado_c){
			printf("TRIANGULO ISOSCELES\n"); 
		}
		else if (lado_a==lado_c && lado_b!=lado_c){
			printf("TRIANGULO ISOSCELES\n"); 
		}
		else if (lado_c==lado_b && lado_a!=lado_c){
			printf("TRIANGULO ISOSCELES\n"); 
		}
	}

	return 0;
}