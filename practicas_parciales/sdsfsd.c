#include <stdio.h>
#include <stdlib.h>

// Definición de estructura para los nodos de listas dobles
struct DoubleNode {
    int data;
    struct DoubleNode* next;
    struct DoubleNode* prev;
};

// Definición de estructura para los nodos de pilas
struct StackNode {
    int data;
    struct StackNode* next;
};

// Definición de estructura para los nodos de colas
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Función para agregar un nodo al final de una lista doble
void addToDoubleList(struct DoubleNode** head, int value) {
    struct DoubleNode* newNode = (struct DoubleNode*)malloc(sizeof(struct DoubleNode));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct DoubleNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Función para eliminar un nodo de una lista doble
void removeFromDoubleList(struct DoubleNode** head, int value) {
    struct DoubleNode* current = *head;
    while (current != NULL) {
        if (current->data == value) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

// Función para agregar un nodo a una pila
void pushToStack(struct StackNode** top, int value) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Función para eliminar un nodo de una pila
void popFromStack(struct StackNode** top) {
    if (*top != NULL) {
        struct StackNode* temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

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

// Función para imprimir una lista doble
void printDoubleList(struct DoubleNode* head) {
    struct DoubleNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Función para imprimir una pila
void printStack(struct StackNode* top) {
    struct StackNode* current = top;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
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
    struct DoubleNode* doubleList = NULL;
    struct StackNode* stack = NULL;
    struct QueueNode* queueFront = NULL;
    struct QueueNode* queueRear = NULL;

    // Agregar nodos a la lista doble
    addToDoubleList(&doubleList, 1);
    addToDoubleList(&doubleList, 2);
    addToDoubleList(&doubleList, 3);

    // Imprimir la lista doble
    printf("Lista Doble: ");
    printDoubleList(doubleList);

    // Eliminar un nodo de la lista doble
    removeFromDoubleList(&doubleList, 2);

    // Imprimir la lista doble después de la eliminación
    printf("Lista Doble después de eliminar un nodo: ");
    printDoubleList(doubleList);

    // Agregar nodos a la pila
    pushToStack(&stack, 10);
    pushToStack(&stack, 20);
    pushToStack(&stack, 30);

    // Imprimir la pila
    printf("Pila: ");
    printStack(stack);

    // Eliminar un nodo de la pila
    popFromStack(&stack);

    // Imprimir la pila después de la eliminación
    printf("Pila después de eliminar un nodo: ");
    printStack(stack);

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
