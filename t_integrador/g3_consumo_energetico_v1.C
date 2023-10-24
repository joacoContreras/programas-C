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

struct Node {
    struct data datos;
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

// Funcion para crear un nuevo nodo y agregarlo al final de la lista
void agregarNode(struct Node** lista, struct data dato)
{
    struct Node* newNode = (struct Node*)malloc (sizeof(struct Node));
    newNode->datos = dato;
    newNode-> next = NULL;

    if (*lista == NULL)
    {
        *lista = newNode;
    }
    else
    {
        struct Node* current = *lista;
        while (current -> next != NULL)
        {
            current = current -> next;
        }
        current -> next = newNode;
    }
    
}

void leer(FILE *archivo, struct Node **lista, int p)
{
    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL)
    {
        printf("\nNo se pudo abrir el archivo");
        exit(1);
    }
    
    for (int i = 0; i < p; i++)
    {
        struct data dato;

        if (fscanf(archivo, "%d-%d-%d %d:%d:%d,%f,%19[^,],%f,%f,%f", &dato.anio, &dato.mes, &dato.dia,&dato.hora, &dato.minuto, &dato.segundo, &dato.consumo, dato.tipoDispositivo, &dato.tempAmbiente, &dato.potencia, &dato.costo) == 11) // Verificar si se leyeron todos los datos
        {
            agregarNode(lista, dato);
        }
        else
        {
            printf("\nError al leer los datos de la linea %d\n", i+1);
            exit(1);
        }
        
    }
    
}

void imprimir(struct Node *lista)
{
    printf("\nFecha | Hora | Consumo | Tipo de Dispositivo | Temp. Ambiente | Potencia del E. | Costo ");
    while (lista != NULL)
    {
        struct data dato = lista->datos;
        printf("\n %d-%d-%d   |   %d:%d:%d   |   %.2f (kWh)   |   %s   |   %.2f   |   %.2f(W)   |   %.2f$\n",dato.anio, dato.mes, dato.dia, dato.hora, dato.minuto, dato.segundo,dato.consumo, dato.tipoDispositivo, dato.tempAmbiente,dato.potencia, dato.costo);

        lista = lista->next;
    }
    
}

// Funcion para calcular consumo total acumulado
float calcularConsumoTotal(struct Node* lista) //toma puntero "lista" a la struct Node
{
    float consumoTotal = 0;

    while (lista != NULL)
    {
        consumoTotal += lista-> datos.consumo;
        lista = lista->next;
    }

    return consumoTotal;
}

int main()
{
    FILE *archivo;
    struct Node* lista = NULL;

    archivo = fopen("/home/joaquin/Escritorio/programas-C/t_integrador/dataset.txt", "r");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    int lineas = contarLineas(archivo);
    int p = lineas; // Establece la cantidad de datos

    leer(archivo, &lista, p);

    int flag = 0;
    do
    {
        printf("\nMenu: ");
        printf("\n0. Salir");
        printf("\n1. Imprimir datos del archivo");
        printf("\n2. Calcular consumo total acumulado");
        int opcion = 0;
        printf("\nTu opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            imprimir(lista);
            break;

        case 0:
            printf("\nSaliendo...\n");
            flag = 1;
            exit(1);

        case 2:
        {
            float consumoTotal = calcularConsumoTotal(lista);
            printf("\nConsumo Total acumulado: %2.f kWh\n", consumoTotal);
            break;
        }
        
        default:
            
            printf("\nEntrada no valida..");
            break;
        }
    } while (flag == 0);
    
    fclose(archivo); // Cerrar archivo

    // Liberar la memoria asignada para la lista de nodos
    while (lista != NULL)
    {
        struct Node* temp = lista;
        lista = lista -> next;
        free(temp);
    }
    
    return 0;
}


