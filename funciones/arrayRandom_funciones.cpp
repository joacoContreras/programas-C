#include <iostream>
#include <stdlib.h>	
#include <time.h>

using namespace std;

int arreglo[10]; // variable global

int fill_array(int sumatoria);

void menu();



int main(int argc, char *argv[]) {
	
	menu();
	
	
	
	
	
	return 0;
}







//funcion para rellenar array
int fill_array (int z) {
	
	
	srand(time(NULL));
	
	
	for(int i =0; i < 10; i++) {
		
		
		int numero_aleatorio = (rand() % (90 - 65 + 1)) + 65;
		arreglo[i] = numero_aleatorio;
		
		z+= arreglo[i];
		
		printf("%d\n", arreglo[i]);
		
	} return z;
}






void menu() {
	
	int total=0, z=0;
	float promedio=0;
	char option=0;
	
	total = fill_array(z);
	
	do {
		printf("\nSeleccione la operación a realizar:\n \n a--> Sumar números generados\n b--> Calcular promedio\n c--> Transformar numeros en letras\n x--> Finalizar\n");
		printf("\nOpción: ");	scanf(" %c", &option);
		
		if (option == 'a') {
			
			printf("\nEl total de la suma es %d\n", total);
			
		} else if (option == 'b') {
			
			promedio= total;
			printf("\nEl total del promedio es %0.2f\n", promedio/10);
			
		} else if (option == 'c') {
			
			for(int i=0; i<10; i++){
				printf("%c\n", char(arreglo[i]));
			}
			
		} else {
			
			printf("\nValor ingresado incorrecto");
			printf("\nSeleccione la operación a realizar:\n \n a--> Sumar números generados\n b--> Calcular promedio\n c--> Transformar numeros en letras\n x--> Finalizar\n");
			printf("\nOpción: ");	scanf(" %c", &option);
		}	
		
	}while (option != 'x');
	
}

