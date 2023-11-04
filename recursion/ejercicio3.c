#include <stdlib.h>
#include <stdio.h>

int calcularPotencia(int base, int exponente) 
{
    if (exponente == 0) {
        return 1;
    }

    int mitad = calcularPotencia(base, exponente / 2);
    int resultado = mitad * mitad;
    
    if (exponente % 2 == 1) {
        resultado *= base;
    }
    return resultado;
}

int main()
{
    int base = 0, exponente = 0, flag = 0;

    do
    {
        printf("\nIngrese un numero para determinar la potencia de un numero -> 0 para salir");
        printf("\nNumero a elevar: ");
        scanf("%d", &base);
        printf("Potencia: ");
        scanf("%d", &exponente);

        if (base == 0)
        {
            exit(0);
        }
        else if (exponente > 0)
        {
            int resultado = calcularPotencia(base, exponente);
            printf("\n%d elevado a la %d es igual a %d\n", base, exponente, resultado);
        }
        else
        {
            printf("\nNumero ingresado es negativo\n");
        }

    } while (flag==0);
    
    return 0;
}