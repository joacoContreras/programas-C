#include <iostream>
#include <stdlib.h>	
#include <time.h>

int arreglo[50];
void fill_array();

int main(void)
{
    printf("Programa para ingresar de saldos (50 max)\n");

    fill_array ();



   
    

    return 0;
}

//funcion para rellenar array
void fill_array () 
{
    int i = 0, cont_mayor = 0, cont_menor = 0, saldos = 0;
    float promedio = 0, total = 0;
    do {
     
         printf("\nIngrese numero (0 para cancelar): ");
         scanf("%d", &arreglo[i]);

        total += arreglo[i];
        i++;
        saldos++;

    } while ( i < 50 && arreglo[i-1] != 0 && arreglo[i-1] >= 0);	


    promedio = total / i;

    for( i = 0; i < 50; i++)
    {
        if(arreglo[i] > promedio)
        {
            cont_mayor++;

        } else if( arreglo[i] > 0 && arreglo[i] <= promedio)
        {
            cont_menor++;

            
        }
    }
    
    printf("\nSe han cargado %d saldos", saldos);
    printf("\nEl promedio de los saldos cargados es: %0.2f", promedio);
    printf("\nFue recaudado en el mes: %0.2f", total);
    printf("\nHubo %d saldos mayores al promedio", cont_mayor);
    printf("\nHubo %d saldos menores o iguales al promedio", cont_menor);


}   