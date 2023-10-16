#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

// Funcion Para verificar si la cola esta vacia
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

// Funcion para imprimir numeros pares de la cola
void printQueuepair(struct queue* queue)
{
    struct Node*current = queue -> front; //Comenzar de izq. a der.

    if (current == NULL)
    {
        printf("\nLa cola esta vacia\n");
        return;
    }

    printf("\nElementos pares de la cola: ");

    while (current != NULL)
    {
        if (current ->data % 2 == 0)
        {
            printf("%d ", current->data);
        }

        current = current -> next;
    }

    printf("\n");
}


int main()
{
    int valor = 0;
    srand(time(NULL));
    struct queue *myQueue = createqueue();

    for (int i = 0; i < 5; i++)
    {
        valor = (rand() % 10) +1;
        enqueue(myQueue, valor);
    }
    
    
    printQueue(myQueue);
    printQueuepair(myQueue);

    return 0;
}