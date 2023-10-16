#include <stdlib.h>
#include <stdio.h>

// Definicion de la estructura de un nodo en la lista

struct Node
{
    int data;           //Almacena el dato del nodo
    struct Node* next;  // Puntero al siguiente nodo
};

// FUncion para insertar un nodo al principio de la lista
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

    
int main ()
{
    struct Node* head = NULL; // La lista esta vacia
    int valor;
    printf("\nIngrese 5 valores numericos");
    for (int i = 0; i < 5; i++)
    {
        valor = 0;
        printf("\nValor %d: ",i+1);
        scanf("%d", &valor);
        insertAtBeginning(&head, valor);
    }
    
    printf("\nImprimiendo lista: ");
    printList(head);

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