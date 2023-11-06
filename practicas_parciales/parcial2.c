#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

// Crear nodo
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    return newNode;
}

// Crear nodo al final de la lista
void appendNode(struct Node** head, int value)
{
    struct Node* newNode = createNode(value);

    if (*head == NULL)
    {
        *head = newNode; // lista vacia, newNode = head
    }
    else 
    {
        struct Node* current = *head;
        while (current -> next != NULL)
        {
            current = current -> next;
        }

        current -> next = newNode;
        newNode -> prev = current;
    }
}

// Borrar nodo por valor
void popNodeValue(struct Node** head, int value)
{
    if (*head == NULL)
    {   
        printf("\nLa lista esta vacia\n");
        return; 
    }
    
    
    struct Node* current = *head;
    while (current != NULL)
    {
        if (current -> data == value)
        {

            if (current -> prev != NULL)
            {
                current -> next -> prev = current -> prev;
            }
            else if(current -> next != NULL)
            {
                current-> next-> prev = current -> prev;
            }
            else if(current == *head)
            {
                *head = current -> next;
            }

            printf("\nNodo eliminado\n");
            free(current);
            return;
        }
        current = current -> next;
    }

    printf("\nNo se ha encontrado nodo con el valor ingresado\n");

}

// Borrar ultimo nodo
void popLastNode(struct Node** head)
{
    if (*head == NULL)
    {
        printf("\nLa lista esta vacia\n");
        return;
    }
    
    struct Node* current = *head;
    while (current -> next != NULL)
    {
        current = current -> next;
    }
    
    if(current->prev != NULL)
    {
        current->prev->next= NULL;
    }
    else 
    {
        *head = NULL;
    }

    free(current);
    printf("\nUltimo nodo eliminado\n");
    
}

// Imprimir lista izq a derecha
void show1(struct Node** head)
{
    if (*head == NULL)
    {
        printf("\nLa lista esta vacia\n");
        return;
    }

    struct Node* current = *head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current-> next;
    }
    printf(" NULL\n");
}

// Funcion para imprimir de der a izq
void show2(struct Node** head)
{
    if (*head == NULL)
    {
        printf("\nLa lista esta vacia\n");
        return;
    }

    struct Node* current = *head;
    while (current -> next != NULL)
    {
        current = current -> next;
    }

    printf("NULL ");
    while (current != NULL)
    {
        printf("%d ", current -> data);
        current = current -> prev;
    }

    printf("\n");
}

int main()
{
    srand(time(NULL));
    struct Node* head = NULL;
    int flag = 0;

    do
    {
        printf("\nMenu");
        printf("\n1. Agregar nodo");
        printf("\n2. Borrar ultimo nodo");
        printf("\n3. Borrar nodo por valor");
        printf("\n4. Imprimir lista izq a der");
        printf("\n5. Imprimir lista der a izq");
        printf("\n0. Salir");
        int opcion = 0;
        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 0:
            printf("\nSaliendo...\n");
            exit(0);

        case 1:

            int value = (rand() % (100 + 1));
            appendNode(&head, value);
            printf("\nNodo agregado\n");
            break;
        
        case 2:
            popLastNode(&head);
            break;
        
        case 3:
            printf("\nIngrese valor a borrar: ");
            int delete;
            scanf("%d", &delete);
            popNodeValue(&head, delete);
            break;

        case 4:
            show1(&head);
            break;
        
        case 5:
            show2(&head);
            break;

        default:
            printf("\nError\n");
            break;
        }
    } while (flag == 0);
    
    

    // Liberar memoria
    struct Node* current = head;
    while (current != NULL)
    {
        struct Node* temp = current;
        current = current -> next;
        free(temp);
    }

    return 0;
}