#include <iostream>
#include <stdio.h>
#include "charComp.h"
#include "charCom_primo.c"
/*Escribir una funcion que reciba dos caracteres e indique si son 
iguales o no(0) independientemente si estan en mayus o minus*/

int main() {
	char c1, c2;
	printf("Ingrese dos caracteres para saber si son iguales \n");
	
	printf("\nIngrese el primer caracter: ");
	scanf(" %c",&c1);
	
	printf("\nIngrese el segundo caracter: ");
	scanf(" %c",&c2);
	

	int res = char_comp(c1, c2);
	if(res == True) {
		printf("\nSon iguales\n");
	} else {
		printf("\nNo son iguales\n");
	}
	
	return 0;
}
	
	

