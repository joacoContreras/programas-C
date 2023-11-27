#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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


struct Queue {       //estructura de la cola
	struct QueueNode* front;
	struct QueueNode* rear;
};

struct QueueNode {
    float consumoDiario;
    int mes;
    int dia;
	int data;
    struct QueueNode* next;
};
struct TipoDispositivoCostoPromedio {
	char tipo[20];
	float costoAcumulado;
	int cantidadDispositivos;
};


void initQueue(struct Queue* queue) {   //inicializamos la cola
	queue->front = queue->rear = NULL;
}

// Agregar un elemento en la cola
void enqueue(struct Queue* queue, float consumoDiario) {
	struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	if (newNode == NULL) {
		printf("Error: No se pudo asignar memoria para el nuevo nodo de la cola.\n");
		exit(1);
	}
	
	newNode->consumoDiario = consumoDiario;
	newNode->next = NULL;
	
	if (queue->front == NULL) {
		queue->front = newNode;
		queue->rear = newNode;
	} else {
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
}


float dequeue(struct Queue* queue) { // Eliminar un elemento de la cola
	if (queue->front == NULL) {
		return 0; // Valor por defecto si la cola estï¿½ vacï¿½a
	}
	struct QueueNode* temp = queue->front;
	float consumoDiario = temp->consumoDiario;
	queue->front = temp->next;
	if (queue->front == NULL) {
		queue->rear = NULL;
	}
	free(temp);
	return consumoDiario;
}

struct Stack
{
	struct Node* top;
};

void initStack(struct Stack* stack)
{
	stack -> top = NULL;
}

bool isEmpty(struct Stack* stack)
{
	return stack -> top == NULL;
}

void pushStack(struct Stack* stack, struct data data)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

	if (newNode == NULL)
    {
        printf("\nError, no hay memoria suficiente\n");
        exit(1);
    }

    newNode->datos = data;
    newNode -> next = stack -> top;
    stack -> top = newNode;
}

void deleteStack(struct Stack* stack)
{
    struct Node* current = stack -> top;

    if (isEmpty(stack))
    {
        printf("La pila esta vacia\n");
        return;
    }

    struct Node* temp = stack -> top;
    stack -> top = stack -> top -> next;
    free(temp);
    printf("\nNodo eliminado con exito\n");    
}

// Funciï¿½n para contar cuï¿½ntas lï¿½neas tiene el archivo de texto
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

// Funciï¿½n para crear un nuevo nodo y agregarlo al final de la lista
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
		
		if (fscanf(archivo, "%d-%d-%d %d:%d:%d,%f,%19[^,],%f,%f,%f", &dato.anio, 
		&dato.mes, &dato.dia, &dato.hora, &dato.minuto, &dato.segundo, &dato.consumo,
		dato.tipoDispositivo, &dato.tempAmbiente, &dato.potencia, &dato.costo) == 11) {
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
		printf("\n %d-%d-%d   |   %d:%d:%d   |   %.2f (kWh)   |   %s   |   %.2f   |   %.2f(W)   |   %.2f$\n",
		 dato.anio, dato.mes, dato.dia, dato.hora, dato.minuto, dato.segundo, dato.consumo, dato.tipoDispositivo, 
		 dato.tempAmbiente, dato.potencia, dato.costo);
		
		lista = lista->next;
	}
}

//Funcion para calcular el consumo acumulado por dispositivo(Martin Gonzalez)

