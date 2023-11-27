#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

struct Data
{
    char nombre[20];
    int cantPlatos;
    int cantVendidos;
    float precio;
};

struct Node{
    struct Node* next;
    struct Data data;
};

struct Stack{
    struct Node* top;
};

void insertarNodo(struct Stack* stack, const struct Data data)
{
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("\nNo hay memoria suficiente\n");
        exit(1);
    }

    newNode -> data = data;
    newNode -> next = stack -> top;
    stack -> top = newNode;
    printf("\nNodo agregado con exito\n");
    
}

void borrarNodo(struct Stack* stack)
{
    if (stack -> top == NULL)
    {
        printf("\nLa pila esta vacia\n");
        
    } else{
        struct Node* temp = stack -> top;
        stack -> top = stack-> top -> next;
        free(temp);
        printf("\nNodo eliminado con exito\n");
    }
}

void mostrar(struct Stack* stack)
{
    struct Node* current = stack -> top;
    if (stack -> top == NULL)
    {
        printf("\nLa pila esta vacia\n");

    } else{

        while (current != NULL)
        {
            printf("\n %s | %d | %d | %.2f", current->data.nombre, current->data.cantPlatos, current->data.cantVendidos, current->data.precio);
            current = current -> next;
        }
    }
}

void generarArchivo(struct Stack* stack)
{
    FILE *archivo = fopen("menu.txt", "w");

    if (archivo == NULL)
    {
        printf("\nError al crear archivo\n");
        exit(1);
    }

    struct Node* current = stack-> top;

    while (current != NULL)
    {
        fprintf(archivo, "%s %d %d %.2f\n", current->data.nombre, current-> data.cantPlatos, current->data.cantVendidos, current->data.precio);
        current = current -> next;
    }

    fclose(archivo);
    printf("\nArchivo con la informacion generado exitosamente\n");
}

void liberarMemoria(struct Stack *stack)
{
    struct Node *current = stack->top;

    while (current != NULL)
    {
        stack->top = stack->top->next;
        free(current);
        current = stack->top;
    }

    printf("\nMemoria liberada con éxito\n");
}

void calcularRecaudacion(struct Stack *stack)
{
    int total = 0;
    if (stack ->top == NULL)
    {
        printf("\nLa lista esta vacia\n");
    } else{

        struct Node* current = stack->top;
        while (current != NULL)
        {
            total += current->data.precio * current->data.cantVendidos;
            current = current-> next;
        }
    }

    printf("\nEl total recaudado es: %d", total);
}

void swap(struct Node *a, struct Node* b)
{
    struct Data temp = a-> data;
    a->data = b-> data;
    b-> data = temp;
}

struct Node* partition(struct Stack* stack, struct Node *low, struct Node* high)
{
    struct Data pivot = high -> data;
    struct Node *i = low-> next;

    for (struct Node *j = low; j != high; j = j-> next)
    {
        if (j-> data.precio < pivot.precio)
        {
            swap(i,j);
            i = i ->next;
        }
    }
    
    swap(i, high);
    return i;
}

void quickSort(struct Stack* stack, struct Node *low, struct Node *high)
{
    if (low != NULL && high != NULL && low != high && low != high->next)
    {
        struct Node *pi = partition(stack, low, high);
        quickSort(stack, low, pi-> next);
        quickSort(stack, pi-> next, high);
    }
    
}

void ordenarPila(struct Stack *stack)
{
    if (stack->top != NULL)
    {
        struct Node *last = stack->top;
        while (last->next != NULL)
        {
            last = last->next;
        }

        quickSort(stack, stack->top, last);
        printf("\nPila ordenada por precio usando QuickSort\n");
    }
    else
    {
        printf("\nLa pila está vacía, no hay elementos para ordenar\n");
    }
}

int main()
{
    struct Stack myStack;
    myStack.top = NULL;
    
    int flag = 0;
    do
    {
        printf("\nMenu");
        printf("\n1. Insertar nuevo plato en menu");
        printf("\n2. Mostrar el menu por consola y generar archivo");
        printf("\n3. Eliminar plato del menu");
        printf("\n4. Calcular recaudacion total de platos vendidos");
        printf("\n5. Ordenar los platos por precios usando QuickSort");
        printf("\n6. Salir");
        printf("\nOpcion: ");
        int opcion;
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            struct Data nuevo;
            printf("\nIngrese nombre: ");
            scanf("%s", nuevo.nombre);
            printf("\nIngrese cantidad de platos: ");
            scanf("%d", &nuevo.cantPlatos);
            printf("\nIngrese cantidad de platos vendidos: ");
            scanf("%d", &nuevo.cantVendidos);
            printf("\nIngrese precio de plato: ");
            scanf("%f", &nuevo.precio);

            insertarNodo(&myStack, nuevo);
            break;

        case 2:
            mostrar(&myStack);
            generarArchivo(&myStack);
            break;

        case 3: 
            borrarNodo(&myStack);
            break;

        case 4:
            calcularRecaudacion(&myStack);
            break;

        case 5:
            ordenarPila(&myStack);
            break;

        case 6:
            exit(0);
            break;
        
        default:
            printf("\nCaracter ingresado invalido\n");
            break;
        }
    } while (flag == 0);
    
    liberarMemoria(&myStack);
    return 0;
}