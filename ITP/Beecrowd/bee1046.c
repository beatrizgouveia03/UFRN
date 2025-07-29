#include <stdio.h>

int main()
{
	int start_time;
	int finish_time;

	scanf("%d %d", &start_time, &finish_time);

	if (start_time < finish_time){
		printf("O JOGO DUROU %d HORA(S)\n", finish_time - start_time);
	}
	else if (start_time == finish_time){
		printf("O JOGO DUROU 24 HORA(S)\n");
	}
	else{
		printf("O JOGO DUROU %d HORA(S)\n", finish_time + (24 - start_time));
	}

	return 0;
}