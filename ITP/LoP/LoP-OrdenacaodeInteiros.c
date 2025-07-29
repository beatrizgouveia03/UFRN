#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char lista[100];
    char* pedaco;
    int* valores;
    int quant = 1;


    valores = malloc(sizeof(int)*quant);
    scanf("%d", &valores[quant-1]);

    
    while(scanf("%d", &valores[quant-1]) != EOF){
        quant++;
        valores = realloc(valores, sizeof(int)*quant);
    }

    for(int i=0;i<quant;i++){
        printf("%d ", valores[i]);
    }

    return 0;
}