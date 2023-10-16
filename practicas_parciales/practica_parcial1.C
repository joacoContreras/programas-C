/*Escriba un programa en C que lea un archivo de texto con datos de personas. Cada linea del archivo contiene los siguientes datos: Nombre, Apellido, Edad. 

El programa debe utilizar una estructura para almacenar los datos de cada persona. La estructura debe tener los siguientes campos: nombre: char[25], apellido: char[25], edad: int

El programa debe utilizar punteros con funciones para realizar las siguientes tareas:

-Leer el archivo de texto y almacenar los datos en una estructura.

-Imprimir los datos de cada persona.

- Liberar la memoria reservada para las estructuras.*/

#include <stdio.h>
#include <stdlib.h>

void read_save(int * np, struct data ** local_data);
void write(int * np, struct data ** local_data);
void free_m(struct data ** local_data);

struct data
{
    char name[25];
    char lastname[25];
    int age = 0;
};



int main()
{
    struct data* local_data;
    int npeople = 0;
    int * np = &npeople;

    read_save(np, &local_data);

    printf("\nImprimiendo datos: ");
    write(np, &local_data);

    free_m(&local_data);
    return 0;
}

void read_save(int * np, struct data ** local_data)
{
    FILE *archivo = fopen("/home/joaquin/Escritorio/IUA/Informática/programas_C/practicas_parciales/p1.txt", "r");
    if (archivo == NULL)
    {
        printf("\nNo se ha podido abrir el archivo");
        exit(1);
    } else
    {
        printf("\nArchivo abierto exitosamente\n");
    }

    int c = 0;
    while ((c = fgetc(archivo)) != EOF)
    {
        if (c == '\n')
        {
            (*np)++;
        }
    }
    rewind(archivo);

    *local_data = (struct data*) malloc (*np * sizeof(struct data));

    for (int i = 0; i < *np; i++)
    {
        fscanf(archivo, "%s %s %d", (*local_data)[i].name, (*local_data)[i].lastname, &(*local_data)[i].age);
    }
    printf("\nArchivo copiado a estructura exitosamente\n");
    fclose(archivo);
}

void write(int * np, struct data ** local_data)
{
    for (int i = 0; i < *np-1; i++)
    {
        printf("\nNombre: %s", (*local_data)[i].name);
        printf("\nApellido: %s", (*local_data)[i].lastname);
        printf("\nEdad: %d\n", (*local_data)[i].age);
    }
}

void free_m(struct data ** local_data)
{
    free(*local_data);
    *local_data = NULL;

    printf("\nMemoria liberada exitosamente\n");
}