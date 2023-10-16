#include <iostream>
using namespace std;
/*Escribir un programa que permita realizar descuentos en un comercio, en función del total de artículos que lleva el cliente. 
Para realizar dichos descuentos, se deben leer los importes de cada artículo hasta que un importe sea igual a cero; 
posteriormente se escribirá el importe total a pagar teniendo en cuenta que se pueden efectuar los siguientes descuentos:
Si el importe total de la compra está entre $50 y $120, el descuento es del 15%.
Si el importe total de la compra es mayor de $120 el descuento es del 20%.
La lectura de clientes finaliza tras responder al mensaje ¿Más clientes (S/N)?, mostrando al final la suma total de todos los importes cobrados por el negocio.
*/
int main(int argc, char *argv[]) {
	int precio=0, acum=0, result=0, result2=0, pozo=0,choice;
	char repeat;
	printf("Este es un programa que realiza descuentos y calcula el total recaudado \n ");
	do {
		precio=0, acum=0, result=0, result2=0, choice;
		while(1) {
			printf("Ingresa valor de articulo: | 0 para terminar\n ");
			scanf("%d", &precio);
			acum+= precio;
			if (precio == 0) { 
				break; 
			}
		}
		result= acum- (acum*15/100);
		result2= acum- (acum*20/100);
		if(acum > 49 && acum<121) {
			pozo+=result;
			printf("El total a pagar es %d \nTiene descuento del 15 porciento aplicado\n", result);
		}
		if(acum > 120) {
			pozo+=result2;
			printf("El total a pagar es %d \nTiene descuento del 20 porciento aplicado \n", result2);
		}
		
		printf("¿Mas clientes?(s/n) \n ");
		scanf(" %c", &repeat);
		
	} while (repeat == 's' || repeat == 'S');
	
	printf("El total recaudado hoy es %d", pozo);
	
	return 0;
	
}

