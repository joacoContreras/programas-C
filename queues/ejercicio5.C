#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int data;
    struct Node* next;
};

struct queue
{
    struct Node* front;
    struct Node* rear;
};

struct queue * createQueue()
{
    struct queue * queue = (struct queue*)malloc(sizeof(struct queue));
    queue -> front = queue -> rear = NULL;
    return queue; 
};

int isEmpty(struct queue * queue)
{
    return(queue -> front == NULL);
}

void enqueue(struct queue * queue, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;

    if (queue ->front == NULL)
    {
        queue -> front = newNode;
        queue -> rear = newNode;
    } else
    {
        queue -> rear -> next = newNode;
        queue -> rear = newNode;
    }
}

int main()
{
    srand(time(NULL));
    int data = 0;
    int flag = 0;
    struct queue *myQueue = createQueue();

    for (int i = 0; i < 10; i++)
    {
        data = rand()%10 +1;
        enqueue(myQueue, data);
    }
    

    do
    {
        printf("\nMenu");
        printf("\n1. Agregar nodo a la cola");
        printf("\n2. Borrar primer nodo de la cola");
        printf("\n3. Imprimir cola");
        printf("\n4. Salir");
        printf("\nOpcion: ");

        int opcion = 0;
        scanf("%d",&opcion);

        if (opcion == 1)
        {
            printf("\nIngrese valor para introducir en la cola: ");
            int value = 0;
            int valueToAdd = 0;
            int repetido = 0;
            scanf("%d", &valueToAdd);

            struct Node* current = myQueue -> front;

            while (current != NULL)
            {
                value = current -> data;
                if (valueToAdd == value)
                {
                    printf("\nNumero repetido...\n");
                    repetido = 1;
                    break;
                }
                current = current -> next;
            }

            if (repetido == 0)
            {
                enqueue(myQueue, valueToAdd);
                printf("\nValor agregado exitosamente a la cola...\n");
            }
            
        } else if (opcion == 2)
        {
            if (isEmpty(myQueue))
            {
                printf("\nLa cola esta vacia.");
            }
            else
            {
                struct Node* temp = myQueue -> front;
                myQueue -> front = myQueue -> front -> next;
                free(temp); // Liberar memoria reservada para el nodo
                printf("\nNodo borrado exitosamente");
            }
            
        } else if(opcion == 3)
        {
            struct Node* current = myQueue ->front;

            if (current == NULL)
            {
                printf("\nLa lista esta vacia.\n");
                break;
            }

            while (current != NULL)
            {
                printf(" %d -", current -> data);
                current = current -> next;
            }
            
            
        } else if (opcion == 4)
        {
            printf("\nSaliendo...");
            flag = 1;
        }
        
    } while (flag == 0);
    
    return 0;
}