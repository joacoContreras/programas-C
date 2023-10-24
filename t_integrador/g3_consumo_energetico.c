#include <stdio.h>
#include <stdlib.h>
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

struct Node
{
    struct data info;
    struct Node* next;
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

// Función para crear un nodo con los datos
struct Node* crearNodo(struct data info)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->next = NULL;
    return newNode;
}

// Función para agregar un nodo a la lista
void agregarNodo(struct Node** lista, struct data info)
{
    struct Node* newNode = crearNodo(info);

    if (*lista == NULL)
    {
        *lista = newNode;
    }
    else
    {
        struct Node* current = *lista;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}


// Función para liberar la memoria de la lista
void liberarLista(struct Node* lista)
{
    while (lista != NULL)
    {
        struct Node* temp = lista;
        lista = lista->next;
        free(temp);
    }
}

void imprimirLista(struct Node* lista)
{
    struct Node* current = lista;

    while (current != NULL)
    {
        struct data info = current->info;
        printf("\nFecha: %d-%d-%d", info.anio, info.mes, info.dia);
        printf("\nHora: %d:%d:%d", info.hora, info.minuto, info.segundo);
        printf("\nConsumo %.2f kWh", info.consumo);
        printf("\nTipo de Dispositivo: %s", info.tipoDispositivo);
        printf("\nTemperatura Ambiente: %.2f", info.tempAmbiente);
        printf("\nPotencia del equipo en uso %.2f Watts", info.potencia);
        printf("\nCosto: %.2f $\n", info.costo);
        current = current->next;
    }
}

// Funcion para calcular el consumo total
float calcularConsumoTotal(struct Node* lista) //toma puntero "lista" a la struct Node
{
    float consumoTotal = 0;
    struct Node* current = lista; /*Se declara puntero de tipo struct Node y se inicializa con la direccion de memoria de lista (para recorrer la lista a traves de los nodos)*/

    while (current != NULL) //Verifica si hay mas nodos en la lista para recorrer
    {
        struct data info = current ->info; // se le asigna el contenido del nodo actual al que apunta current
        consumoTotal += info.consumo;
        current = current ->next;
    }

    return consumoTotal;
}



int main()
{
    FILE *archivo;

    archivo = fopen("/home/joaquin/Escritorio/programas-C/t_integrador/dataset.txt", "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    int lineas = contarLineas(archivo);
    struct Node* lista = NULL;

    for (int i = 0; i < lineas; i++)
    {
        struct data datos;
        fscanf(archivo, "%d-%d-%d %d:%d:%d,%f,%[^,],%f,%f,%f", &datos.anio, &datos.mes, &datos.dia, &datos.hora, &datos.minuto, &datos.segundo, &datos.consumo, datos.tipoDispositivo, &datos.tempAmbiente, &datos.potencia, &datos.costo);

        agregarNodo(&lista, datos);
    }

    fclose(archivo); // Cerrar archivo

    imprimirLista(lista);

    float totalConsumo = calcularConsumoTotal(lista);
    printf("\nConsumo total acumulado: %.2f kWh\n", totalConsumo);

    liberarLista(lista);

    return 0;
}