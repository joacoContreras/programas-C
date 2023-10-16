#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	char let;
	int grade=0;
	printf("Programa para ubicar alumno en grupo \n");
	
	printf("Ingrese la inicial de su apellido en Mayúscula: "); 
	scanf("%c", &let);
	
	printf("Ingrese la nota obtenida: ");
	scanf("%d", &grade);
	
	if(let >= 41 && let <= 77 ) {
		if (grade > 6) {
			printf ("\nLe corresponde el grupo A\n");
		} else if (grade < 7) {
			printf ("\nLe corresponde el grupo C\n");
		}
	}
	if(let > 77 && let < 91 ) {
		if (grade > 6) {
			printf ("\nLe corresponde el grupo B\n");
		} else if (grade < 7) {
			printf ("\nLe corresponde el grupo D\n");
		}
	}
	return 0;
}

