#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
/*Un estudiante est� aprendiendo las tablas de multiplicar del 1 al 10,  
entonces realice un programa que obtenga dos n�meros aleatorios entre el 1 y 10 y a
s� compone una multiplicaci�n. Luego el estudiante ingresa el resultado, y el programa 
deber� evaluar si es correcto o no. En caso de que sea incorrecto brindar la soluci�n. 
Despu�s el programa preguntar� si desea seguir practicando. 
Si el estudiante responde Si 'S' el programa genera otro c�lculo, 
en caso de que diga que No 'N' se dar� por terminada la sesi�n de preguntas y 
mostrar� la cantidad de preguntas en total y cu�ntas respuestas fueron correctas. 
*/

int main(int argc, char *argv[]) {
	int c_ask=0, ask=0, i=0, num1=0,num2=0, res=0, answer=0;
	srand(time(NULL));
	char repeat;
	printf("Programa para aprender las tablas de Multiplicar \n");
	do {
		ask+=1;
		num1=1+rand()%(10-1+1);
		num2=1+rand()%(10-1+1);
		res=num1*num2;
		printf("%d * %d = \n", num1, num2);
		scanf("%d", &answer);
		if(answer==res) {
			printf("La respuesta es correcta \n");
			c_ask+=1;
		} else {
			printf("La respuesta es incorrecta\n");
		}
		printf("Desea seguir practicando? (s/n)\n");
		scanf(" %c", &repeat);
	}while( repeat == 's' || repeat == 'S');
	printf("Total de preguntas %d \n",ask);
	printf("Respuestas correctas %d \n", c_ask);
	return 0;
}

