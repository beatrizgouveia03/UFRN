#include<stdio.h>

int main()
{
	int numero1;
	int numero2;
	int numero3;

	scanf("%d %d %d", &numero1, &numero2, &numero3);

	if (numero1<numero2 && numero1<numero3){
		printf("%d\n", numero1);
		if (numero2<numero3){printf("%d\n %d\n", numero2, numero3);}
		else{printf("%d\n %d\n", numero3, numero2);}
	}
	else if (numero2<numero1 && numero2<numero3){
		printf("%d\n", numero2);
		if (numero1<numero3){printf("%d\n %d\n", numero1, numero3);}
		else{printf("%d\n %d\n", numero3, numero1);}
	}
	else if (numero3<numero1 && numero3<numero2){
		printf("%d\n", numero3);
		if (numero1<numero2){printf("%d\n %d\n", numero1, numero2);}
		else{printf("%d\n %d\n", numero2, numero1);}
	}

	printf(" \n %d\n %d\n %d\n", numero1, numero2, numero3);

	return 0;
}
