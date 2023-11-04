#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>

struct Data
{
    char codigo[20];
    char nombre[20];
    int cantidad;
    float precioLista;
};

struct Node
{
    struct Data data;
    struct Node* next;
};

struct Stack
{
    struct Node* top;
};

void initStack(struct Stack* stack)
{
    stack -> top = NULL;
}

bool isEmpty(struct Stack* stack)
{
    return stack->top == NULL;
}

void push(struct Stack* stack, const struct Data Data)
{
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    newNode -> data = Data;
    newNode -> next = stack -> top;
    stack -> top = newNode;
    
}

void deleteLast(struct Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("\nLa lista esta vacia\n");
        return;
    }
    
    struct Node* current = stack ->top;

    while (current->next->next != NULL)
    {
        current= current-> next;
    }

    struct Node* temp = current-> next;
    current->next = NULL;
    free(temp);
    printf("\nElemento inferior eliminado con exito\n");
}

void show(struct Stack* Stack)
{
    struct Node* current = Stack-> top;

    if (isEmpty(Stack))
    {
        printf("\nLa lista esta vacia\n");
        return;
    }
    
    printf("\nProductos:\n");
    
    while (current != NULL)
    {
        printf("%s | %s | %d u.| %.2f$\n",current->data.codigo, current->data.nombre, current->data.cantidad, current->data.precioLista );
        current = current ->next;
    }


}

void deStock(struct Stack* stack)
{
    int cambio = 0;

    if (isEmpty(stack))
    {
        printf("\nLa lista esta vacia\n");
        return;
    }
    
    printf("\nIngrese codigo del producto para descontar Stock: ");
    char lcode[20];
    scanf("%s", lcode);

    struct Node* current = stack-> top;
    while (current != NULL)
    {
        if (strcmp(lcode, current->data.codigo)== 0)
        {
            printf("\nStock actual: %d", current->data.cantidad);
            printf("\nIngrese a cantidad a descontar: ");
            int resta = 0;
            scanf("%d", &resta);
            current->data.cantidad = current->data.cantidad-resta;
            printf("\nStock actualizado: %d", current->data.cantidad);
            cambio++;
            return;
        }   
    }

    if (cambio == 0)
    {
        printf("\nProducto no encontrado\n");
    }
}

void addStock(struct Stack* stack)
{
    int cambio = 0;
    if (isEmpty(stack))
    {
        printf("\nLa lista esta vacia\n");
        return;
    }
    
    struct Node* current = stack -> top;
    while (current != NULL)
    {
        printf("\nIngrese codigo de producto: ");
        char lcode[20];
        scanf("%s", lcode);
        if (strcmp(lcode, current->data.codigo) == 0)
        {
            printf("\nStock actual: %d", current->data.cantidad);
            printf("\nIngrese a cantidad a sumar: ");
            int suma = 0;
            scanf("%d", &suma);
            current->data.cantidad = current->data.cantidad+suma;
            if (current->data.cantidad < 0)
            {
                printf("\nStock descontado mayor al existente\n");
                current->data.cantidad = 0;
                printf("\nStock actualizado: %d\n", current->data.cantidad);
                break;
            }
            
            printf("\nStock actualizado: %d\n", current->data.cantidad);
            cambio++;
            return;
        }
    }

    if (cambio == 0)
    {
        printf("\nProducto no encontrado\n");
    }
}

void clearStack(struct Stack* stack)
{
    while (stack->top != NULL)
    {
        struct Node* temp = stack-> top;
        stack->top = stack->top->next;
        free(temp);
    }
    
}

int main()
{
    struct Stack myStack;
    initStack(&myStack);

    int flag = 0;

    while (flag == 0)
    {
        printf("\nMenu");
        printf("\n0. Salir");
        printf("\n1. Agregar nuevo producto");
        printf("\n2. Borrar ultimo nodo de la pila");
        printf("\n3. Mostrar el stock");
        printf("\n4. Descontar stock");
        printf("\n5. Reponer stock");
        printf("\nOpcion: ");

        int opcion = 0;
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 0:
            exit(1);
            break;

        case 1:
            struct Data nuevoProducto;
            printf("\nCodigo: ");
            scanf("%s", nuevoProducto.codigo);
            printf("\nNombre: ");
            scanf("%s", nuevoProducto.nombre);
            printf("\nCantidad: ");
            scanf("%d", &nuevoProducto.cantidad);
            printf("\nPrecio de Lista: ");
            scanf("%f", &nuevoProducto.precioLista);

            push(&myStack, nuevoProducto);
            break;

        case 2:
            deleteLast(&myStack);
            break;

        case 3:
            show(&myStack);
            break;

        case 4: 
            deStock(&myStack);
            break;
        
        case 5:
            addStock(&myStack);
            break;
        
        default:
            {
                printf("\nValor ingresado incorrecto\n");
                break;
            }
        }
    }
    

    clearStack(&myStack);
    return 0;
}
