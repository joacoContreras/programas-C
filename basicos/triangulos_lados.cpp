#include <iostream>
using namespace std;
/* Escribir un programa para una empresa que tiene salas de juegos para todas 
las edades y quiere calcular de forma automática el precio que debe cobrar a sus c
lientes por entrar. El programa debe preguntar al usuario la edad del cliente 
y mostrar el precio de la entrada. Si el cliente es menor de 4 años puede entrar gratis, 
si tiene entre 4 y 18 años debe pagar $100 y si es mayor de 18 años, $200.  */
int main(int argc, char *argv[]) {
	int edad=0;
	printf("Ingrese su edad \n");
	scanf("%d", &edad);
	if(edad<4) {
		printf("Puedes entrar gratis \n");
	} else if (edad>= 4 && edad<18) {
		printf("Debes pagar una entrada de 100$ \n");
	} else if (edad>=18) {
		printf("Debes pagar una entrada de 200$ \n");
	} 
	return 0;
}

