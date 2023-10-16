#include <stdio.h>

int main(int argc, char *argv[]) {
	int n1= 0 , n2= 0, r= 0;
	printf ("Ingresar Números: \n");
	scanf ("%d %d", &n1, &n2);
	r = n1 + n2;
	printf ("El resultado es %d", r);
	return 0;
}