void calcularConsumoAcumuladoPorDispositivo(struct Node* lista) {
	struct DispositivoConsumo {
		char tipo[20];
		float consumoAcumulado;
	};
	
	struct DispositivoConsumo dispositivos[100];
	int totalDispositivos = 0;
	
	for (int i = 0; i < 100; i++) {
		strcpy(dispositivos[i].tipo, "");
		dispositivos[i].consumoAcumulado = 0.0;
	}
	
	while (lista != NULL) {
		for (int i = 0; i < totalDispositivos; i++) {
			if (strcmp(lista->datos.tipoDispositivo, dispositivos[i].tipo) == 0) {
				dispositivos[i].consumoAcumulado += lista->datos.consumo;
				break;
			}
		}
		
		if (totalDispositivos < 100) {
			int dispositivoEncontrado = 0;
			for (int i = 0; i < totalDispositivos; i++) {
				if (strcmp(lista->datos.tipoDispositivo, dispositivos[i].tipo) == 0) {
					dispositivoEncontrado = 1;
					break;
				}
			}
			
			if (!dispositivoEncontrado) {
				strcpy(dispositivos[totalDispositivos].tipo, lista->datos.tipoDispositivo);
				dispositivos[totalDispositivos].consumoAcumulado = lista->datos.consumo;
				totalDispositivos++;
			}
		}
		
		lista = lista->next;
	}
	
	printf("\nConsumo acumulado por dispositivo:\n");
	for (int i = 0; i < totalDispositivos; i++) {
		printf("%s: %.2f kWh\n", dispositivos[i].tipo, dispositivos[i].consumoAcumulado);
	}
}


// Funciïon para calcular consumo total acumulado (Joaquin Contreras)
float calcularConsumoTotal(struct Node *lista) {
	float consumoTotal = 0;
	
	while (lista != NULL) {
		consumoTotal += lista->datos.consumo;
		lista = lista->next;
	}
	
	return consumoTotal;
}

// Funciï¿½n para calcular el consumo de un mes seleccionado por el usuario (Facundo Degani)
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

// Funciï¿½n para identificar el dispositivo menos eficiente (Martin Gonzalez)
const char*identificarDispositivoIneficiente(struct Node*lista) {
	if (lista==NULL) {
		return "No hay datos disponibles";
	}
	
	float maxConsumo=lista->datos.consumo;
	const char*dispIneficiente=lista->datos.tipoDispositivo;
	
	struct Node*dispositivosMaxConsumo=NULL; 
	
	while (lista != NULL) {
		if (lista->datos.consumo > maxConsumo) {
			maxConsumo = lista->datos.consumo;
			dispIneficiente = lista->datos.tipoDispositivo;
			
			
			while (dispositivosMaxConsumo != NULL) {
				struct Node* temp = dispositivosMaxConsumo;
				dispositivosMaxConsumo = dispositivosMaxConsumo->next;
				free(temp);
			}
			
			struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->datos = lista->datos;
			newNode->next = NULL;
			dispositivosMaxConsumo = newNode;
		} else if (lista->datos.consumo == maxConsumo) {
			
			struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->datos = lista->datos;
			newNode->next = dispositivosMaxConsumo;
			dispositivosMaxConsumo = newNode;
		}
		
		lista = lista->next;
	}
	
	if (dispositivosMaxConsumo == NULL) {
		return "No se encontraron dispositivos ineficientes";
	}
	
	printf("Dispositivo(s) con el mayor consumo (%.2f kWh):\n", maxConsumo);
	while (dispositivosMaxConsumo != NULL) {
		printf("- %s\n",dispositivosMaxConsumo->datos.tipoDispositivo);
		dispositivosMaxConsumo=dispositivosMaxConsumo->next;
	}
	
	return dispIneficiente;
}

// Funciï¿½n para calcular costo por mes (Valentin Albertinazzi)
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


// Calcular el prromedio de consumo diario de un mes y dia especifico (Martin Gonzalez)

float calcularPromedioConsumoDiario(struct Node* lista, int mesSeleccionado, int diaSeleccionado) {
	struct Queue dailyConsumptionQueue;
	initQueue(&dailyConsumptionQueue);
	
	float totalConsumption = 0;
	int count = 0;
	
	while (lista != NULL) {
		if (lista->datos.mes == mesSeleccionado && lista->datos.dia == diaSeleccionado) {
			totalConsumption += lista->datos.consumo;
			count++;
			enqueue(&dailyConsumptionQueue, lista->datos.consumo);
		}
		lista = lista->next;
	}
	
	if (count == 0) {
		return 0; // No hay datos para el dï¿½a y mes especificados
	}
	
	float promedioDiario = totalConsumption / count;
	return promedioDiario;
}

