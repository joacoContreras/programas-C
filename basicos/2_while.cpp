#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*Diseñar un programa que lea dos números y presente una serie de opciones correspondientes a 
	distintas operaciones que podemos realizar con ellos (suma, resta, multiplicación y división),
	de manera que, en función de la opción elegida, muestre el resultado de la operación realizada. 
	En aquellos casos en los que se desee seguir operando con los mismos números, se debe contestar 'S' 
	(Si a la siguiente pregunta ¿Otra operación con los mismos números (S/N)?.
	En caso de que responda 'N' (No) dar por terminado el programa.*/
	
	int num1, num2, result, choice;
	char repeat;
	printf("   Este es un programa que realiza las 4 operaciones basicas a partir de 2 numeros: \n ");
	do {
		
		printf("Ingresa el primer numero:\n ");
		scanf("%d", &num1);
		
		printf("Ingresa el segundo numero:\n ");
		scanf("%d", &num2);
		
		printf("¿Que operacion quieres realizar?\n");
		printf("1. Suma\n");
		printf("2. Resta\n");
		printf("3. Multiplicacion\n");
		printf("4. Division\n");
		printf("Eleccion: ");
		scanf("%d", &choice);
		
		switch (choice) {
		case 1:
			result = num1 + num2;
			printf("El resultado es: %d\n", result);
			break;
			
		case 2:
			result = num1 - num2;
			printf("El resultado es: %d\n", result);
			break;
			
		case 3:
			result = num1 * num2;
			printf("El resultado es: %d\n", result);
			break;
			
		case 4:
			if (num2 == 0) {
				printf("Error, no se puede dividir por cero \n");
			}
			else {
				result = num1 / num2;
				printf("El resultado es: %d\n", result);
			}
			break;
			
		default:
			printf("Opcion invalida\n");
			break;
		}
		
		printf("¿Queres hacer otra operacion con los mismos numeros?(s/n) \n ");
		scanf(" %c", &repeat);
		
	} while (repeat == 's' || repeat == 'S');
	return 0;
}

