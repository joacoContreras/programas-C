#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int num1=0, num2=0, suma=0;
	printf("Ingresar dos numeros para sumar: \n"); 
	scanf("%d %d", &num1, &num2);
	suma= num1 + num2;
	printf("El resultado de la suma es %d \n", suma);
	printf("El resultado de la multiplicacion es %d \n" , num1 * num2);
	printf("El resultado de la resta es %d \n", num1 - num2);
	
	return 0;
}