void calcularTendenciaEnMes(struct Queue* queue, int mesSeleccionado) {
	struct QueueNode* current = queue->front;
	int mayor = 0, menor = 0, igual = 0;
	
	while (current != NULL) {
		if (current->next != NULL && current->consumoDiario < current->next->consumoDiario) {
			mayor++;
		} else if (current->next != NULL && current->consumoDiario > current->next->consumoDiario) {
			menor++;
		} else if (current->next != NULL) {
			igual++;
		}
		current = current->next;
	}
	
	if (mayor > menor && mayor > igual) {
		printf("La tendencia del mes %d es ascendente.\n", mesSeleccionado);
	} else if (menor > mayor && menor > igual) {
		printf("La tendencia del mes %d es descendente.\n", mesSeleccionado);
	} else {
		printf("La tendencia del mes %d es constante.\n", mesSeleccionado);
	}
}
void calcularTendenciaEnDia(struct Queue* queue, int mesSeleccionado, int diaSeleccionado) {
	struct QueueNode* current = queue->front;
	int mayor = 0, menor = 0, igual = 0;
	
	while (current != NULL) {
		if (current->next != NULL) {
			if (current->mes == mesSeleccionado && (current->dia == diaSeleccionado || current->dia == 0)) {
				if (current->consumoDiario < current->next->consumoDiario) {
					mayor++;
				} else if (current->consumoDiario > current->next->consumoDiario) {
					menor++;
				} else {
					igual++;
				}
			}
		}
		current = current->next;
	}
	
	if (mayor > menor && mayor > igual) {
		printf("La tendencia en el dia %d del mes %d es ascendente.\n", diaSeleccionado, mesSeleccionado);
	} else if (menor > mayor && menor > igual) {
		printf("La tendencia en el dia %d del mes %d es descendente.\n", diaSeleccionado, mesSeleccionado);
	} else {
		printf("La tendencia en el dia %d del mes %d es constante.\n", diaSeleccionado, mesSeleccionado);
	}
}


// Calcular tendencia de consumo TDA-COLA (Joaquin Contreras)
void tendenciaConsumo(struct Node* lista, int mesSeleccionado, int diaSeleccionado)
{
	struct Queue dailyConsumptionQueue;
	initQueue(&dailyConsumptionQueue);

	int count = 0;

	while (lista != NULL) {
		if (lista->datos.mes == mesSeleccionado && (lista->datos.dia == diaSeleccionado || lista->datos.dia == 0)) {
			count++;
			enqueue(&dailyConsumptionQueue, lista->datos.consumo);
		}
		lista = lista->next;
	}

	if (count == 0) {
		printf("\nNo hay datos para el dia y mes especificados\n");
		return; // No hay datos para el dÃ­a y mes especificados
	}

	if (dailyConsumptionQueue.front == NULL) {
		printf("\nLa cola esta vacia\n");
		return;
	}

	calcularTendenciaEnDia(&dailyConsumptionQueue, mesSeleccionado, diaSeleccionado);
	calcularTendenciaEnMes(&dailyConsumptionQueue, mesSeleccionado);
}

