#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Estructura que recibe informacion del archivo
struct data {
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

// Estructura para utilizar Cola
struct queue {

    struct Node* rear;
    struct Node* front;
};

// Inicializar cola
struct queue * createQueue()
{
    struct queue* queue =(struct queue*) malloc(sizeof(struct queue));
    queue -> front = queue-> rear = NULL;
    return queue;
}

// Funcion para contar cuantas lineas tiene el archivo a leer
int contarLineas(FILE *archivo);

// Agregar nodo en lista enlazada
void agregarNode(struct Node** lista, struct data dato);

void leer(FILE *archivo, struct Node **lista, int p);

//Imprime toda la informacion del archivo
void imprimir(struct Node *lista);

// Genera memoria para nuevo nodo
struct Node* createNode(struct data datos)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> datos = datos;
    newNode -> next = NULL;
    return newNode;
}

// Agregar elemento a la cola
void enqueue(struct queue* queue, struct data datos)
{
    struct Node* newNode = createNode(datos); // Guardar nodo en la cola 

    if (queue -> front == NULL)
    {
        queue -> front = newNode;
        queue -> rear = newNode;
    }
    else
    {
        queue -> rear -> next = newNode;
        queue -> rear = newNode;
    }
}

// Genera nodo (funciones de lista enlazada 1-4)
void addNode(struct Node** lista, struct data datos)
{
    struct Node* newNode = createNode(datos);

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

// Verificar si la cola esta vacia
int isEmptyQueue(struct queue* queue)
{
    return(queue -> front == NULL);
}

// Liberar memoria de la cola
void liberarCola(struct queue* cola) {
    struct Node* currentNode = cola->front;
    while (currentNode != NULL) {
        struct Node* temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
    free(cola);
}

// Funcion para calcular consumo total acumulado (Joaquin Contreras)
float calcularConsumoTotal(struct Node *lista) {
	float consumoTotal = 0;
	
	while (lista != NULL) {
		consumoTotal += lista->datos.consumo;
		lista = lista->next;
	}
	
	return consumoTotal;
}

// Funcion para calcular el consumo de un mes seleccionado por el usuario (Facundo Degani)
float calcular_Consumo_Mes(struct Node *lista, int mes) {
	float consumo_Mes = 0;
	
	while (lista != NULL) {
		if (lista->datos.mes == mes) {
			consumo_Mes += lista->datos.consumo;
		}
		lista = lista->next;
	}
	return consumo_Mes;
}

// Funcion para identificar el dispositivo menos eficiente (Martin Gonzalez)
const char* identificarDispositivoIneficiente(struct Node* lista) {
	float maxConsumo = lista->datos.consumo;
	const char* dispIneficiente = lista->datos.tipoDispositivo;
	
	if (lista == NULL) {
		return "No hay datos disponibles";
	}
	
	while (lista != NULL) {
		if (lista->datos.consumo > maxConsumo) {
			maxConsumo = lista->datos.consumo;
			dispIneficiente = lista->datos.tipoDispositivo;
		}
		lista = lista->next;
	}
	
	return dispIneficiente;
}

// Funcion para calcular costo por mes (Valentin Albertinazzi)
float calcularCostoMes(struct Node *lista, int mesSeleccionado) {
	float costoTotal = 0.0;
	
	while (lista != NULL) {
		if (lista->datos.mes == mesSeleccionado) {
			costoTotal += lista->datos.costo;
		}
		lista = lista->next;
	}
	
	return costoTotal;
}

void agregarElementosCola(struct Node* lista, struct queue* cola, int mesSeleccionado)
{
	// Recibe el mes ingresado para agregar los elementos a la cola, y poder manipularlos desde ahi

	struct Node* currentNode = lista;

    while (currentNode != NULL) 
	{
		if (currentNode->datos.mes == mesSeleccionado)
		{
			enqueue(cola, currentNode->datos);
		}
		
        currentNode = currentNode->next;
	}
}

// Funcion para calcular promedio de consumo diario - TDA cola (Joaquin Contreras)
float calcularPromedioDiario(struct queue* cola, int diaSeleccionado, int mesSeleccionado)
{
    int cantDias = 0;
    float consumoDia = 0;

	struct Node* currentNode = cola -> front;

	while (currentNode != NULL)
	{
		if (currentNode->datos.mes == mesSeleccionado && currentNode->datos.dia == diaSeleccionado) // Busca el dia en el mes ingresado
        {
            consumoDia += currentNode->datos.consumo;
            cantDias++; // Contamos el día como válido
        }
        currentNode = currentNode->next;
	}

	if (cantDias > 0)
	{
		printf("\nEl consumo del día %d es: %.2f kWh", diaSeleccionado, consumoDia);
        return consumoDia / cantDias;
	}
	else
	{
		printf("\nNo hay datos para el día %d del mes %d", diaSeleccionado, mesSeleccionado);
        return 0.0; // Otra opción, si no hay datos para el día.
	}
}



int main() {
	FILE *archivo;
	struct Node *lista = NULL;
	struct queue *myQueue = createQueue(); 

	archivo = fopen("/home/joaquin/Escritorio/programas-C/t_integrador/dataset.txt", "r");
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo.\n");
		return 1;
	}
	
	int lineas = contarLineas(archivo);
	int p = lineas; // Establece la cantidad de datos
	
	leer(archivo, &lista, p);
	
	int flag = 0;
	do {
		printf("\nMenu: ");
		printf("\n0. Salir");
		printf("\n1. Imprimir datos del archivo");
		printf("\n2. Calcular consumo total acumulado");
		printf("\n3. Calcular el consumo de un mes");
		printf("\n4. Identificar el dispositivo mas ineficiente");
		printf("\n5. Calcular costo total por mes");
		printf("\n6. Calcular promedio de consumo diario");
		printf("\n7. Calcular tendencia de consumo");
		printf("\n8. Dispositivos que superan umbral de consumo");
		printf("\n9. Calcular costo por tipo de dispositivo");
		int opcion = 0;
		printf("\nTu opcion: ");
		scanf("%d", &opcion);
		
		switch (opcion) 
		{
		
			case 0:
				printf("\nSaliendo...\n");
				flag = 1;
				break;

			case 1:
				imprimir(lista);
				break;
				
			case 2: {
				float consumoTotal = calcularConsumoTotal(lista);
				printf("\nConsumo Total acumulado: %.2f kWh\n", consumoTotal);
				break;
			}
			
			case 3: {
				int mesSeleccionado;
				printf("Ingresa el mes para calcular el consumo: ");
				scanf("%d", &mesSeleccionado);
				float consumoMes = calcular_Consumo_Mes(lista, mesSeleccionado);
				printf("El consumo del mes %d es: %.2f kWh\n", mesSeleccionado, consumoMes);
				break;
			}
			
			case 4: {
				const char* dispositivoIneficiente = identificarDispositivoIneficiente(lista);
				printf("El dispositivo mas ineficiente es: %s\n", dispositivoIneficiente);
				break;
			}
			
			case 5: {
				int mesSeleccionado;
				printf("Ingresa el mes para calcular el costo total: ");
				scanf("%d", &mesSeleccionado);
				float costoTotal = calcularCostoMes(lista, mesSeleccionado);
				printf("El costo total del mes es: %.2f$\n", costoTotal);
				break;
			}

			case 6:
			{
				int mes = 0, dia = 0;
				printf("\nIngrese mes(01 - 12): ");
				scanf("%d", &mes);
				printf("\nIngrese dia (01 - 31): ");
				scanf("%d", &dia);

				agregarElementosCola(lista, myQueue, mes);
				float promedioConsumoDiario = calcularPromedioDiario(myQueue, mes, dia);

				printf("\nEl promedio de consumo diario es: %.2f kWh\n", promedioConsumoDiario);
			}
			
			default:
				printf("\nEntrada no valida..\n");
				break;
		}

	} while (flag == 0);
	
	fclose(archivo); // Cerrar archivo
	
	// Liberar la memoria asignada para la lista de nodos
	while (lista != NULL) {
		struct Node *temp = lista;
		lista = lista->next;
		free(temp);
	}
	
	liberarCola(myQueue);

	return 0;
}

// Funcion para contar cuantas lineas tiene el archivo de texto
int contarLineas(FILE *archivo) {
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo.\n");
		return 0;
	}
	
	int contador = 0;
	char caracter;
	
	while ((caracter = fgetc(archivo)) != EOF) {
		if (caracter == '\n') {
			contador++;
		}
	}
	
	// Rebobinar el archivo al comienzo
	rewind(archivo);
	
	return contador;
}

