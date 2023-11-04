#include <stdio.h>

int invertir(int a)
{
    if(a < 10)
    {
        return a;
    }

    int ultimoDigito = a % 10;
    int numeroSinUDigito = a / 10;

    int invertido = invertir(numeroSinUDigito);

    int decimal = 1;
    while (invertido >= decimal)
    {
        decimal *= 10;
    }

    invertido += ultimoDigito * decimal;
    return invertido;
}


int main()
{
    printf("\nIngresa numero para mostrarlo de forma invertida: ");
    int num = 0;
    scanf("%d", &num);

    int invertido = invertir(num);
    printf("\n%d -> %d\n",num, invertido);
    return 0;
}