#include <stdio.h>
#include <stdlib.h>

int funcion_suma(int n1, int n2)
{
    int z;
    z = n1 + n2;

    printf("\nEl resultado de la suma sin punteros: %d", z);
    
    return(0);
}

int funcion_punteros(int * puntero1, int * puntero2)
{
     int z;

    z= *puntero1 + *puntero2;
    printf("\nEl resultado de la suma con punteros es: %d", z);

     return(0);
}

int main(void) {
   
   int a, b;
   
   printf("Ingrese primer numero: ");
   scanf("%d", &a);

   printf("\nIngrese segundo numero: ");
   scanf("%d", &b);

   funcion_suma(a, b);
   funcion_punteros( &a, &b);

   



    return 0;
}
