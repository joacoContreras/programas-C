#include <stdio.h>

int main() {
	int i, temperatura[24], temp_min=100, temp_max=-100;
	float temp_promedio=0;
	
	printf("Programa que evalua la temperatura\n");
	
	for (i=0; i<24; i++) {
		printf("Ingrese la temperatura de la hora %d: ", i+1);
		scanf("%d", &temperatura[i]);
		
		temp_promedio += temperatura[i];
		
		if (temperatura[i] < temp_min) {
			temp_min = temperatura[i];
		}
		if (temperatura[i] > temp_max) {
			temp_max = temperatura[i];
		}
	}
	
	temp_promedio /= 24;
	printf("Promedio de la temperatura: %.2f \n", temp_promedio);
	printf("Temperatura mínima: %d \n", temp_min);
	printf("Temperatura máxima: %d \n", temp_max);
	
	return 0;
}

