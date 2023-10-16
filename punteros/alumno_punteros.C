#include <stdio.h>
#include <stdlib.h>

void cargar_datos(int * legajo, int * dni);
void imprime_alumno(int legajo, int dni);

int main(void)
{
   int legajo, dni;

   cargar_datos(&legajo, &dni);
   imprime_alumno(legajo, dni); 


    return 0;
}

void cargar_datos(int * legajo, int * dni)
{
     printf("Ingresar legajo de alumno: "); 
     scanf("%d", legajo);

     printf("\nIngresar dni alumno: ");
     scanf("%d", dni);

}

void imprime_alumno(int legajo, int dni) 
{
    printf("\nEl numero de legajo del alumno es: %d", legajo);
    printf("\nEl dni del alumno es: %d", dni);
}