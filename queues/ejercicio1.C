#include <stdio.h>
#include <stdlib.h>

// Definicion de struct Node
struct Node
{
    int data;
    struct Node *next;
};

// Definicion de struct queue
struct queue
{
    struct Node* front;
    struct Node* rear;
};

// Funcion para crear una queue vacia
struct queue* createqueue()
{
    struct queue * queue = (struct queue*) malloc(sizeof(struct queue));
    queue -> front = queue -> rear = NULL;
    return queue; 
}

// Funcion oara verificar si la cola esta vacia
int isEmpty(struct queue* queue)
{
    return(queue -> front == NULL);
}

// Funcion agregar nodo
void enqueue(struct queue* queue, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->front == NULL) {
        // Si la cola está vacía, el nuevo nodo será el primero
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Si la cola ya tiene elementos, agregamos el nuevo nodo al final
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Funcion para borrar el primer nodo de la cola
void dequeue(struct queue*queue)
{
    if(isEmpty(queue))
    {
        printf("\nLa cola esta vacia. No se puede borrar ningun nodo\n");
        return;
    }

    struct Node *temp = queue -> front;
    queue -> front = queue -> front -> next;
}

// Funcion para calcular la suma de los valores de la cola
int sumQueue(struct queue *queue)
{
    int sum = 0;
    struct Node *current = queue -> front;

    while (current != nullptr)
    {
        sum += current -> data;
        current = current -> next;
    }

    return sum;
}

// Funcion para imprimir cola
void printQueue(struct queue* queue)
{
    struct Node*current = queue -> front; //Comenzar de izq. a der.

    if (current == NULL)
    {
        printf("\nLa cola esta vacia\n");
        return;
    }

    printf("\nElementos de la cola: ");

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current -> next;
    }
    
    printf("\n");
}


int main()
{
    
    int flag = 0;
    struct queue *myQueue = createqueue();

    do
    {
        printf("\nMenu");
        printf("\n1. Agregar nodos a la cola");
        printf("\n2. Borrar primer nodo de la cola");
        printf("\n3. Suma de los valores de la cola");
        printf("\n4. Imprimir cola");
        printf("\n5. Salir");
        printf("\nOpcion: ");

        int opcion = 0;
        scanf("%d",&opcion);

        switch (opcion)
        {
        case 1:
        {
            int valor = 0;

            for (int i = 0; i < 5; i++)
            {
                printf("\nIngrese un valor para agregar al a cola: ");
                scanf("%d", &valor);
                enqueue(myQueue, valor);
            }

            break;
            }
            

        case 2:
            dequeue(myQueue);
            printf("El primer nodo ha sido eliminado de la cola.\n");
            break;

        case 3:
            if (isEmpty(myQueue))
            {
                printf("La cola esta vacia. La suma es 0.\n");
            }
            else
            {
                int suma = sumQueue(myQueue);
                printf("La suma de los valores en la cola es: %d\n", suma);
            }
            break;
        case 4:
            printQueue(myQueue);

        break;

        case 5:
            flag = 1;
            break;
        
        default:
            printf("Opcion no valida. Intente de nuevo.\n");
            break;
        }
    
    } while (flag == 0);
    
    return 0;
}