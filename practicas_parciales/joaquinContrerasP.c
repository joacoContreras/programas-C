#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{


    return 0;
}



















































/*
// Definición de estructura para los nodos de pilas
struct StackNode {
    int data;
    struct StackNode* next;
};

// Función para eliminar un nodo de una pila
void popFromStack(struct StackNode** top) {
    if (*top != NULL) {
        struct StackNode* temp = *top;
        *top = (*top)->next;
        free(temp);
    }
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

struct StackNode* stack = NULL;

// Agregar nodos a la pila
    pushToStack(&stack, 10);
    pushToStack(&stack, 20);
    pushToStack(&stack, 30);

    // Imprimir la pila
    printf("Pila: ");
    printStack(stack);

    // Eliminar un nodo de la pila
    popFromStack(&stack);



*/
