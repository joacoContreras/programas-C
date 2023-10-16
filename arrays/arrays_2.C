#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int numeros[5];
   
    float promedio = 0, sumatoria= 0 ;
    for (int i=1; i <= 5; i++) 
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &numeros[i-1]);
        sumatoria += numeros[i-1];
    }

    for (int i=1; i <= 5; i++) 
    {
        printf("\n%d", numeros[i-1]);
    }
    promedio = sumatoria / 5;
    printf("\nEl promedio es: %0.2f", promedio);

    return 0;
}