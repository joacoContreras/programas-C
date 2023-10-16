#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float cant_gb =0, cant_mb = 0;
	printf("Ingrese los mb a convertir: \n");
	scanf("%f", &cant_mb);
	cant_gb = cant_mb / 1024;
	printf( "%0.f mb. son %0.f gb.", cant_mb, cant_gb);
	return 0;
}
