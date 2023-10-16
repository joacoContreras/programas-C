#include <iostream>
#include <stdlib.h>	
#include <time.h>

int arreglo[20];
void fill_array();

int main(void)
{
    printf("Programa para contar cuantas veces una moneda salio cara o cruz aleatoriamente\n");

    fill_array ();



   
    

    return 0;
}

//funcion para rellenar array
void fill_array () 
{
    srand(time(NULL)); // Inicializar la semilla con el tiempo actual
    int num, cara = 0, cruz = 0;
    
    for (int i = 0; i<= 19; i++)
    {
        num = (rand() % (1 - 0 + 1)) + 0; // Generar un número aleatorio en el rango [min, max]
        arreglo[i] = num;

        if (arreglo[i] == 0) 
        {
            cara ++;
        } else
        {
            cruz++;
        }
    }

    printf("\nCara salio: %d veces", cara);
    printf("\nCruz salio: %d veces", cruz);
}   