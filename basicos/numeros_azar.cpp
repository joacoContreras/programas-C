#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char*argv[]){
	int v_acumulado = 0º;
	int v_leido = 0;
	int c = 0;
	int n = 0, total = 0;
	printf("Cantidad de numeros que vas a ingresar: \n"); scanf("%d", &n);
	for (c=0; c=n; c++) {
		printf ("Entre valor .:"); scanf ("%d", &v_leido);
		v_acumulado = v_acumulado + v_leido;
	}
		total= v_acumulado / n;
		printf("El total acumulado es .: %d", v_acumulado);
		printf("El promedio total es .: %d", total);

return 0;
}