// Funciï¿½n para identificar dispositivos que superan un umbral de consumo en un dï¿½a y mes (FACUNDO DEGANI)
void identificar_Dispositivos_Umbral(struct Node *lista,int dia,int mes,float umbral){
	
	printf("Dispositivos que superan el umbral de consumo de %.2f kWh en el dï¿½a %d del mes %d:\n",umbral,dia,mes);
	
	while(lista!=NULL){
		if(lista->datos.mes==mes && lista->datos.dia==dia && lista->datos.consumo>umbral){
			printf("Tipo de Dispositivo: %s \n",lista->datos.tipoDispositivo);
			printf("consumo: %.2f kwh\n",lista->datos.consumo);
		}
		lista=lista->next;
	}
}
	// Funciï¿½n para calcular el costo por tipo de dispositivo (ALBERTINAZZI VALENTIN)
	void calcularCostoPorTipo(struct Node* lista) {
		// Crear una estructura de datos para rastrear el costo por tipo de dispositivo
		struct TipoDispositivoCosto {
			char tipo[20];
			float costoTotal;
		};
		
		// Inicializar una lista de tipo de dispositivos con costos totales
		struct TipoDispositivoCosto tiposDeDispositivos[100];
		int totalTipos = 0;
		
		// Inicializar los costos totales en 0
		for (int i = 0; i < 100; i++) {
			strcpy(tiposDeDispositivos[i].tipo, "");
			tiposDeDispositivos[i].costoTotal = 0.0;
		}
		
		// Recorrer la lista de nodos y acumular el costo por tipo de dispositivo
		while (lista != NULL) {
			for (int i = 0; i < totalTipos; i++) {
				if (strcmp(lista->datos.tipoDispositivo, tiposDeDispositivos[i].tipo) == 0) {
					tiposDeDispositivos[i].costoTotal += lista->datos.costo;
					break;
				}
			}
			
			// Si el tipo de dispositivo no se encuentra en la lista, agregarlo
			if (totalTipos < 100) {
				int tipoEncontrado = 0;
				for (int i = 0; i < totalTipos; i++) {
					if (strcmp(lista->datos.tipoDispositivo, tiposDeDispositivos[i].tipo) == 0) {
						tipoEncontrado = 1;
						break;
					}
				}
				
				if (!tipoEncontrado) {
					strcpy(tiposDeDispositivos[totalTipos].tipo, lista->datos.tipoDispositivo);
					tiposDeDispositivos[totalTipos].costoTotal = lista->datos.costo;
					totalTipos++;
				}
			}
			
			lista = lista->next;
		}
		
		// Imprimir los costos por tipo de dispositivo
		printf("\nCosto por tipo de dispositivo:\n");
		for (int i = 0; i < totalTipos; i++) {
			printf("%s: %.2f$\n", tiposDeDispositivos[i].tipo, tiposDeDispositivos[i].costoTotal);
		}
	}
	
	// Funcion para calcular Eficiencia - PILA (Joaquin Contreras)

	float calcularEficiencia(struct data dato)
	{
		return dato.potencia / dato.consumo;
	}

	void eficienciaStack(struct Node* lista, struct Stack* stack) 
	{
    struct Node* current = lista; // Apunta al primer nodo de la lista

    while (current != NULL) 
	{
        float eficiencia = calcularEficiencia(current->datos);
        pushStack(stack, current->datos); // Agrega los datos a la pila
        current = current->next;
    }
	}

	void encontrarDispositivoMasEficiente(struct Stack* stack) 
	{
		float maxEficiencia = 0.0;
		struct data dispositivoMasEficiente;
		struct Node* current = stack->top; // Apunta al primer nodo de la pila

		while (current != NULL) 
		{
			float eficiencia = calcularEficiencia(current->datos);
			if (eficiencia > maxEficiencia) {
				maxEficiencia = eficiencia;
				dispositivoMasEficiente = current->datos;
			}
			current = current->next;
		}

		if (maxEficiencia > 0) 
		{
			printf("El dispositivo mas eficiente es:\n");
			printf("Tipo de Dispositivo: %s\n", dispositivoMasEficiente.tipoDispositivo);
			printf("Eficiencia: %.2f (W/kWh)\n", maxEficiencia);
		} 
		else 
		{
			printf("No se encontraron dispositivos en la pila.\n");
		}
	}

	//funcion para calcular la fecha y hora del maximo de consumo de un dispositivo (FACUNDO DEGANI) 
	void identificar_MaxConsumo_Dispositivo(struct Node* lista){
		struct Stack stack;
		initStack(&stack);
		
		// Inicializamos una pila para rastrear los datos
		while (lista!=NULL){
			pushStack(&stack,lista->datos);
			lista=lista->next;
		}
		
		// Crear una estructura para rastrear el máximo consumo por dispositivo
		struct MaxConsumo_Dispositivo {
			char tipo[20];
			float maxConsumo;
			int hora;
			int minuto;
			int segundo;
			int dia;
			int mes;
			int anio;
		};
		
		struct MaxConsumo_Dispositivo maxConsumos[100];
		int total_Dispositivos=0;
		
		// Inicializar la estructura de máximo consumo
		for (int i=0;i<100;i++){
			strcpy(maxConsumos[i].tipo, "");
			maxConsumos[i].maxConsumo=0.0;
			maxConsumos[i].hora=0;
			maxConsumos[i].minuto=0;
			maxConsumos[i].segundo=0;
			maxConsumos[i].dia=0;
			maxConsumos[i].mes=0;
			maxConsumos[i].anio=0;
		}
		
		// Calcular el máximo consumo por dispositivo
		while(!isEmpty(&stack)){
			struct data dato=stack.top->datos;
			for (int i=0;i<total_Dispositivos;i++){
				if (strcmp(dato.tipoDispositivo,maxConsumos[i].tipo)==0){
					if (dato.consumo>maxConsumos[i].maxConsumo){
						maxConsumos[i].maxConsumo=dato.consumo;
						maxConsumos[i].hora=dato.hora;
						maxConsumos[i].minuto=dato.minuto;
						maxConsumos[i].segundo=dato.segundo;
						maxConsumos[i].dia=dato.dia;
						maxConsumos[i].mes=dato.mes;
						maxConsumos[i].anio=dato.anio;
					}
					break;
				}
			}
			
			// Si el dispositivo no se encuentra en la lista, agregarlo
			if(total_Dispositivos<100){
				int dispositivoEncontrado=0;
				for(int i=0;i<total_Dispositivos;i++){
					if(strcmp(dato.tipoDispositivo,maxConsumos[i].tipo)==0){
						dispositivoEncontrado=1;
						break;
					}
				}
				
				if(!dispositivoEncontrado){
					strcpy(maxConsumos[total_Dispositivos].tipo,dato.tipoDispositivo);
					maxConsumos[total_Dispositivos].maxConsumo=dato.consumo;
					maxConsumos[total_Dispositivos].hora=dato.hora;
					maxConsumos[total_Dispositivos].minuto=dato.minuto;
					maxConsumos[total_Dispositivos].segundo=dato.segundo;
					maxConsumos[total_Dispositivos].dia=dato.dia;
					maxConsumos[total_Dispositivos].mes=dato.mes;
					maxConsumos[total_Dispositivos].anio=dato.anio;
					total_Dispositivos++;
				}
			}
			
			deleteStack(&stack);
		}
		
		// Imprimir el resultado
		printf("Máximo consumo por dispositivo:\n");
		for (int i=0;i<total_Dispositivos;i++){
			printf("Tipo de Dispositivo: %s\n",maxConsumos[i].tipo);
			printf("Máximo Consumo: %.2f kWh\n",maxConsumos[i].maxConsumo);
			printf("Fecha y Hora del Máximo Consumo: %d-%d-%d %d:%d:%d\n",
				   maxConsumos[i].anio,maxConsumos[i].mes,maxConsumos[i].dia,
				   maxConsumos[i].hora,maxConsumos[i].minuto,maxConsumos[i].segundo);
			printf("\n");
		}
	}
		void calcularCostoPromedioPorTipo(struct Node* lista) { //(Albertinazzi Valentin)
			struct TipoDispositivoCostoPromedio tiposDeDispositivos[100];
			int totalTipos = 0;
			
			for (int i = 0; i < 100; i++) {
				strcpy(tiposDeDispositivos[i].tipo, "");
				tiposDeDispositivos[i].costoAcumulado = 0.0;
				tiposDeDispositivos[i].cantidadDispositivos = 0;
			}
			
			while (lista != NULL) {
				for (int i = 0; i < totalTipos; i++) {
					if (strcmp(lista->datos.tipoDispositivo, tiposDeDispositivos[i].tipo) == 0) {
						tiposDeDispositivos[i].costoAcumulado += lista->datos.costo;
						tiposDeDispositivos[i].cantidadDispositivos++;
						break;
					}
				}
				
				if (totalTipos < 100) {
					int tipoEncontrado = 0;
					for (int i = 0; i < totalTipos; i++) {
						if (strcmp(lista->datos.tipoDispositivo, tiposDeDispositivos[i].tipo) == 0) {
							tipoEncontrado = 1;
							break;
						}
					}
					
					if (!tipoEncontrado) {
						strcpy(tiposDeDispositivos[totalTipos].tipo, lista->datos.tipoDispositivo);
						tiposDeDispositivos[totalTipos].costoAcumulado = lista->datos.costo;
						tiposDeDispositivos[totalTipos].cantidadDispositivos = 1;
						totalTipos++;
					}
				}
				
				lista = lista->next;
			}
			
			printf("\nCosto promedio por tipo de dispositivo:\n");
			for (int i = 0; i < totalTipos; i++) {
				if (tiposDeDispositivos[i].cantidadDispositivos > 0) {
					float costoPromedio = tiposDeDispositivos[i].costoAcumulado / tiposDeDispositivos[i].cantidadDispositivos;
					printf("%s: %.2f$\n", tiposDeDispositivos[i].tipo, costoPromedio);
				}
			}
		}
		
