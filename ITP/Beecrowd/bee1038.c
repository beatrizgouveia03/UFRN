#include <stdio.h>

int main()
{
	int code_product;
	int quantity;

	scanf("%d %d", &code_product, &quantity);

	switch(code_product){
		case 1: printf("Total: R$ %.2lf\n", quantity*4.00); break;
		case 2: printf("Total: R$ %.2lf\n", quantity*4.50); break;
		case 3: printf("Total: R$ %.2lf\n", quantity*5.00); break;
		case 4: printf("Total: R$ %.2lf\n", quantity*2.00); break;
		case 5: printf("Total: R$ %.2lf\n", quantity*1.50); break;
		default: break;
	}
	return 0;
}