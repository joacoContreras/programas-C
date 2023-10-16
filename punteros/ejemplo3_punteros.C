#include <stdio.h>
#include <stdlib.h>
#define CONSTANTE  32
void pasar_mayuscula( char * p);

int main (void) 
{
    char letra = 0;

    printf("Ingresar letra para pasar a mayuscula: ");
    scanf(" %c", &letra);
    printf("\nEl caracter ingresado es: %c", letra);

    pasar_mayuscula(&letra);

    printf("\nEl caracter procesado es: %c", letra);

}

void pasar_mayuscula( char * p)
{   
  if (*p >= 'a' && *p <= 'z' )
    {
        *p += -CONSTANTE;

    }

}