#include <stdlib.h>
#include <stdio.h>

void aBinario(int numero)
{
    if (numero > 1) 
    {
        aBinario(numero / 2);
    }
    printf("%d", numero % 2);
}

int main()
{
    int numeroIngresado = 0, flag = 0;

    do
    {
        printf("\nIngrese un numero para convertir en binario -> 0 para salir: ");
        scanf("%d", &numeroIngresado);

        if (numeroIngresado == 0)
        {
            exit(0);
        }
        else if (numeroIngresado > 0)
        {
            aBinario(numeroIngresado);
        }
        else
        {
            printf("\nNumero ingresado es negativo\n");
        }

    } while (flag==0);
    
    return 0;
}