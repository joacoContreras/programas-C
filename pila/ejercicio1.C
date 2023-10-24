#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct Node
{
    int data;
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

void push(struct Stack *stack, int value)
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack ->top;
    stack->top = newNode;
}

int pop(struct Stack *stack)
{
    if (!isEmpty(stack))
    {
        struct Node*temp = stack -> top;
        int value = temp-> data;
        stack ->top = stack->top->next;
        free(temp);
        printf("\nElemento borrado con exito");
        return value;

    } else
        {
            printf("\nLa pila esta vacia, no se puede eliminar nodo.\n");
            return -1;
        }
    
}

void liberarMemoria(struct Stack *stack)
{
    while (!isEmpty(stack))
    {
        struct Node* data = stack -> top;
        stack -> top = stack -> top-> next;
        free(data);
    }

}

void imprimir(struct Stack *stack)
{
    struct Node *current = stack->top;
    printf("\nElementos de la pila: ");

    if (current == NULL)
    {
        printf("\nNo hay elementos en la pila\n");
    }
    
    while (current != NULL)
    {
        printf("%d - ", current->data);
        current = current ->next;
    }
    
    printf("\n");
}

void sumatoria(struct Stack *stack)
{
    struct Node *current = stack -> top;
    int sumatoria = 0;

    if (current == NULL)
    {
        printf("\nNo hay elementos en la pila\n");
    }
    
    while (current != NULL)
    {
        sumatoria += current -> data;
        current = current ->next;
    }

    printf("\nEl total es: %d",sumatoria);
}


int main()
{
    int flag = 0;
    struct Stack stack;
    initStack(&stack);

    do
    {            
        printf("\nMenu\n");
        printf("\n1. Agregar nodo a la pila (5 valores)");
        printf("\n2. Borrar el ultimo nodo de la pila");
        printf("\n3. Imprimir pila");
        printf("\n4. Suma de los valores de la pila");
        printf("\n0. Salir");
        printf("\nOpcion: ");
        
        int opcion = 0;
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 0:
            printf("\nSaliendo...\n");
            exit(1);
            break;

        case 1:
        {   int valor = 0;
            for (int i = 0; i < 5; i++)
            {
                printf("\nIngresar valor %d: ",i+1);
                scanf("%d", &valor);
                push(&stack, valor);
            }
            
            break;
        }

        case 2:
        {
            pop(&stack);
        }

        case 3:
        {
            imprimir(&stack);
            break;
        }

        case 4:
        {
            sumatoria(&stack);
        }
        
        default:
            printf("\nValor ingresado incorrecto...");
            break;
        }
        

    } while (flag == 0);
        
    liberarMemoria(&stack);
    return 0;
}
