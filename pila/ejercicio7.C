#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Stack
{
    struct Node* top;
};

struct Node
{
    struct Data data;
    struct Node* next;
};

struct Data 
{
    char patente[20];
    char direccion[10];
    int cantEjes;
    float precio;
};

void initStack(struct Stack* stack)
{
    stack -> top = NULL;
}

bool isEmpty(struct Stack* stack)
{
    return stack -> top == NULL;
}

void push(struct Stack* stack, const struct Data data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Data));

    if (newNode == NULL)
    {
        printf("\nError, no hay memoria suficiente\n");
        exit(1);
    }

    newNode->data = data;
    newNode -> next = stack -> top;
    stack -> top = newNode;
}

void deleteNode(struct Stack* stack)
{
    struct Node* current = stack -> top;

    if (isEmpty(stack))
    {
        printf("La pila esta vacia\n");
        return;
    }

    struct Node* temp = current -> next;
    current -> next = NULL;
    free(temp);
    printf("\nNodo eliminado con exito\n");    
}

void printN(struct Stack* stack)
{
    printf("\nPila de vehiculos: ");
    struct Node* current = stack -> top;

    if (isEmpty(stack))
    {
        printf("La pila esta vacia\n");
        return;
    }

    while (current ->next != NULL)
    {
        printf("\n%s | %s | %d ejes | %.2f$", current->data.patente, current->data.direccion, current->data.cantEjes, current->data.precio);

        current = current -> next;
    }
}

void ordenarPorDireccion(struct Stack* stack)
{
    if (isEmpty(stack)|| stack->top ->next == NULL)
    {
        printf("\nLa lista esta vacia o tiene un solo elemento\n");
        return;
    }

    int intercambiado;
    struct Node* actual;
    struct Node* siguiente = NULL;

    do
    {
        intercambiado = 0;
        actual = stack-> top;

    while (actual -> next != siguiente)
    {
        if (strcmp("NS",actual->data.direccion)!= 0)
        {
            struct Data temp = actual -> data;
            actual -> data = actual->next->data;
            actual->next->data = temp;
            intercambiado = 1;
        }

        actual = actual -> next;

        }
        siguiente = actual;

    } while(intercambiado);
    
    printf("La pila se ha ordenado por Direccion.\n");
}

void ordenarPorEjes(struct Stack* stack)
{
    if (isEmpty(stack)|| stack->top ->next == NULL)
    {
        printf("\nLa lista esta vacia o tiene un solo elemento\n");
        return;
    }

    int intercambiado = 0;
    struct Node* actual;
    struct Node* siguiente = NULL;

    do
    {
        intercambiado = 0;
        actual = stack-> top;

    while (actual -> next != siguiente)
    {
        if ((actual -> data.cantEjes) > (actual -> next ->data.cantEjes))
        {
            struct Data temp = actual -> data;
            actual -> data = actual->next->data;
            actual->next->data = temp;
            intercambiado = 1;
        }

        actual = actual -> next;
        }
        siguiente = actual;

    } while(intercambiado);
    
    printf("La pila se ha ordenado por ejes.\n");
}

int main()
{
    struct Stack myStack;
    initStack(&myStack);

    int flag = 0;
    do
    {
        printf("\nMenu");
        printf("\n0. Salir");
        printf("\n1. Agregar vehiculo a la pila");
        printf("\n2. Borrar el ultimo nodo de la pila");
        printf("\n3. Mostrar todos los vehiculos");
        printf("\n4. Mostrar vehiculos por direccion");
        printf("\n5. Mostrar vehiculos por ejes");
        printf("\nOpcion: ");
        int opcion = 0;
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 0:
            printf("\nSaliendo...\n");
            exit(0);

        case 1:
            struct Data nuevoVehiculo;
            printf("\nCPatente: ");
            scanf("%s", nuevoVehiculo.patente);
            printf("\nDireccion: ");
            scanf("%s", nuevoVehiculo.direccion);
            printf("\nCantidad de Ejes: ");
            scanf("%d", &nuevoVehiculo.cantEjes);
        
            if (nuevoVehiculo.cantEjes == 1)
            {
                nuevoVehiculo.precio = 100;
            }
            else if (nuevoVehiculo.cantEjes == 2)
            {
                nuevoVehiculo.precio = 150;
            }
            else if (nuevoVehiculo.cantEjes == 3)
            {
                nuevoVehiculo.precio = 200;
            }
            else if (nuevoVehiculo.cantEjes == 1)
            {
                nuevoVehiculo.precio = 300;
            }
            
            push(&myStack, nuevoVehiculo);
            break;

        case 2:
            deleteNode(&myStack);
            break;

        case 3:
            printN(&myStack);
            break;

        case 4:
        ordenarPorDireccion(&myStack);
            break;

        case 5: 
            ordenarPorEjes(&myStack);
            break;
            
        default:
            printf("\nCaracter ingresado no valido\n");
            break;
        }

    } while (flag == 0);
    


    return 0;
}

