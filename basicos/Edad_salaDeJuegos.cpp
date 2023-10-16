#include <iostream>
using namespace std;
/* 11. Ingrese el monto de una cuota y el día de pago. 
Si el día de pago es menor o igual a 10 no se cobra recargo. De lo contrario si la cuota 
es mayor a $5000 se cobra el 10% de recargo, sino se cobra el 5%. 
Debe mostrar en todos los casos el recargo y el valor final de la cuota.  */
int main(int argc, char *argv[]) {
	int monto=0, dia=0, total=0;
	printf("Ingrese monto de la cuota \n");
	scanf("%d", &monto);
	printf("Ingrese el dia de pago \n");
	scanf("%d", &dia);
	if(dia=< 10) {
		printf("No se cobra recargo \n");
	} else if (monto> 5000) {
		total= monto - ((monto*10)/100)
		printf("Debes pagar %d , incluye 10 porciento de recargo \n", total);
	} else if (monto<5000) {
		total= monto - ((monto*5)/100)
		printf("Debes pagar %d , incluye 5 porciento de recargo \n", total);
	} 
	return 0;
}

