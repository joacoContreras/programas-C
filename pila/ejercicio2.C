#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<time.h>

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

void imprimirPares(struct Stack *stack)
{
    struct Node *current = stack->top;
    printf("\nElementos pares de la pila: ");

    if (current == NULL)
    {
        printf("\nNo hay elementos pares en la pila\n");
    }
    
    while (current != NULL)
    {
        int valor = current -> data;

        if (valor % 2 == 0)
        {
            printf("- %d ", current->data);
            
        }

        current = current ->next;
    }
    
    printf("\n");
}

int main()
{
    struct Stack stack;
    initStack(&stack);
    srand(time(NULL));
    
    int valor = 0;
    for (int i = 0; i < 5; i++)
    {
        valor = rand () % 11 + 1;
        push(&stack, valor);
    }
    
    imprimir(&stack);
    imprimirPares(&stack);
    printf("\nSaliendo...\n");
    liberarMemoria(&stack);

    return 0;
}
