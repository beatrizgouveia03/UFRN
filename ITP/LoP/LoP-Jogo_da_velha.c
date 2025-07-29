#include <stdio.h>

int vencer(char elem, int x, int y, char matriz[3][3]){
  //Testa se o jogo é vencido na linha
  if(matriz[x][0] == elem && matriz[x][1] == elem && matriz[x][2] == elem){
    return 1;
  }
  //Testa se o jogo é vencido na coluna
  else if(matriz[0][y] == elem && matriz[1][y] == elem && matriz[2][y] == elem){
    return 1;
  }
  //Testa se o jogo é vencido na diagonal principal
  else if(matriz[0][0] == elem && matriz[1][1] == elem && matriz[2][2] == elem){
    return 1;
  }
 //Testa se o jogo é vencido na diagonal secundária
  else if(matriz[0][2] == elem && matriz[1][1] == elem && matriz[2][0] == elem){
    return 1;
  }
  else{return 0;}
}

int main(void) {
  int x, y, i, j, jogadas;
  char elemento, jogo[3][3];

  //Lê a situação atual do jogo
  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      scanf(" %c", &jogo[i][j]);
    }
  }
  
  //Lê a quantidade de jogadas a serem testadas
  scanf("%d", &jogadas); 
  
  //Testa cada jogada individualmente
  while(jogadas>0){
    
    scanf("%d %d %c", &x, &y, &elemento); 
    //Lê a jogada da vez a ser testada
  
    x -= 1;
    y -= 1;

    //Testar se a jogada é válida
    if(jogo[x][y] != '.'){printf("Jogada inválida!\n");}
    else{
      //Coloca a jogada teste na matriz do jogo
      jogo[x][y] = elemento;
      //Testa se com a jogada o jogo é vencido
      if(vencer(elemento, x, y, jogo)){
        printf("Boa jogada, vai vencer!\n");
      }
      else{
        printf("Continua o jogo.\n");
      }
      //Retira a jogada teste da matriz do jogo
      jogo[x][y] = '.';
    }
    //Desconta o teste já feito da contagem
    jogadas--;
  }
  return 0;
}