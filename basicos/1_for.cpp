#include <iostream>
using namespace std;
/*Realizar un programa que muestre la tabla de multiplicar del 1 al 10 de un número. 
Ejemplo: Si ingreso 2 deberá aparecer en pantalla los valores 2, 4, 6, hasta el 20.*/
int main(int argc, char *argv[]) {
	int num=0, i=0, result=0;
	printf("Programa para calcular tabla de multiplicar \n");
	printf("Ingrese un numero \n");
	scanf("%d", &num);
	for (i=1; i<=10; i++) {
		result= i*num;
		printf(" %d x %d = %d \n", num, i, result);
	}
	return 0;
}

