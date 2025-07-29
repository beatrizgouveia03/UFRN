#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int nlin, ncol;
  int **mat;
}  Matrix;

Matrix* createMatrix(int nlin, int ncol){
  Matrix* aux;
  int** matrix;

  aux = malloc(sizeof(Matrix));
  
  aux->nlin = nlin;
  aux->ncol = ncol;

  matrix = (int**)calloc(nlin,sizeof(int*));

  for(int i=0;i<nlin;i++){
    matrix[i] = (int*)calloc(ncol,sizeof(int));
  }
  
  aux->mat = matrix;
  
  return aux;
}

void readMatrix(Matrix *m){
  int lin, col;
  lin = m->nlin;
  col = m->ncol;

  for(int i=0;i<lin;i++){
    for(int j=0;j<col;j++){
      scanf("%i", &m->mat[i][j]);
    }
  }
}

void printMatrix(Matrix *m){
  int lin, col;
  lin = m->nlin;
  col = m->ncol;

  for(int i=0;i<lin;i++){
    for(int j=0;j<col;j++){
      printf("%d ", m->mat[i][j]);
    }
    printf("\n");
  }
}

/*void destroyMatrix(Matrix **m){
  int lin, col;
  
  lin = *m->*nlin;
  col = *m->*ncol;

  for(int i=0;i<lin;i++){ 
    free(*m->*mat[lin]);
  }

  free(m);
}*/

int main(void) {
  int lin = 0, col = 0;
  Matrix* mat;

  mat = malloc(sizeof(Matrix));

  scanf("%i %i", &lin, &col);
  mat = createMatrix(lin, col);
  readMatrix(mat);
  printMatrix(mat);
  //destroyMatrix(&mat);
  if (mat == NULL){
    printf("OK\n");
  }
  return 0;
}