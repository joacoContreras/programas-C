#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct data
{
    int anio;
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    float consumo;
    char tipoDispositivo[20];
    float tempAmbiente;
    float potencia;
    float costo;
};

// Función para contar cuántas líneas tiene el archivo de texto
int contarLineas(FILE *archivo)
{
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    int contador = 0;
    char caracter;

    while ((caracter = fgetc(archivo)) != EOF)
    {
        if (caracter == '\n')
        {
            contador++;
        }
    }

    // Rebobinar el archivo al comienzo
    rewind(archivo);

    return contador;
}

void leer(FILE *archivo, struct data datos[], int p)
{
    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL)
    {
        printf("\nNo se pudo abrir el archivo");
        exit(1);
    }

    for (int i = 0; i < p; i++)
    {
        /*%[^,] se utiliza en las funciones de lectura de archivos en C (como fscanf o sscanf) para leer una secuencia de caracteres hasta encontrar una coma (,). */
        
        fscanf(archivo, "%d-%d-%d %d:%d:%d,%f,%[^,],%f,%f,%f",&datos[i].anio, &datos[i].mes, &datos[i].dia, &datos[i].hora, &datos[i].minuto, &datos[i].segundo, &datos[i].consumo, datos[i].tipoDispositivo, &datos[i].tempAmbiente, &datos[i].potencia, &datos[i].costo);
    }
}

void imprimir(struct data datos[], int p)
{
    for (int i = 0; i < p; i++)
    {
        printf("\nFecha: %d-%d-%d", datos[i].anio, datos[i].mes, datos[i].dia);
        printf("\nHora: %d:%d:%d", datos[i].hora, datos[i].minuto, datos[i].segundo);
        printf("\nConsumo %.2f kWh", datos[i].consumo);
        printf("\nTipo de Dispositivo: %s", datos[i].tipoDispositivo);
        printf("\nTemperatura Ambiente: %.2f", datos[i].tempAmbiente);
        printf("\nPotencia del equipo en uso %.2f Watts", datos[i].potencia);
        printf("\nCosto: %.2f $\n", datos[i].costo);
    }
}

int main()
{
    FILE *archivo;

    archivo = fopen("/home/joaquin/Descargas/dataset.txt", "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    int lineas = contarLineas(archivo);
    int p = lineas; // Establece la cantidad de datos

    struct data datos[p];
    leer(archivo, datos, p);
    imprimir(datos, p);

    fclose(archivo); // Cerrar archivo
    return 0;
}

