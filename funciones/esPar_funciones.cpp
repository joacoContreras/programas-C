#include <iostream>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

//Declarar la funcion

void calcu();
void suma();
void resta();
void mult();
void divis();

int main(int argc, char *argv[]) {
	
	printf("Calculadora\n");
	
	calcu();
	
	

	return 0;
}

//desarrollar la funcion

void calcu() {
	int n1=0, n2=0;
	char option = '0';
	
	printf("\nIngrese el tipo de operación a realizar: \n"); 
	printf("a--> Suma\nb--> Resta\nc--> Multiplicación\nd--> División\nx--> Salir\n"); scanf(" %c", &option);
	if(option == 'a') {
		suma();
	} else if (option =='b') {
		resta();
	} else if (option == 'c') {
		mult();
	} else if (option == 'd') {
		divis();
	} else if(option == 'x') {
		printf("Finalizado");
	} else {
		printf("Caractèr ingresado no válido \n");
		calcu();
	}
	
}

void suma() {
	int n1=0, n2=0, result=0;
	
	printf("\nIngrese primer numero: "); scanf("%d", &n1);
	printf("\nIngrese segundo numero: "); scanf("%d", &n2);
	
	result= n1+n2;
	
	printf("\nEl resultado es: %d\n", result);
	
	calcu();
}

void resta() {
	int n1=0, n2=0, result=0;
	
	printf("\nIngrese primer numero: "); scanf("%d", &n1);
	printf("\nIngrese segundo numero: "); scanf("%d", &n2);
	
	result= n1-n2;
	
	printf("\nEl resultado es: %d\n", result);
	
	calcu();
}

void mult() {
	int n1=0, n2=0, result=0;
	
	printf("\nIngrese primer numero: "); scanf("%d", &n1);
	printf("\nIngrese segundo numero: "); scanf("%d", &n2);
	
	result= n1*n2;
	
	printf("\nEl resultado es: %d\n", result);
	
	calcu();
}

void divis() {
float n1=0, n2=0, result=0;
	
	printf("\nIngrese primer numero: "); scanf("%d", &n1);
	printf("\nIngrese segundo numero: "); scanf("%d", &n2);
	
	result= n1/n2;
	
	printf("\nEl resultado es: %0.2f\n", result);
	
	calcu();
}
