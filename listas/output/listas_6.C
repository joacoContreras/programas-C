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

    //Funcion para eliminar un nodo por valor

    void deleteNode(struct Node** head, int key)
    {
        struct Node* temp = *head;
        struct Node* prev = NULL;

        // Si el nodo a eliminar es el head

        if (temp != NULL && temp -> data == key)
        {
            *head =  temp -> next;
            // Cambia la cabeza de la lista
            free(temp); //LIbera la memoria del nodo
            return;
        }
        // Busca el nodo a eliminar y lleva un puntero al nodo anterior
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        // Si no se encontro el nodo, no hace nada
        if (temp == NULL)
        {
            printf("\nNo se encontro el valor ingresado...\n");
            exit(1);
        }
        
        // Desvincula el nodo de la lista
        prev -> next = temp -> next;

        // Libera la memoria del nodo
        free(temp);
        
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
    
    // Imprimir lista orginal
    printf("\nImprimiendo lista: ");
    printList(head);
    
    // Borrar nodo con valor 
    printf("\nIngresar valor del nodo a borrar: ");
    int target = 0;
    scanf("%d", &target);
    deleteNode(&head, target);
    
    //Imprimir nuevamente la lista
    printf("\nNueva lista...\n");
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