#include <iostream>
#include <stdio.h>
using namespace std;
/*Se solicita un algoritmo que calcule cuánto ha podido ahorrar en un año una persona. 
Para ello se solicita cuanto ha sido su sueldo en cada uno de los meses y 
cuánto ha gastado en cada uno de los meses.  */

int main(int argc, char *argv[]) {
	int sueldo[12], gasto[12], total_sueldo=0, total_gasto=0, i;
	
	printf("Programa para calcular cuanto ha podido ahorrar una persona\n");
	for (i=0; i<12; i++) {
		printf("Ingrese sueldo %d\n", i+1);
		scanf("%d", &sueldo[i]);
		total_sueldo += sueldo[i];
		
		printf("Ingrese gasto correspondiente a mes %d\n", i+1);
		scanf("%d", &gasto[i]);
		total_gasto += gasto[i];
	}
	
	printf("\n Ingreso total anual %d", total_sueldo);
	printf("\n Gasto total anual %d", total_gasto);
	printf("\n Has podido ahorrar %d", total_sueldo-total_gasto);
	
	return 0;
}


