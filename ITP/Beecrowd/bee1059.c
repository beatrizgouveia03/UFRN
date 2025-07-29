#include<stdio.h>

int main()
{
	int inicio = 1;
	int fim = 100;
	int i;

	for (i = inicio; i<=fim; i++){
		if(i%2 == 0){
			printf("%d\n", i);
		}
	}
	return 0;
}