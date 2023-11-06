#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{




    return 0;
}






































































/*
Lista doble

// Definición de estructura para los nodos de listas dobles
struct DoubleNode {
    int data;
    struct DoubleNode* next;
    struct DoubleNode* prev;
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

// Función para imprimir una lista doble
void printDoubleList(struct DoubleNode* head) {
    struct DoubleNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct DoubleNode* doubleList = NULL;

// Agregar nodos a la lista doble
    addToDoubleList(&doubleList, 1);

    // Eliminar un nodo de la lista doble
    removeFromDoubleList(&doubleList, 2);

    // Imprimir la lista doble después de la eliminación
    printf("Lista Doble después de eliminar un nodo: ");
    printDoubleList(doubleList);

*/
