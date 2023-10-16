#include <iostream>
#include <stdlib.h>	
#include <time.h>

int arreglo[5];
void fill_array();

int main(void)
{
    printf("Programa para ingresar numeros\n");

    fill_array ();



   
    

    return 0;
}

//funcion para rellenar array
void fill_array () 
{
    int mayor = 0, menor = 0, previo = 0;
    
    for (int i = 0; i <= 5; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &arreglo[i]);
        
        if(arreglo[i]> mayor)
        {
            mayor = arreglo[i];

        } else if (arreglo[i] < previo)
        {
            menor = arreglo[i];
        }

        previo = arreglo[i];
    }

    printf("\nEl menor numero ingresado fue: %d", menor);
    printf("\nEl mayor numero ingresado fue: %d", mayor);
}   