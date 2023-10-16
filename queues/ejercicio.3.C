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

// Contar elementos de la cola
int size(struct queue* queue) {
    int count = 0;
    struct Node* current = queue->front;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Imprimir valor del fernte
int frontValue(struct queue* queue) {
    if (queue->front == NULL) {
        printf("La cola está vacía, no hay un valor en el frente.\n");
        // También puedes elegir retornar un valor especial o manejar el caso de cola vacía según tus necesidades.
        return -1;
    }
    return queue->front->data;
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
    
    int cont = size(myQueue);
    printf("\nsize cola: %d\n", cont);

    valor = frontValue(myQueue);
    printf("\nValor del frente de la cola: %d\n", valor);
    
    return 0;
}