int main() {
	FILE *archivo;
	struct Node *lista = NULL;
	struct Stack stack;
	initStack(&stack);

	archivo = fopen("dataset.txt", "r");
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
		printf("\n8.identificar los dispositivos que superan un cierto umbral de consumo en un dï¿½a y mes.");
		printf("\n9. Calcular el costo por tipo de dispositivo");
		printf("\n10. Calcular consumo acumulado por dispositivo");
		printf("\n11. Identificar fecha y hora del maximo consumo de cada dispositivo");
		printf("\n12. Identificar el dispositivo con mayor eficiencia ");
		printf("\n13. Calcular costo promedio por tipo de dispositivo");

		int opcion = 0;
		printf("\nTu opcion: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			imprimir(lista);
			break;
			
		case 0:
			printf("\nSaliendo...\n");
			flag = 1;
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
		
		case 6: {
			int mesSeleccionado,diaSeleccionado;
			printf("Ingresa el mes y el dï¿½a para calcular el promedio de consumo diario (MM DD):");
			scanf("%d %d", &mesSeleccionado, &diaSeleccionado);
			float promedioDiario = calcularPromedioConsumoDiario(lista,mesSeleccionado,diaSeleccionado);
			if (promedioDiario==0){
				printf("No hay datos para el dï¿½a y mes especificados.\n");
			} else {
				printf("El promedio de consumo diario para el %d-%d es: %.2f kWh\n",mesSeleccionado,diaSeleccionado,promedioDiario);
			}
			break;
		}
		
		case 7:
		{
			int mesSeleccionado = 0,diaSeleccionado = 0;
			printf("Ingresa el mes y el dia para calcular el promedio de consumo diario (MM DD):");
			scanf("%d %d", &mesSeleccionado, &diaSeleccionado);

			tendenciaConsumo(lista, mesSeleccionado, diaSeleccionado);

			break;
		}
	case 8:
		{
			int diaSeleccionado, mesSeleccionado;
			float umbral;
			
			printf("\nINGRESE EL DIA Y MES PARA IDENTIFICAR EL DISPOSITIVO POR UMBRAL (en numero):\n");
			printf("ingrese el dia:\n");
			scanf("%d",&diaSeleccionado);
			
			printf("Ingresa el mes:\n");
			scanf("%d",&mesSeleccionado);
			
			printf("Ingresa el umbral de consumo en kWh:\n");
			scanf("%f",&umbral);
			
			identificar_Dispositivos_Umbral(lista,diaSeleccionado,mesSeleccionado,umbral);
			
			break;
		}
		case 9: {
			calcularCostoPorTipo(lista);
			break;
		}

		case 10:
			calcularConsumoAcumuladoPorDispositivo(lista);
		{
			break;
		}

		case 11:
		{
			identificar_MaxConsumo_Dispositivo(lista);
			break;
		}
		case 12:
		{
			eficienciaStack(lista, &stack);
			encontrarDispositivoMasEficiente(&stack);
			break;
		}
		case 13: {
			calcularCostoPromedioPorTipo(lista);
			break;
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
	
	return 0;
}
