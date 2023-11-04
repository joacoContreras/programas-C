#include <stdlib.h>
#include <stdio.h>

void sNaturales(int numero, int *p, int primero)
{
    if (numero > 1) 
    {
        sNaturales(numero-1, p, primero);
    }
    *p +=numero;
    printf("%d", numero);

    if (primero != numero)
    {
        printf(" + ");
    }
    
}

int main()
{
    int numeroIngresado = 0, flag = 0;

    do
    {
        printf("\nIngrese un numero para determinar la suma de los primeros n numeros naturales -> 0 para salir: ");
        scanf("%d", &numeroIngresado);

        if (numeroIngresado == 0)
        {
            exit(0);
        }
        else if (numeroIngresado > 0)
        {
            int sumatoria = 0;
            int *p = &sumatoria;
            int primero = numeroIngresado;
            sNaturales(numeroIngresado, p, primero);

            printf(" = %d", *p);
        }
        else
        {
            printf("\nNumero ingresado es negativo\n");
        }

    } while (flag==0);
    
    return 0;
}