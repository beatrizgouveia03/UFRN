#include <stdio.h>

int main(){
	int inicial_hour;
	int inicial_minute;
	int final_hour;
	int final_minute;
	int total_hours;
	int total_minutes;

	scanf("%d %d %d %d", &inicial_hour, &inicial_minute, &final_hour, &final_minute);

	if (inicial_hour<final_hour){
		total_hours = final_hour - inicial_hour;
		if (inicial_minute<=final_minute){
			total_minutes = final_minute - inicial_minute;
		}
		else if (inicial_minute > final_minute){
			total_minutes = final_minute + 60 - inicial_minute;
			total_hours -= 1;
		}
	}
	else if(inicial_hour == final_hour){
		total_hours = 24;
		if (inicial_minute<=final_minute){
			total_minutes = final_minute - inicial_minute;
		}
		else if (inicial_minute > final_minute){
			total_minutes = final_minute + 60 - inicial_minute;
			total_hours += 1;
		}
	}
	else{
		total_hours = final_hour + (24 - inicial_hour);
		if (inicial_minute<=final_minute){
			total_minutes = final_minute - inicial_minute;
		}
		else if (inicial_minute > final_minute){
			total_minutes = final_minute + 60 - inicial_minute;
			total_hours -= 1;
		}
	}
	
	return 0;
	
}
/* Erro de formamtação na saída a ser descoberto*/