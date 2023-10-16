#include <iostream>
#include <stdlib.h>	
#include <time.h>

int pares[10];

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
    int num, cont_impares = 0;
    

    for (int i = 0; i <= 9; i++)
    {
        num = (rand() % (100 - 0 + 1)) + 0; // Generar un número aleatorio en el rango [min, max]

        if (num % 2 == 0)
        {
            pares[i] = num;

        } else
        {
            cont_impares++;
            pares[i] = num + 1;           

        }
            
   }

 printf("\nLa cantidad de numeros impares que salieron fue: %d", cont_impares);
 printf("\nLos valores pares que salieron fueron: ");

for (int i = 0; i <= 9; i++)
    {
        printf("\n%d", pares[i]);
            
   }


}   