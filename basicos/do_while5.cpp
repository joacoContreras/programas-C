#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	/*Crear un menú de opciones con las siguientes operaciones: 
	Elevar a la potencia de 2 un número.
	Raíz cuadrada de un número.
	Raíz cúbica de un número. 
	Calcular el seno, coseno y tangente de un ángulo.
	*/
	
	int result=0,num=0, choice, angulo=0;
	float rad;
	double pi = 3.14159265358979323846;
	char repeat;
	printf("   Este es un programa que realiza operaciones \n ");

	do {
		printf("¿Que operacion quieres realizar?\n");
		printf("1. Elevar a la potencia de 2 un numero\n");
		printf("2. Raíz cuadrada de un número\n");
		printf("3. Raíz cúbica de un número\n");
		printf("4. Calcular el seno, coseno y tangente de un ángulo\n");
		scanf("%d", &choice);
		
		switch (choice) {
		case 1:
			printf("\n Ingresar numero \n");
			scanf("%d",&num);
			result = pow(num,2);
			printf("El resultado es: %d\n", result);
			break;
			
		case 2:
			printf("Ingresar numero");
			scanf("%d",&num);
			result = sqrt(num);;
			printf("El resultado es: %d\n", result);
			break;
			
		case 3:
			printf("Ingresar numero");
			scanf("%d",&num);
			result = cbrt(num);
			printf("El resultado es: %d\n", result);
			break;
			
		case 4:
			printf("Ingresar valor \n");
			scanf("%d",&angulo);
			rad=(((float)angulo*pi)/180); //convertir a radianes
			printf( "El seno de %d es %.2f \n", angulo, sin(rad));
			printf( "El coseno de %d es %.2f \n", angulo, cos(rad));
			printf( "La tangente de %d es %.2f \n", angulo, tan(rad));
			break;
		default:
			printf("El numero ingresado no es valido \n");
			break;
		}
		
		printf("¿Queres hacer otra operacion?(s/n) \n ");
		scanf(" %c", &repeat);
		
	} while (repeat == 's' || repeat == 'S');
	return 0;
}
