#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{





    return 0;
}














































/*
// Definición de estructura para los nodos de colas
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Función para agregar un nodo a una cola
void enqueueToQueue(struct QueueNode** front, struct QueueNode** rear, int value) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Función para eliminar un nodo de una cola
void dequeueFromQueue(struct QueueNode** front, struct QueueNode** rear) {
    if (*front != NULL) {
        struct QueueNode* temp = *front;
        *front = (*front)->next;
        if (*front == NULL) {
            *rear = NULL;
        }
        free(temp);
    }
}





// Función para imprimir una cola
void printQueue(struct QueueNode* front) {
    struct QueueNode* current = front;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct QueueNode* queueFront = NULL;
    struct QueueNode* queueRear = NULL;




    // Agregar nodos a la cola
    enqueueToQueue(&queueFront, &queueRear, 100);
    enqueueToQueue(&queueFront, &queueRear, 200);
    enqueueToQueue(&queueFront, &queueRear, 300);

    // Imprimir la cola
    printf("Cola: ");
    printQueue(queueFront);

    // Eliminar un nodo de la cola
    dequeueFromQueue(&queueFront, &queueRear);

    // Imprimir la cola después de la eliminación
    printf("Cola después de eliminar un nodo: ");
    printQueue(queueFront);

    return 0;
}



*/