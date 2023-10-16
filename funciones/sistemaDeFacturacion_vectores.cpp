#include <iostream>
using namespace std;

int c;


void cargar_factura();
void metodo_pago();

int codigo [5];
float precio_unitario[5];
int cantidad[5];
float subtotal[5];
float total;

int main(int argc, char *argv[]) {
	
	cargar_factura();
	metodo_pago();

	
	
	return 0;
}

void cargar_factura(){
	int i=0; int c=0;
	
	printf("Ingrese la catidad de artículos de la factura (max 5)\n");
	scanf("%d", &c);
	
	if (c>5) {
		
		printf("Cantidad de artículos excedida\n");
			printf("Ingrese la catidad de artículos de la factura (max 5)\n");
		scanf("%d", &c);
		
	} else if (c>0 || c <6) {
		
	
	for(i=1 ; i<= c; i++) {
		
		printf("\nIngrese precio unitario: ");
		scanf("%f", &precio_unitario[i]);
		
		printf("\nIngrese cantidad: ");
		scanf("%d", &cantidad[i]);
		
		subtotal[i] = cantidad[i] * precio_unitario[i];
		total += cantidad[i] * precio_unitario[i];
	}
	
	printf("\nFactura: \n");
	for (int i=1; i<= c; i++){
		
		printf("\nCódigo: %d | Precio unitario: %0.2f  | Cantidad: %d  | Subtotal: %0.2f .\n",i, precio_unitario[i], cantidad[i], subtotal[i]);
	}
	
	
	}
	
	else if (c = 0){
		
		printf("\nIngrese la catidad de artículos de la factura (max 5)\n");
		scanf("%d", &c);
	}
}


	
	void metodo_pago(){
		
		char opcion=0;
		float vuelto=0, pago=0, interes =0;
		
		printf("\nEl total es: %0.2f\n", total);
		printf("\nIngrese método de pago:\n a--> Efectivo\n b--> débito\n c--> crédito(5% recargo)\n");
		scanf(" %c", &opcion);
		
		switch(opcion) {
			
		case 'a':
			
			printf("Ingrese el monto de pago\n");
			scanf("%f", &pago);
			vuelto= pago - total;
			
			if (vuelto < 0 ) {
				
				printf ("Pago insuficiente\n");
			} else {
				printf("\nEl vuelto es %0.2f\n", vuelto);
			}
			
		
			break;
			
		case 'c':
		
			
			interes= (total *5) / 100 ;
			printf("El nuevo total es %0.2f\n", total+interes);
			
			break;
			
			
		case 'b':
			
		
			break;
		
		default:
			printf("\nCaracter ingresado no válido");
			
			void metodo_pago();

		
			
			break;
		}
	}
		
