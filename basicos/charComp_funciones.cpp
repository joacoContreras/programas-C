#include <iostream>
#include <stdio.h>
#include "charComp.h"

/*Escribir una funcion que reciba dos caracteres e indique si son 
iguales o no(0) independientemente si estan en mayus o minus*/

int main() {
	char c1, c2;
	printf("Ingrese dos caracteres para saber si son iguales \n");
	
	printf("Ingrese el primer caracter: ");
	scanf(" %c",&c1);
	
	printf("\nIngrese el segundo caracter: ");
	scanf(" %c",&c2);
	

	int res = char_comp(c1, c2);
	if(res == True) {
		printf("Son iguales\n");
	} else {
		printf("No son iguales\n");
	}
	
	return 0;
}
	
	

