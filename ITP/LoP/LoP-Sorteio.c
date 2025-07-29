#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char* nome;
} cadastro;

int main(void) {
  char* fim  = "acabou";
  int N = 0, indice_participante, S;
  char nome[50];
  char** participantes;

  participantes = malloc(sizeof(char *) * N);
    
  fgets(nome, 50, stdin);
  nome[strlen(nome)-1] = '\0';
  
  while(strcmp(fim,nome)){
    N++;
    participantes = realloc(participantes, sizeof(char *)*(N));
    participantes[N-1] = malloc(sizeof(char)*strlen(nome));
    strcpy(participantes[N-1],nome); 

    fgets(nome,50,stdin);
    nome[strlen(nome)-1] = '\0';
  }

  scanf("%d", &S);
  
  while(participantes != NULL){
    indice_participante = S%N;
    printf("%s\n", participantes[indice_participante]);
    char** novo;
    int cont = 0;
    novo = malloc(sizeof(char *)*(N));
    for(int i=0;i<=N;i++){
      if(i != indice_participante){
        novo[cont] = malloc(sizeof(char)*strlen(participantes[i]));
        strcpy(novo[cont], participantes[i]);
        cont++;
      }
      free(participantes[i]);
    }
    free(participantes);
    participantes = novo;
    N=cont;
  }
  return 0;
}