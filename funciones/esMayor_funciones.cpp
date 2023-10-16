#include <iostream>
using namespace std;

void inicio();
int encontrar_mayor(int x, int y);



int main(int argc, char *argv[]) {
	printf("Programa para detectar el numero mayor ingresado\n");
	inicio();
	
	return 0;
}

void inicio(){
	int n1=0, n2=0, z=0;
	printf("\nIngrese primer numero:");
	scanf("%d",&n1);
	
	printf("\nIngrese segundo numero:");
	scanf("%d",&n2);
	
	z= encontrar_mayor(n1 ,n2);
	
	if (z!= 0) {
		
	printf("\nEl numero %d es mayor", z);
	
	}else {
		
		printf("\nLos numeros son iguales");
	}
}

	int encontrar_mayor(int x, int y) {
		
		int num_max;
		
		if(x, y) {
			num_max = x;
			
		} else if (y> x){
			num_max = y;
			
		} else if (x = y) {
			num_max = 0;
		}
		return num_max;
	}
