#include <stdio.h>
#include <time.h>
#define NUM 10


int main ()
{
    int vector[NUM];
    int * puntero;

    puntero = vector;

    for (int i = 0; i < NUM; i++)
    {
        printf("\nIngrese numero: ");
        scanf("%d",&*(puntero + i));
    }

    float promedio = 0;

    for (int i = 0; i < NUM; i++)
    {
        promedio += (float)*(puntero + i);
    }

    for (int i = 0; i < NUM; i++)
    {
        printf("\n%d",*(puntero + i));
    }
    
    printf("\nEL promedio total es: %.2f", promedio/NUM);

    return 0;
}