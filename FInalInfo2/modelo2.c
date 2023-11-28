#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Data
{
    char nombre[20];
    int duracion;
    char estado[12];
};

struct Node
{
    struct Node* next;
    struct Data data;
};

struct stack
{
    struct Node* top;
};

void agregarTarea(struct stack *stack, const struct Data data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

void eliminarTarea(struct stack *stack)
{
    if (stack->top == NULL)
    {
        printf("\nLa pila esta vacia\n");
    
    } else{

        struct Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        printf("\nNodo eliminado\n");
    }
}

void mostrar(struct stack *stack)
{
    if (stack->top == NULL)
    {
        printf("\nLa pila esta vacia\n");
    
    }else{
        struct Node* current = stack->top;
        while (current != NULL)
        {
            printf("\n%s | %d | %s\n",current->data.nombre, current->data.duracion, current->data.estado);
            current = current->next;
        }
    }
}

void generarArchivo(struct stack *stack)
{
    FILE *archivo = fopen("proyecto.txt", "w");
    if (archivo == NULL)
    {
        printf("\nError al crear archivo");
    
    } else{
        struct Node* current = stack->top;
        while (current != NULL)
        {
            fprintf(archivo,"%s %d %s\n",current->data.nombre, current->data.duracion,current->data.estado);
            current = current ->next;
        }
        fclose(archivo);
    }
}

void calcularAvance(struct stack* stack)
{
    int cTareas = 0, pendientes = 0, retrasadas = 0, terminadas = 0, completitud = 0;
    struct Node* current = stack->top;
    if (current == NULL)
    {
        printf("\nLa lista esta vacia\n");
    
    } else{
        while (current != NULL)
        {
            cTareas++;

            if (strcmp(current->data.estado,"pendientes") == 0)
            {
                pendientes++;
            }
            else if (strcmp(current->data.estado,"retrasada") == 0)
            {
                retrasadas++;
            }
            else if (strcmp(current->data.estado,"terminada") == 0)
            {
                terminadas++;
            }

            current = current->next;
        }
    }
     // Calcular completitud en base a las tareas terminadas
        completitud = (terminadas * 100) / cTareas;

        // Imprimir resultados
        printf("\nTotal de tareas: %d", cTareas);
        printf("\nPendientes: %d", pendientes);
        printf("\nRetrasadas: %d", retrasadas);
        printf("\nTerminadas: %d", terminadas);
        printf("\nCompletitud: %d%%", completitud);
    }

void swap(struct Node *a, struct Node *b)
{
    struct Data temp = a->data;
    a->data = b->data;
    b->data = temp;
}

struct Node* partition(struct stack* stack, struct Node *low, struct Node *high)
{
    struct Data pivot = high-> data;
    struct Node* i= low->next;

    for (struct Node* j = low; j != high; j = j->next)
    {
        if (j ->data.duracion < pivot.duracion)
        {
            swap(i, j);
            i = i->next;
        }
    }
    swap(i, high);
    return i;
}

void quickSort(struct stack* stack, struct Node *low, struct Node *high)
{
    if (low != NULL && low != high && high != NULL && low != high->next)
    {
        struct Node* pi = partition(stack, low, high);
        quickSort(stack, low,pi->next);
        quickSort(stack, pi->next, high);
    }
}

void ordenarPila(struct stack *stack)
{
    if (stack->top != NULL)
    {
        struct Node * last = stack->top;
        while (last->next != NULL)
        {
            last = last->next;
        }
        quickSort(stack, stack->top, last);
    }
}



int main()
{
    struct stack myStack;
    myStack.top = NULL;
    int flag = 0;
    do
    {
        printf("\nMenu");
        printf("\n1. Agregar nueva tarea al proyecto");
        printf("\n2. Mostrar la lista de tareas por consola y generar un archivo txt");
        printf("\n3. Eliminar tarea del proyecto");
        printf("\n4. Calcular porcentaje de avance del proyecto");
        printf("\n5. Ordenar las tareas por duracion estimada - QuickSort");
        printf("\n6. Salir");
        printf("\nOpcion: ");
        int opcion;
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            struct Data nuevo;
            printf("\nIngrese nombre de tarea:");
            scanf("%s", nuevo.nombre);
            printf("\nIngrese duracion de tarea:");
            scanf("%d", &nuevo.duracion);
            printf("\nIngrese estado de tarea(pendiente/terminada/retrasada):");
            scanf("%s", nuevo.estado);
            agregarTarea(&myStack, nuevo);
            break;

        case 2:
            mostrar(&myStack);
            generarArchivo(&myStack);
            break;
        case 3:
            eliminarTarea(&myStack);
            break;
        case 4:
            calcularAvance(&myStack);
            break;
        case 6:
            printf("\nSaliendo...");
            exit(0);
            break;
        
        default:
            printf("\nCaracter ingresano no valido\n");
            break;
        }
    } while (flag == 0);
    
    return 0;
}