#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
/*Un circo desea agilizar los tiempos de espera de los clientes para la compra de entradas, 
para ello, se le solicita que elabore un programa de venta de ticket de entradas. 
El programa debe solicitar al usuario que ingrese todas las edades del grupo familiar, 
hasta que ingrese cero (0), luego calcular y mostrar el monto total a pagar, de acuerdo a los siguientes precios: 
Menores de 5 años gratis.
Entre 5 y 15 años inclusive $20.
Mayores de 15 años $40.

*/

int main(int argc, char *argv[]) {
	int age=0, amount=0;
	
	printf("Programa para agilizar ventas de entrada \n");
	printf("Menores de 5 años gratis - Entre 5 y 15 años inclusive $20 - Mayores de 15 años $40 \n");
	printf("Ingrese edades del grupo familiar | 0 para parar \n");
	
	do {
		scanf("%d", &age);
		if(age<5 && age>0) {
			amount+=0;
		}
		if(age<=15 && age>=5) {
			amount+=20;
		}
		if(age>15) {
			amount+=40;
		}
		
	}while( age != 0);
	printf("Total a pagar es %d$ \n",amount);

	return 0;
}

