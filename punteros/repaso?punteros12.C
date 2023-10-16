#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NUM 5
void valor_minimo(int vector[], int  * puntero);
void valor_max(int vector[], int  * puntero);
void promedio(int vector[], int  * puntero);

int main()
{
    srand(time(NULL));
    int num = 0;
    int vector[NUM];
    int * puntero = vector;

    for (int i = 0; i < NUM; i++)
    {
        num = rand() % 100 + 1;
        *(puntero + i) = num;
        printf("\n%d\n", *(puntero + i));
    }

    valor_minimo(vector, puntero);
    valor_max(vector, puntero);
    promedio(vector, puntero);


    return 0;
}

void valor_minimo(int vector[], int  * puntero)
{
    int minimo = 100;

    for (int i = 0; i < NUM; i++)
    {
        if (*(puntero + i) < minimo)
        {
            minimo = *(puntero + i);
        
        } 
    }
printf("\nEL valor minimo del arreglo es: %d\n", minimo);
}

void valor_max(int vector[], int  * puntero)
{
    int maximo = 0;

    for (int i = 0; i < NUM; i++)
    {
        if (*(puntero + i) > maximo)
        {
            maximo = *(puntero + i);
        
        } 
    }
printf("\nEL valor maximo del arreglo es: %d\n", maximo);
}

void promedio(int vector[], int  * puntero)
{
    int sumatoria = 0;

    for (int i = 0; i < NUM; i++)
    {
    
        sumatoria += *(puntero + i);
        
        
    }
printf("\nEL valor promedio del arreglo es: %.2f\n", (float)sumatoria/NUM);
}

