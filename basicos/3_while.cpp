#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	printf("Programa para sacar estadisticas de tus notas \n");
	printf("Ingrese nota | 0 para cancelar \n");
	int grade = 0, Mgrade = 0, Hgrade = 0, pass = 0, failed = 0, prom = 0, i = 0;
	while (1) { // use an infinite loop
		scanf("%d", &grade);
		if (grade == 0) { // check if grade is 0
			break; // break out of the loop
		}
		prom = prom + grade;
		i = i + 1;
		if (grade > Hgrade) {
			Hgrade = grade;
		} 
		if (i == 1) { // set Mgrade to the first grade entered
			Mgrade = grade;
		} else if (grade < Mgrade) {
			Mgrade = grade;
		}
		if (grade >= 4) {
			pass = pass + 1;
		} else if (grade < 4) {
			failed = failed + 1;
		}
	}
	if (i > 0) { // check if any grades were entered
		printf("La nota mas baja es %d \n", Mgrade);
		printf("La nota mas alta es %d \n", Hgrade);
		printf("Aprobaste %d examenes\n", pass);
		printf("Desaprobaste %d examenes\n", failed);
		printf("Tu promedio general es %d \n", prom / i);
	} else {
		printf("No se ingresaron notas.\n"); // handle the case when no grades were entered
	}
	return 0;
}

