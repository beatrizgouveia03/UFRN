#include <stdio.h>

int MDC(int num1, int num2){
	int mdc = 1;

	for(int x = 1; x<=num1; x++){
		if(num1%x == 0 && num2%x == 0){
			mdc *= x;
			num1 /= x;
			num2 /= x;
		}
	}
	
	if (num1 == 0){mdc = num2;}
	return mdc;
}

int main(){
	int num1, num2;

	scanf("%d %d", &num1, &num2);

	printf("MDC(%d , %d) = %d", num1, num2, MDC(num1, num2));
}
