#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// Definicion de struct Node
struct Node
{
    char data;
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

// Funcion para verificar si la cola esta vacia
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

// Función para contar letras mayúsculas y minúsculas en la cola
void countLetters(struct queue* queue) {
    int uppercaseCount = 0;
    int lowercaseCount = 0;
    struct Node* current = queue->front;

    while (current != NULL) {
        char value = current->data;

        if (isupper(value)) {
            uppercaseCount++;
        } else if (islower(value)) {
            lowercaseCount++;
        }

        current = current->next;
    }

    printf("\nLetras mayúsculas en la cola: %d", uppercaseCount);
    printf("\nLetras minúsculas en la cola: %d", lowercaseCount);
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
        printf("\n3. Cantidad de nodos en la cola");
        printf("\n5. Cantidades de letras mayusculas y mninusculas en la cola");
        printf("\n4. Imprimir cola");
        printf("\n6. Salir");
        printf("\nOpcion: ");

        int opcion = 0;
        scanf("%d",&opcion);

        switch (opcion)
        {
        case 1:
        {
            char valor = 0;

            printf("\nIngrese un valor para agregar al a cola: ");
            scanf(" %c", &valor);
            enqueue(myQueue, valor);
    

            break;
            }
            

        case 2:
            dequeue(myQueue);
            printf("El primer nodo ha sido eliminado de la cola.\n");
            break;

        case 3:

            int cont = size(myQueue);
            printf("\nHay %d nodos en la cola", cont);
            break;

        case 4:
            printQueue(myQueue);
            break;

        case 5:
            countLetters(myQueue);
            break; // Deja el break aquí para salir del caso 5

        case 6:
            flag = 1;
            break; // Deja el break aquí para salir del bucle

        
        default:
            printf("Opcion no valida. Intente de nuevo.\n");
            break;
        }
    
    } while (flag == 0);
    
    return 0;
}