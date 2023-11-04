#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct data
{
    char patente[10];
    int ejes;
    float precio;
    char direccion[5];
};

struct Node
{
    struct data info;
    struct Node* next;
};

struct queue
{
    struct Node* front;
    struct Node* rear;
};

struct queue * createQueue()
{
    struct queue* queue = (struct queue*) malloc(sizeof(struct queue));
    queue -> front = queue -> rear = NULL;
    return queue;
}

struct Node* createNode(struct data info)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode-> info = info;
    newNode-> next = NULL;
    return newNode;
}

void enqueue(struct queue* queue, struct data info)
{
    struct Node* newNode = createNode(info);

    if (queue -> front == NULL)
    {
        queue -> front = newNode;
        queue -> rear = newNode;
    }
    else
    {
        queue -> rear->next = newNode;
        queue -> rear = newNode;
    }
    
}
void addNode(struct Node** lista, struct data info)
{
    struct Node* newNode = createNode(info);

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

int isEmpty(struct queue* queue)
{
    return(queue -> front == NULL);
}

void ordenarPorDireccion(struct Node** lista)
{
    if (*lista == NULL || (*lista)->next == NULL)
    {
        printf("\nLa lista esta vacia\n");
        return;
    }
    int intercambiado = 0;
    struct Node* actual;
    struct Node* siguiente = NULL;

    do
    {
        intercambiado = 0;
        actual = *lista;

    while (actual -> next != siguiente)
    {
        if (strcmp(actual -> info.direccion, actual -> next ->info.direccion) > 0)
        {
            struct data temp = actual -> info;
            actual -> info = actual->next->info;
            actual->next->info = temp;
            intercambiado = 1;
        }

        actual = actual -> next;
        }
        siguiente = actual;

    } while(intercambiado);
    
    
}

void ordenarPorEjes(struct Node** lista)
{
    if (*lista == NULL || (*lista)->next == NULL)
    {
        printf("\nLa lista esta vacia\n");
        return;
    }

    int intercambiado = 0;
    struct Node* actual;
    struct Node* siguiente = NULL;

    do
    {
        intercambiado = 0;
        actual = *lista;

    while (actual -> next != siguiente)
    {
        if ((actual -> info.ejes) > (actual -> next ->info.ejes))
        {
            struct data temp = actual -> info;
            actual -> info = actual->next->info;
            actual->next->info = temp;
            intercambiado = 1;
        }

        actual = actual -> next;
        }
        siguiente = actual;

    } while(intercambiado);
    
    
}

int main()
{
    struct Node* lista = NULL;
    struct queue *myQueue = createQueue();
    srand(time(NULL));
    int flag = 0;

    do 
    {
        printf("\nMenu:\n");
        printf("\n1. Agregar vehiculo a la cola");
        printf("\n2. Borrar primero nodo de la cola");
        printf("\n3. Mostrar todos los vehiculos");
        printf("\n4. Mostrar todos los vehiculos por direccion");
        printf("\n5. Mostrar todos los vehiculos por ejes");
        printf("\n6. Salir");
        printf("\nTu opcion: ");
        int opcion = 0;
        scanf("%d", &opcion);

        if (opcion == 1)
        {
            struct data datos;

            printf("\nIngresar patente: ");
            scanf("%s", datos.patente);
            printf("\nIngresar cantidad de ejes (1-4): ");
            scanf("%d", &datos.ejes);
            
            if (datos.ejes == 1)
            {
                datos.precio = 100;

            } else if (datos.ejes == 2)
            {
                datos.precio = 150;

            } else if (datos.ejes == 3)
            {
                datos.precio = 200;
            
            } else if (datos.ejes == 4)
            {
                datos.precio = 300;
            
            } else
            {
                printf("La cantidad de ejes debe estar en el rango de 1 a 4.\n");
                continue; // Salta de nuevo al menú sin agregar el vehículo
            }       
            char direccion[3];
            do
            {
                printf("\nIngresar direccion (NS o SN): ");
                scanf("%s", datos.direccion);

            } while (strcmp(datos.direccion, "NS") != 0 && strcmp(datos.direccion, "SN") != 0);

            
            strcpy(datos.direccion, direccion);
            enqueue(myQueue, datos);
            printf("\nVehiculo agregado a la cola correctamente\n");
            
        }

        else if(opcion == 2)
        {
            if (isEmpty(myQueue))
            {
                printf("\nLa cola esta vacia.\n");
            }
            else
            {
                struct Node* temp = myQueue -> front;
                myQueue -> front = myQueue -> front -> next;
                free(temp); // Liberar memoria reservada para el nodo
                printf("\nNodo borrado exitosamente\n");
            }
            
        }

        else if(opcion == 3)
        {
            struct Node* current = myQueue -> front;
            if (isEmpty(myQueue))
            {
                printf("\nLa cola esta vacia\n");
            }
            else
            {
                while (current != NULL)
                {
                    printf("\nPatente: %s", current -> info.patente);
                    printf("\nCantidad de ejes: %d", current -> info.ejes);
                    printf("\nDireccion: %s", current -> info.direccion);
                    current = current -> next;
                }
                
            }
            
        }

        else if(opcion == 4)
        {
            if (isEmpty(myQueue))
            {
                printf("\nLa cola esta vacia\n");
            }
            else
            {
                ordenarPorDireccion(&myQueue-> front);
                printf("\nVehículos ordenados por dirección:\n");
                struct Node* current = myQueue->front;
                while (current != NULL)
                {
                    printf("Patente: %s, Dirección: %s\n", current->info.patente, current->info.direccion);
                    current = current->next;
                }
            }
        }
        

        else if(opcion == 5)
        {
            if (isEmpty(myQueue))
            {
                printf("\nLa cola esta vacia\n");
            }
            else
            {
                ordenarPorEjes(&myQueue-> front);
                printf("\nVehículos ordenados por Ejes:\n");
                struct Node* current = myQueue->front;
                while (current != NULL)
                {
                    printf("Patente: %s, Ejes: %d\n", current->info.patente, current->info.ejes);
                    current = current->next;
                }
            }
            
        }

        else if(opcion == 6)
        {
            printf("\nSaliendo...\n");
            flag = 1;
        } 
        else
        {
            printf("\nError");
        }


    } while (flag == 0);
    
    // Libera la memoria de los nodos de la cola
    liberarLista(myQueue->front);
    free(myQueue);
    
    liberarLista(lista);
    return 0;
}
