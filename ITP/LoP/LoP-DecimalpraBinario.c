#include <stdio.h>
#include <stdlib.h>

int main(){
    int* binario;
    int num, qnt=0;

    binario = malloc(sizeof(int)*qnt);

    scanf("%d", &num);

    if(num == 0){printf("0");}

    while(num != 0){
        binario = realloc(binario, sizeof(int)*(qnt+1));
        binario[qnt] = num%2;
        num /= 2;
        qnt++;
    }

    for(int i = qnt-1; i>=0;i--){
        printf("%d", binario[i]);
    }
}