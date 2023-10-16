#include <stdlib.h>
#include <stdio.h>

int main() 
{
    //Declarar un puntero de tipo File para el archivo
    FILE *archivo;
    char nombre[100], apellido[100], dni[20], edad[10], nacionalidad[100];

    //Abrir el archivo en modo de escritura ('w')
    archivo = fopen("datos_personales.txt", "w");

    //Verificar si el archivo se abrio correctamente
    if (archivo == NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        return 1;
    }

    // Carga de datos del usuario
    printf("\nIngrese su nombre: ");
    scanf("%s", nombre);

    printf("\nIngrese su apellido: ");
    scanf("%s", apellido);

    printf("\nIngrese su DNI: ");
    scanf("%s", dni);
    
    printf("\nIngrese su edad: ");
    scanf("%s", edad);

    printf("\nIngrese su nacionalidad: ");
    scanf("%s", nacionalidad);

    // Escribir los datos en el archivo

    fprintf(archivo, "Nombre: %s\n", nombre);
    fprintf(archivo, "Apellido: %s\n", apellido);
    fprintf(archivo, "Dni: %s", dni);
    fprintf(archivo, "Edad: %s", edad);
    fprintf(archivo, "Nacionalidad: %s", nacionalidad);

    // Cerrar el archivo
    fclose(archivo);

    // Abrir archivo en modo lectura ("r")
    archivo = fopen("datos_personales.txt", "r");

    // Verificar si lo abrio correctamente
    if (archivo == NULL)
    {
        printf("\nNo se pudo abrir el archivo");
        return 1;
    }
    
    // Mostrar el contenido del archivo
    printf("\nContenido del archivo: \n");
    char caracter;
    while ((caracter = fgetc(archivo)) != EOF)
    {
        printf("%c", caracter);
    }
    
    // Cerrar el archivo
    fclose(archivo);

return 0;
}

