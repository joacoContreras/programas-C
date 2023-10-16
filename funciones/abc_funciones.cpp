#include <iostream>
using namespace std;

void mayus();
void sec_minus();
void inicio();


int main(int argc, char *argv[]) {
	
	inicio();
	
	return 0;
}

void inicio() {
	
	int opcion=3;
	
	printf("¿Desea imprimir el abecedario en mayuscula (1), o minuscula (2)?. (0 para cerrar)\n");
	scanf("%d", &opcion);
	
	if(opcion==1) {
		mayus();
		
	} else if (opcion==2) {
		
		sec_minus();
		
	} else if (opcion==0) {
		printf("Finalizado");
		
	}	else {
		printf("Error de entrada");
		inicio();
}
}
void mayus() {
	char i;
	
	for (i=65; i<=90; i++) {
		
		printf("%c \n", i);
		
	} inicio();
}

void sec_minus() {
	char i;
	
	for (i=97; i<=122; i++) {
		
		printf("%c \n", i);
		
	} inicio();
}
