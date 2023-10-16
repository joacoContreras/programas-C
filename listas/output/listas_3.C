#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Definicion de la estructura de un nodo en la lista

struct Node
{
    int data;           //Almacena el dato del nodo
    struct Node* next;  // Puntero al siguiente nodo
};

// Funcion para insertar un nodo al principio de la lista
void insertAtBeginning(struct Node** head, int data)
{
    // Crear un nuevo nodo
    struct Node* newNode = (struct Node*)malloc (sizeof(struct Node));

    // Asignar el dato y el puntero al siguiente nodo
    newNode ->data = data;
    newNode ->next = *head;

    // El nuevo nodo se convierte en la nueva cabeza de la lista

    *head = newNode;
    
}

    // Funcion para imprimir la lista
    void printList(struct Node* head)
    {
        struct Node* current = head;

        while (current != NULL)
        {
            printf("%d -> ", current->data);
            current = current -> next;
        }
        printf("NULL\n");
    }

    void printCinco(struct Node* head)
    {
        struct Node* current = head;
        printf("\nElementos multiplos de 5: ");

        int contador = 0;
        while (current != NULL)
        {
            if (current -> data % 5 == 0 && current -> data != 0)
            {
                printf("%d -> ", current->data);
                contador++;
            }

            current = current -> next;
        }

        if (contador == 0)
        {
            printf("\nNo hay elementos multiplos de 5...");
        }
    }

int main ()
{
    struct Node* head = NULL; // La lista esta vacia
    int valor;
    
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        valor = rand() % 11;
        insertAtBeginning(&head, valor);
    }
    
    printf("\nImprimiendo lista: ");
    printList(head);
    printCinco(head);
    
    //Liberar memoria
    struct Node* current = head;
    while (current != NULL)
    {
        struct Node* temp = current;
        current = current -> next;
        free(temp);
    }

    return 0;
}