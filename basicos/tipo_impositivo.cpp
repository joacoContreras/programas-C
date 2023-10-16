#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int alum=0, precio=0, colectivo=4000, total=0, sup=0;
	printf("Ingrese la cantidad de alumnos \n");
	scanf("%d", &alum);

	if(alum < 30) {
		colectivo=4000/alum;
		precio= 100*alum;
		total= colectivo+ 100;
		sup= 4000+ precio;
		printf("Cada alumno debe pagar %d \n", total);
		printf("El director debe entregar %d \n", sup);
	} else if (alum> 29 && alum <50) {
		colectivo=4000/alum;
		precio= 95*alum;
		total= colectivo+ 95;
		sup= 4000+ precio;
		printf("Cada alumno debe pagar %d \n", total);
		printf("El director debe entregar %d \n", sup);
	}else if (alum <100 && alum>49) {
		colectivo=4000/alum;
		precio= 70*alum;
		total= colectivo+ 70;
		sup= 4000+ precio;
		printf("Cada alumno debe pagar %d \n", total);
		printf("El director debe entregar %d \n", sup);
	} else if (	alum>99) {
		colectivo=4000/alum;
		precio= 65*alum;
		total= colectivo+ 65;
		sup= 4000+ precio;
		printf("Cada alumno debe pagar %d \n", total);
		printf("El director debe entregar %d \n", sup);
	}
	return 0;
}

