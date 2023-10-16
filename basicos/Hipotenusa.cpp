#include <iostream>
#include <math.h> //librería de matemática
using namespace std;

int main(int argc, char *argv[]) {
		float catA=0, catB=0, hip=0;
		printf("Ingrese los catetos A y B\n");
		scanf("%f%f",&catA, &catB);
		hip=sqrt(pow(catA,2)+pow(catB,2));
		printf("La hipotenusa es: %0.f",hip);
		return 0;
}

