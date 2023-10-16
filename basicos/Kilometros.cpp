#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float cant_m =0, cant_km = 0;
		printf("Ingrese los metros a convertir: \n");
		scanf("%f", &cant_m);
		cant_km = cant_m / 1000;
		printf( "%0.f m. son %0.f km.", cant_m, cant_km) ;
	return 0;
}

