#include <iostream>
#include <stdio.h>
#include "header_factorial.h"
#include "primo_factorial.c"

//Ingresar un numero y devolver factorial
using namespace std;

int main() {
	int n1 = 0;
	
	printf("Programa que devuelve factorial de un numero\n");
	printf("Ingrese un numero: ");
	scanf("%d", &n1);
	
	int res = factorial(n1);
	printf("El resultado es %d\n", res);
	

	return 0;
}

	
