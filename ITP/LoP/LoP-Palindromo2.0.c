#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int teste(char* entrada){
    int dif = 0;
    for(int i=0; i<strlen(entrada)/2;i++){
        if(entrada[i] != entrada[strlen(entrada)-1-i]){
            dif = 1;
            break;
        }
    }

    if(dif){return 0;}
    else{return 1;}
}

int palindromo(char *entrada){
    char* frase;
    int cont = 0;

    frase = malloc(sizeof(char)*cont);

    for(int i=0;i<strlen(entrada);i++){
        if(entrada[i] != ' '){
            frase = realloc(frase, sizeof(char)*cont+1);
            frase[cont] = entrada[i];
            cont++;
        }
    }

    if(teste(frase)){return 1;}
    else{return 0;}
}

int main(){
    char entrada[50];

    fgets(entrada,50,stdin);
    entrada[strlen(entrada)-1] = '\0';

    if(palindromo(entrada)){
        printf("O texto \"%s\" é palíndromo\n", entrada);
    }
    else{
        printf("O texto \"%s\" não é palíndromo\n", entrada);
    }

    return 0;
} 