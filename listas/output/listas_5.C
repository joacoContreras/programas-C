#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Definicion de la estructura de un nodo en la lista

struct Node
{
    char data;           //Almacena el dato del nodo
    struct Node* next;  // Puntero al siguiente nodo
};

// Funcion para insertar un nodo al principio de la lista
void insertAtBeginning(struct Node** head, char data)
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
            printf("%c -> ", current->data);
            current = current -> next;
        }
        printf("NULL\n");
    }

    void printVocals(struct Node* head)
    {
        printf("\nImprimiendo consonantes: ");
        struct Node* current = head;
        
        while (current != NULL)
        {
            char data = current -> data;
            if (data != 'a' && data != 'A' && data !=  'e' && data !=  'E' && data !=  'i' && data !=  'I' && data != 'o' && data != 'O' && data != 'u' && data !=  'U')
            {
                printf("%c -> ", current->data);
                
            }
            current = current -> next;
        }
    }
int main ()
{
    struct Node* head = NULL; // La lista esta vacia
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        int valor = rand() % 52;

        if (valor < 26)
        {
            valor = 'A' + valor;

        } else
        {
            valor = 'a' + (valor - 26);
        }
        
        insertAtBeginning(&head, (char)valor);
    }
    
    printf("\nImprimiendo lista: ");
    printList(head);
    printVocals(head);
    
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