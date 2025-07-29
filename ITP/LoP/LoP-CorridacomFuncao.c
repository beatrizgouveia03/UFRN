#include <stdio.h>

int corrida(int x, int v1, int v2){
	int aux = 0;
	for(int y = 0; y < 100; y++){
		if(v1*y == v2*y+x){return y; aux++; break;}
	}
	if(aux == 0){return 0;}
}

int main(){
	int x, v1, v2;

	scanf("%d %d %d", &x, &v1, &v2);

	if(corrida(x, v1, v2)==0){printf("impossivel\n");}
	else{printf("%ds\n", corrida(x, v1, v2));}
}