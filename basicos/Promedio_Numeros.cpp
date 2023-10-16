#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int num = 0, cantidad = 0;
	float suma= 0;
	printf("Calcula promedio de una lista de numeros \n");
	printf("Ingresar numeros:"); scanf("%d", &cantidad);
	
	for (int i = 1; 1<= cantidad; i++) {
		printf("Numero %d:", i);
		scanf("%d", &num);
		suma = suma + num;
	}
	rand(time(NULL));
	int i;
	for(i=0; i<101; i++) {
		printf("%d\n", rand()%101);
	}
	suma = suma / cantidad;
	printf("suma promedio es: %f", suma);
return 0;
}
