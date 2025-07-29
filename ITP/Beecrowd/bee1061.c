#include<stdio.h>

int main(){
	int dia_inicio;
	int hora_inicio;
	int minuto_inicio;
	int segundo_inicio;
	int dia_fim;
	int hora_fim;
	int minuto_fim;
	int segundo_fim;
	char data[20];
	int dias;
	int horas;
	int minutos;
	int segundos;

	scanf("%s %d", data, &dia_inicio);
	scanf("%d %s %d %s %d", &hora_inicio, data, &minuto_inicio, data, &segundo_inicio);
	scanf("%s %d", data, &dia_fim);
	scanf("%d %s %d %s %d", &hora_fim, data, &minuto_fim, data, &segundo_fim);

	dias = dia_fim - dia_inicio;

	if(hora_fim<hora_inicio){
		horas = 24 - hora_inicio + hora_fim;
		if(dias>0){dias -= 1;}
	}
	else{
		horas = hora_fim - hora_inicio;
	}

	if(minuto_fim<minuto_inicio){
		minutos = 60 - minuto_inicio + minuto_fim;
		if(horas > 0){horas -= 1;}
	}
	else{
		minutos = minuto_fim - minuto_inicio;
	}


	if(segundo_fim<segundo_inicio){
		segundos = 60 - segundo_inicio + segundo_fim;
		if(minutos>0){minutos -= 1;}
	}
	else{
		segundos = segundo_fim - segundo_inicio;
	}


	printf("%d dias(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", dias, horas, minutos, segundos);

}