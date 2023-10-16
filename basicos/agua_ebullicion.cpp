#include <iostream>
using namespace std;
/*Escriba un programa que pida tres números y que escriba si son los tres iguales, 
si hay dos iguales o si son los tres distintos.  */
int main(int argc, char *argv[]) {
	int n1=0, n2=0, n3=0;
	printf("Ingrese tres numeros \n");
	scanf("%d%d%d", &n1,&n2,&n3);
	if(n1== n2 && n1 == n3) {
		printf("Los tres numeros son iguales \n");
	} else if (n1 != n2 && n1!= n3 && n2 != n3) {
		printf("Los tres numeros son distintos \n");
	} else if (n1== n2 && n1 != n3) {
		printf("El primer y el segundo numero son iguales");
	} else if (n2== n3 && n1 != n3) {
		printf("El tercer y el segundo numero son iguales");
	}
	return 0;
}

