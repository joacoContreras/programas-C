#include <iostream>
using namespace std;
/*Realizar un algoritmo para determinar la cantidad de números positivos y 
negativos que han sido ingresados.
*/

int main(int argc, char *argv[]) {
	int num=0, negatives=0, positives=0;
	
	printf("Ingrese numero | 0 para finalizar \n");
	do {
		scanf("%d", &num);
		if (num<0) {
			negatives+=1;
		}
		if (num>0) {
			positives+=1;
		}
	}while (num != 0);
	printf("Usted ingreso %d numeros positivos\n", positives);
	printf("Usted ingreso %d numeros negativos\n", negatives);
	return 0;
}

