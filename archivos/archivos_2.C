#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *archivo;

    archivo = fopen("pares.txt", "w");

    if (archivo == NULL)
    {
        printf("\nNo se pudo abrir el archivo para escribir");
        return 1;
    }
    
    // Escribir numeros pares en el archivo
    for (int i = 0; i <= 100; i+=2)
    {
        fprintf(archivo, "%d\n", i);
    }

    fclose(archivo);

    archivo = fopen("pares.txt", "r");
    if (archivo == NULL)
    {
        printf("\nNo se pudo abrir el archivo para leer");
        return 1;
    }
    
    printf("\nContenido del archivo: \n");
    int numero;
    while (fscanf(archivo, "%d", &numero) != EOF) {
        printf("%d\n", numero);
    }
    
    fclose(archivo);

    return 0;
}