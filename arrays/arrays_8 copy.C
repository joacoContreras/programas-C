#include <iostream>
#include <stdlib.h>	
#include <time.h>

int arreglo[10];
int nuevo_arreglo[10];
void fill_array();

int main(void)
{

    fill_array ();


    return 0;
}

//funcion para rellenar array
void fill_array () 
{
    srand(time(NULL)); // Inicializar la semilla con el tiempo actual
    int num;
    printf("\nEl primer arreglo es:");
    for (int i = 0; i <= 9; i++)
{
    num = (rand() % (30 - 15 + 1)) + 15; // Generar un número aleatorio en el rango [min, max]
    arreglo[i] = num;
    printf("\n%d", arreglo[i]);
   
}

 printf("\nEl arreglo en orden inverso es:");

for (int i = 9; i >= 0; i--)
{
    printf("\n%d", arreglo[i]);
}


   
}   