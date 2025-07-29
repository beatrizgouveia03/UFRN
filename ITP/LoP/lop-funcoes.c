#include <stdio.h>

int teste(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    if(x1<x3 && y1<y3 && x2>x4 && y2> y4){return 0;}
    else if(x1>x3 && y1>y3 && x2<x4 && y2<y4){return 1;}
    else{return 2;}
}

int main(){
    int x1, y1, x2, y2, x3, y3, x4, y4;
    
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
    printf("%d %d %d %d", x3, y3, x4, y4);
    
    while(x3 != 0 && y3 != 0 && x4 != 0 && y4 != 0){
        switch(teste(x1,y1,x2,y2,x3,y3,x4,y4)){
            case 0: printf("(<%.2d,%.2d>,<%.2d,%.2d>) contem (<%.2d,%.2d>,<%.2d,%.2d>).", x1,y1,x2,y2,x3,y3,x4,y4); break;
            case 1: printf("(<%.2d,%.2d>,<%.2d,%.2d>) contem (<%.2d,%.2d>,<%.2d,%.2d>).", x3,y3,x4,y4,x1,y1,x2,y2); break;
            case 2: printf("Nao posso afirmar!"); break;
        }
        scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
    }
    
    return 0;
}