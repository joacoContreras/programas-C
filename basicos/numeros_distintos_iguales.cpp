#include <iostream>
using namespace std;
/*9. Ingrese los lados de un triángulo y determine de qué triangulo se trata. 
Si tiene todos los lados diferentes es escaleno, 
todos los lados iguales es equilátero y si tiene dos lados iguales y uno desigual es isósceles. */
int main(int argc, char *argv[]) {
	int n1=0, n2=0, n3=0;
	printf("Ingrese los lados de un triangulo \n");
	scanf("%d%d%d", &n1,&n2,&n3);
	if(n1== n2 && n1 == n3) {
		printf("Es un triangulo Equilatero \n");
	} else if (n1 != n2 && n1!= n3 && n2 != n3) {
		printf("Es un triangulo escaleno \n");
	} else if (n1== n2 && n1 != n3) {
		printf("Es un triangulo isosceles");
	} else if (n2== n3 && n1 != n3) {
		printf("Es un triangulo isosceles");
	} else if (n1== n3 && n1 != n2) {
		printf("Es un triangulo isosceles");
	}
	return 0;
}