// Funcion para crear un nuevo nodo y agregarlo al final de la lista
void agregarNode(struct Node** lista, struct data dato) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->datos = dato;
	newNode->next = NULL;
	
	if (*lista == NULL) {
		*lista = newNode;
	} else {
		struct Node* current = *lista;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
}

void leer(FILE *archivo, struct Node **lista, int p) {
	if (archivo == NULL) {
		printf("\nNo se pudo abrir el archivo");
		exit(1);
	}
	
	for (int i = 0; i < p; i++) {
		struct data dato;
		
		if (fscanf(archivo, "%d-%d-%d %d:%d:%d,%f,%19[^,],%f,%f,%f", &dato.anio, &dato.mes, &dato.dia, &dato.hora, &dato.minuto, &dato.segundo, &dato.consumo, dato.tipoDispositivo, &dato.tempAmbiente, &dato.potencia, &dato.costo) == 11) {
			agregarNode(lista, dato);
		} else {
			printf("\nError al leer los datos de la linea %d\n", i + 1);
			exit(1);
		}
	}
}

void imprimir(struct Node *lista) {
	printf("\nFecha | Hora | Consumo | Tipo de Dispositivo | Temp. Ambiente | Potencia del E. | Costo ");
	while (lista != NULL) {
		struct data dato = lista->datos;
		printf("\n %d-%d-%d   |   %d:%d:%d   |   %.2f (kWh)   |   %s   |   %.2f   |   %.2f(W)   |   %.2f$\n", dato.anio, dato.mes, dato.dia, dato.hora, dato.minuto, dato.segundo, dato.consumo, dato.tipoDispositivo, dato.tempAmbiente, dato.potencia, dato.costo);
		
		lista = lista->next;
	}
}