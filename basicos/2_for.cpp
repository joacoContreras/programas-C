#include <iostream>
using namespace std;
/*Desarrollar un programa que permita la carga de 5 valores por teclado y 
nos muestre posteriormente la suma de los valores ingresados y su promedio.*/
int main(int argc, char *argv[]) {
	int num=0, i=0, sum=0, prom=0;
	printf("Programa para calcular promedio y suma de 5 numeros \n");
	
	for (i=1; i<=5; i++) {
		printf("Ingrese un numero \n");
		scanf(" %d", &num);
		sum+= num;
		prom= sum/i;
	}
	printf("\nLa suma total de los numeros ingresados es %d \n", sum);
	printf("\nEl prmedio de los numeros ingresados es %d\n", prom);
	return 0;
}

