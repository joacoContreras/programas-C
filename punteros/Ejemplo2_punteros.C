#include <stdio.h>
#include <stdlib.h>

void modificaVar( int * p, int valor);

int main(void)
{
    int variable = 10;

    modificaVar(&variable, 20);

    printf("\nEl nuevo valor de la variable es: %d\n", variable);


    return 0;
}

void modificaVar(int * p, int valor) 
{
    //Imprimir la direccion de memoria de la variable
    printf("\nLa dirección de memoria es: %p", p);

    //Imprimir el valor actual de la variable cuya direccion se pasa
    printf("\nEl valor actual de la variable es: %d", *p);

    //Modifiquemos el valor de la variable reemplazandolo por "valor"
     *p = valor;

}