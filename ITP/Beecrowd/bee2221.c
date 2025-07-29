#include <stdio.h>

double dabriel, guarte;
int instances, bonus, atk, def, level, aux;

double calc_value(int attack, int defense, int bonus){
	return (attack+defense)/2.0 + bonus;
}

int main(void){
	scanf("%d", &instances);
	for(int y=0; y<instances; y++){
		scanf("%d", &bonus);
		scanf("%d %d %d", &atk, &def, &level);
		if(level%2 != 0 || level == 1){aux = 0;}
		else{aux = bonus;}
		dabriel = calc_value(atk, def, aux);
		scanf("%d %d %d", &atk, &def, &level);
		if(level%2 != 0 || level == 1){aux = 0;}
		else{aux = bonus;}
		guarte = calc_value(atk, def, aux);

		if(guarte > dabriel){printf("Guarte\n");}
		else if(dabriel > guarte){printf("Dabriel\n");}
		else{printf("Empate\n");}
	}
}