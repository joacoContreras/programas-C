#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	/*Diseñar un programa que lea dos números y presente una serie de opciones correspondientes a 
	distintas operaciones que podemos realizar con ellos (suma, resta, multiplicación y división),
	de manera que, en función de la opción elegida, muestre el resultado de la operación realizada. 
	En aquellos casos en los que se desee seguir operando con los mismos números, se debe contestar 'S' 
	(Si a la siguiente pregunta ¿Otra operación con los mismos números (S/N)?.
	En caso de que responda 'N' (No) dar por terminado el programa.*/
	
	int num1=0, num2=0, op=0, ans=0;
	char answer='0';
	
	while (answer='0') {
		printf("Ingrese dos numeros para realizar operacion\n"); scanf("%d%d", &num1, &num2);	
		printf("Seleccione el tipo de operacion\n 1 --> Suma \n 2 --> Resta \n 3 --> Multiplicacion\n 4 --> Division \n "); scanf("%d", &op);
	
	switch(op) {
		case 1: 
			answer='1';
			ans= num1 + num2;
			printf("El resultado es %d \n", ans);
			
			printf("\n ¿Quiere realizar otra operacion con los mismos numeros (S/N)? \n");
		break; 	
		
		default: 
			printf("Numero no valido, reinicie");
		break;
	}
	}

	while (answer=='N') {
		printf(" ¿Quiere realizar otra operacion con los mismos numeros (S/N)? \n"); scanf("%c", &answer);
		if(answer=='S') 
			answer='S';
	}
	
	return 0;
}

