#include <stdio.h>

int main(){
	int hostis, agua, deserto, vegetacao, nada;
	int linhas, colunas, elementos = 0;
	char elemento;

	scanf("%d %d", &linhas, &colunas);

	char mapa[linhas][colunas];
	hostis = agua = deserto = vegetacao = nada = 0;

	for(int x=0; x<linhas; x++){
		for(int y=0; y<colunas; y++){
			scanf(" %c", &mapa[x][y]);
		}
	}

	for(int x=0; x<linhas; x++){
		for(int y=0; y<colunas; y++){
			elemento = mapa[x][y];
			switch(elemento){
				case '~': agua++;break;
				case 'X': hostis++;break;
				case '^': deserto++;break;
				case '*': vegetacao++;break;
				case '.': nada++;break;
			}
			elementos++;
			printf("%c\n", mapa[x][y]);
		}
		printf("\n");
	}
	if(hostis != 0){printf("Planeta Hostil\n");}
	else if(agua >= 0.85*elementos){printf("Planeta Aquático\n");}
	else if(deserto >= 0.6*elementos){printf("Planeta Desértico\n");}
	else if(vegetacao >= 0.65*elementos){printf("Planeta Selvagem\n");}
	else if(agua >= 0.5*elementos && vegetacao >= 0.2*elementos){printf("Planeta Classe M\n");}
	else{printf("Planeta Inóspito\n");}

	return 0;
}