#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*Desarrollar un programa que permita la carga de n valores por teclado y 
	nos muestre posteriormente la cantidad de veces que se repitió el número 10. */
	int n=-1, x=0;
	printf("Ingrese valores, para parar, ingrese 0\n");
	while (n != 0) {
		
		scanf("%d", &n);
		if (n == 10) {
			x=x+1;
		}
	}
	printf("Ingreso el numero 10 %d veces", x);
	return 0;
}

