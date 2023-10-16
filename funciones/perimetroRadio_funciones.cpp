#include <stdio.h>
#include <math.h>
using namespace std;

//Declarar la funcion

void calcu();
void circulo();
void cuadrado();
void rectangulo();


int main(int argc, char *argv[]) {
	
	printf("Calculadora de área y perímetro de cuadrados\n");
	
	calcu();
	
	return 0;
	
}

//desarrollar la funcion

void calcu() {
	int n1=0, n2=0;
	char option = '0';
	
	printf("\nIngrese el tipo de figura: \n"); 
	printf("\na--> Cuadrado\nb--> Círculo\nc--> Rectángulo\nx--> Salir\n"); scanf(" %c", &option);
	if(option == 'a') {
		cuadrado();
	} else if (option =='b') {
		circulo();
		
	} else if (option == 'c') {
		rectangulo();
		
	} else if(option == 'x') {
		printf("Finalizado");
		
	} else {
		printf("Caractèr ingresado no válido \n");
		calcu();
	}
	
}

void cuadrado() {
	int lado=0,  perimetro=0;
	float area=0;
	printf("\nIngrese valor de un lado: "); scanf("%d", &lado);
	
	area= pow (lado, 2);
	perimetro=  4*lado;
	
	
	printf("\nEl area es: %0.2f\n", area);
	printf("\nEl perimetro es: %d\n", perimetro);
	calcu();
	}


void circulo() {
	int radio=0;
	float area=0, perimetro=0;
	double pi=3.14159;
	printf("\nIngrese el radio: "); scanf("%d", &radio);
	
	area= pi*(pow (radio, 2));
	perimetro=  (pow(pi, 2))*radio;
	
	
	printf("\nEl area es: %0.2f\n", area);
	printf("\nEl perimetro es: %0.2f\n", perimetro);
	calcu();
}

void rectangulo() {
	int ancho=0, largo=0, area=0, perimetro=0;
	
	printf("\nIngrese ancho: "); scanf("%d", &ancho);
	printf("\nIngrese largo: "); scanf("%d", &largo);
	
	area= ancho*largo;
	perimetro=  2*ancho + 2*largo;
	
	
	printf("\nEl area es: %d\n", area);
	printf("\nEl perimetro es: %d\n", perimetro);
	calcu();
}

