#include <stdlib.h>
#include <stdio.h>

void menu();

int main()
{

    menu();

    return 0;
}

void menu()
{
    printf("\na. Abrir un archivo\nb. Escribir un archvo\nc. Leer un archivo");
    printf("\nOpcion: ");
    char opcion = 0;
    scanf(" %c", &opcion);

    switch (opcion)
    {
    case 'a':
        
        break;
    
    default:
        break;
    }
}

void abrir()
{
    FILE *archivo;
    archivo = fopen("nombre.text", "w");
}