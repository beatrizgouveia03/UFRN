#include <stdio.h>

int main()
{
	double salary;
	double tax1;
	double tax2;
	double tax3;

	scanf("%lf", &salary);

	salary -= 2000.00;

	if (salary <= 0.0){
		printf("Isento\n");
	}
	else{
		if (salary>=1000.00){
			tax1 = 1000.00;
			salary -= 1000.00;
			if(salary>=1500.00){
				tax2 = 1500.00;
				salary -= 1500.00;
				tax3 = salary;
			}
			else{
				tax2 = salary;
				tax3 = 0.0;
			}
		}
		else{
			tax1 = salary;
			tax2 = 0.0;
			tax3 = 0.0;
		}

		tax1 *= 0.08;
		tax2 *= 0.18;
		tax3 *= 0.28;

		printf("R$ %.2lf\n", tax1+tax2+tax3);
	}

	return 0;
}