#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct data
{
    char codigo[20];
    char nombre[20];
    int cantidad;
    float precioLista;
};

struct queue
{
    struct Node* front;
    struct Node* rear;
};

struct Node
{
    struct data info;
    struct Node* next;
};

// Se crea la cola y gestiona memoria
struct queue * createQueue()
{
    struct queue* queue = (struct queue*) malloc(sizeof(struct queue));
    queue -> front = queue -> rear = NULL;
    return queue;
}

struct Node* createNode(struct data info)
{
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode-> info = info;
    newNode -> next = NULL;
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
        queue -> rear-> next = newNode;
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

void liberarLista(struct Node* lista)
{
    while (lista != NULL)
    {
        struct Node* temp = lista;
        lista = lista -> next;
        free(temp);
    }
}

int isEmpty(struct queue* queue)
{
    return(queue -> front == NULL);
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
        printf("\n1. Agregar nuevo producto");
        printf("\n2. Borrar primero nodo de la cola");
        printf("\n3. Mostrar stock");
        printf("\n4. Descontar stock");
        printf("\n5. Reponer stock");
        printf("\n6. Salir");
        printf("\nTu opcion: ");
        int opcion = 0;
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            struct data datos;

            printf("\nIngresar codigo: ");
            scanf("%s", datos.codigo);
            printf("\nIngresar nombre: ");
            scanf("%s", datos.nombre);
            printf("\nIngresar cantidad: ");
            scanf("%d", &datos.cantidad);
            printf("\nIngresar precio de lista: ");
            scanf("%f", &datos.precioLista);

            enqueue(myQueue, datos);
            printf("\nProducto agregado a la cola...\n");
            break;
        }

        case 2:
        {
            if (isEmpty(myQueue))
            {
                printf("\nLa cola esta vacia\n");
            }
            else
            {
                struct Node* temp = myQueue -> front;
                myQueue -> front = myQueue -> front -> next;
                free(temp);
                printf("\nNodo borrado exitosamente\n");
            }
        }    
        
        case 3:
        {
            struct Node* current = myQueue -> front;
            if (isEmpty(myQueue))
            {
                printf("\nLa cola esta vacia\n");
            }
            else
            {
                while(current != NULL)
                {
                    printf("\nCodigo: %s", current -> info.codigo);
                    printf("\nStock: %d", current -> info.cantidad);
                    current = current -> next;
                }
            }
        }


        default:
        {
            break;
        }
            
        }

    } while (flag == 0);

    return;
}