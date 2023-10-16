#include <iostream>
using namespace std;
/*Escribir un programa que pida ingresar coordenadas (x,y) que representan puntos en el plano. 
Informar cuántos puntos se han ingresado en el primer, segundo, tercer y cuarto cuadrante. 
Al comenzar el programa se pide que se ingrese la cantidad de puntos a procesar.*/
int main(int argc, char *argv[]) {
	int puntos=0, i=0, cx=0, cy=0, primer_c=0, segundo_c=0, tercer_c=0, cuarto_c=0;
	printf("Programa para informar cuantos puntos se han ingresado en el primer, segundo, tercer y cuarto cuadrante.\n");
	printf("Ingrese la cantidad de puntos a procesar\n");
	scanf(" %d", &puntos);
	for (i=1; i<=puntos; i++) {
		printf("Ingrese coordenada x \n");
		scanf(" %d", &cx);
		printf("Ingrese coordenada y \n");
		scanf(" %d", &cy);
		if(cx>=0 && cy>=0) {
			primer_c+= 1;
		}
		if(cx<0 && cy>=0) {
			segundo_c+= 1;
		}
		if(cx<0 && cy<0) {
			tercer_c+= 1;
		}
		if(cx>=0 && cy<0) {
			cuarto_c+= 1;
		}
	}
	printf("\n Se han ingresado\n");
	printf("\n%d puntos en el primer cuadrante\n", primer_c);
	printf("\n%d puntos en el segundo cuadrante\n", segundo_c);
	printf("\n%d puntos en el tercer cuadrante\n", tercer_c);
	printf("\n%d puntos en el cuarto cuadrante\n", cuarto_c);
	return 0;
}

