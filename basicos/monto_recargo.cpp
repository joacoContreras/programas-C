#include <iostream>
using namespace std;
/* 11. Ingrese el monto de una cuota y el día de pago. 
Si el día de pago es menor o igual a 10 no se cobra recargo. De lo contrario si la cuota 
es mayor a $5000 se cobra el 10% de recargo, sino se cobra el 5%. 
Debe mostrar en todos los casos el recargo y el valor final de la cuota.  */
int main(int argc, char *argv[]) {
	int renta=0;
	printf("Ingrese su renta anual \n");
	scanf("%d", &renta);

	if(renta <= 20000) {
		printf("Le corresponde un tipo impostivo del 5 porciento \n");
	} else if (renta> 20000 && renta<30000) {
		printf("Le corresponde un tipo impostivo del 10 porciento \n");
	}else if (renta<= 30000 && renta<40000) {
		printf("Le corresponde un tipo impostivo del 15 porciento \n");
	} else if (renta>40000) {
		printf("Le corresponde un tipo impostivo del 20 porciento \n");
	}
	return 0;
}

