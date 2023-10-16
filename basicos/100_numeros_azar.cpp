#include<stdio.h>

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
	suma = suma / cantidad;
	printf("suma promedio es: %f", suma);
return 0;
}
