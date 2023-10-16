#include <iostream>
using namespace std;
/*Una empresa de telefonía lanza una promoción a sus clientes que han llamado mas de 1000 minutos de 
llamadas locales y 1000 minutos de llamadas a larga distancia haciéndoles un descuento en su factura del 10%. 
Téngase en cuenta que el precio del minutos de llamadas locales es de $0.05 y de las llamadas de larga a distancia es de $0.10. 
Realice un algoritmo en la cual solicite los datos necesarios al cliente e informar si es o no beneficiario de tal promoción y cuanto debería abonar en su próxima factura. */
int main(int argc, char *argv[]) {
	int larga=0, corta=0, total=0, total1=0, descuento=0, descuento1=0, totalfinal=0;
	printf("Ingrese la cantidad de minutos en llamadas locales \n");
		scanf("%d", &corta);
	printf("Ingrese la cantidad de minutos en llamadas de larga distancia\n");
		scanf("%d", &larga);
	total= corta*0.05;
	total1=larga*0.10;
	descuento= total*10/100;
	descuento1= total1*10/100;
	totalfinal= (total-descuento) + (total1-descuento1);
	if(corta >1000 && larga>1000) {
		printf("Usted aplica al descuento en el servicio de llamadas de un 10 por ciento \n");
		printf("Debera pagar en total con descuento aplicado %d",totalfinal);
	} else { ("Usted no aplica al descuento de llamadas");
	printf("Debera pagar en total  %d",total+total1);
	}
		
	return 0;
}

