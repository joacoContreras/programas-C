#include <iostream>
using namespace std;
/*Elaborar un algoritmo para obtener el resultado del escrutinio en las elecciones de un pueblo. 
	Se han presentado 3 candidatos, considerando la posibilidad del voto en blanco e impugnado. 
	El programa debe mostrar: 
	El orden de los ganadores 1º, 2º y 3º lugar. (por mayoría simple)
	Las cantidades de votos que sacaron cada uno, como también la cantidad de votos en blanco e impugnados.*/
	
#include <stdio.h>
	
	int main() {
		int candidato1 = 0, candidato2 = 0, candidato3 = 0, votos_blancos = 0, votos_impugnados = 0, votos_totales = 0;
		int voto = 0;
		
		// Leer los votos hasta que se ingrese -1 para finalizar la votación
		while (voto != -1) {
			printf("Ingrese el número del candidato al que desea votar (1, 2 o 3). Ingrese -1 para finalizar la votación.\n");
			scanf("%d", &voto);
			
			switch (voto) {
			case 1:
				candidato1++;
				break;
			case 2:
				candidato2++;
				break;
			case 3:
				candidato3++;
				break;
			case -1:
				break;
			default:
				votos_impugnados++;
				break;
			}
			
			votos_totales++;
		}
		
		// Calcular el porcentaje de votos para cada candidato y los votos en blanco
		float porcentaje1 = (float) candidato1 / votos_totales * 100;
		float porcentaje2 = (float) candidato2 / votos_totales * 100;
		float porcentaje3 = (float) candidato3 / votos_totales * 100;
		votos_blancos = votos_totales - candidato1 - candidato2 - candidato3 - votos_impugnados;
		
		// Imprimir los resultados del escrutinio
		printf("Resultados del escrutinio:\n");
		printf("Candidato 1: %d votos (%.2f%%)\n", candidato1, porcentaje1);
		printf("Candidato 2: %d votos (%.2f%%)\n", candidato2, porcentaje2);
		printf("Candidato 3: %d votos (%.2f%%)\n", candidato3, porcentaje3);
		printf("Votos en blanco: %d\n", votos_blancos);
		printf("Votos impugnados: %d\n", votos_impugnados);
		
		// Calcular y mostrar el orden de los ganadores
		printf("Orden de los ganadores:\n");
		if (candidato1 > candidato2 && candidato1 > candidato3) {
			printf("1º lugar: Candidato 1\n");
			if (candidato2 > candidato3) {
				printf("2º lugar: Candidato 2\n");
				printf("3º lugar: Candidato 3\n");
			} else {
				printf("2º lugar: Candidato 3\n");
				printf("3º lugar: Candidato 2\n");
			}
		} else if (candidato2 > candidato1 && candidato2 > candidato3) {
			printf("1º lugar: Candidato 2\n");
			if (candidato1 > candidato3) {
				printf("2º lugar: Candidato 1\n");
				printf("3º lugar: Candidato 3\n");
			} else {
				printf("2º lugar: Candidato 3\n");
				printf("3º lugar: Candidato 1\n");
			}
		} 
	return 0;
}

