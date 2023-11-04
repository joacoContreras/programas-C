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

void push(struct Stack *stack, char value)
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack ->top;
    stack->top = newNode;
    printf("\nNodo agregado con exito\n");
}

void popLast(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("La pila está vacía, no se puede eliminar el fondo.\n");

    } else if (stack -> top->next == NULL)
        {
            free(stack->top);
            stack -> top = NULL;
            printf("\nUltimo elemento eliminado\n");
            
        } else 
            {
                struct Node* current = stack -> top;
                while (current->next-> next != NULL)
                {
                    current = current -> next;
                }
                free(current -> next);
                current -> next = NULL;
                printf("\nUltimo elemento eliminado\n");
                
            }
}

void tipoLetra(struct Stack *stack, int *pminus, int *pmayus)
{
    struct Node* current = stack -> top;

    while(current!= NULL)
    {
        char c = current ->data;

        if (c >= 'A' && c <= 'Z')
        {
            (*pmayus)++;
        }
        else if (c >= 'a' && c <= 'z')
        {
            (*pminus)++;
        }

        current = current->next;
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
        printf("%c - ", current->data);
        current = current ->next;
    }
    
    printf("\n");
}

int numElementos(struct Stack *stack)
{
    struct Node *current = stack -> top;
    int numElementos = 0;

    if (current == NULL)
    {
        printf("\nNo hay elementos en la pila\n");
    }
    
    while (current != NULL)
    {
        numElementos++;
        current = current ->next;
    }

    return numElementos;
}


int main()
{
    int flag = 0;
    struct Stack stack;
    initStack(&stack);
    srand(time(NULL));

    do
    {            
        printf("\nMenu\n");
        printf("\n1. Agregar nodo a la pila (letra mayuscula o minuscula");
        printf("\n2. Borrar el ultimo nodo de la pila");
        printf("\n3. Imprimir pila");
        printf("\n4. Cantidad de nodos en la pila");
        printf("\n5. Cantidades de letras mayusculas y minusculas");
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
        {   
            char letra = 0;
            printf("\nIngresar letra: ");
            scanf(" %c",&letra);
            push(&stack, letra);
            
            break;
        }

        case 2:
        {
            popLast(&stack);
            break;
        }

        case 3:
        {
            imprimir(&stack);
            break;
        }

        case 4:
        {
            int num = numElementos(&stack);

            if (num != 0)
            {
                printf("\nHay %d nodos en la pila",num);
            }
        break;
        }

        case 5:
        {
            int mayus = 0, minus = 0;
            int *pmayus = &mayus;
            int *pminus = &minus;

            tipoLetra(&stack, pminus, pmayus);
            
            if (mayus != 0)
            {
                printf("\nHay %d letras mayusculas.\n", mayus);
            }
            
            if (minus!=0)
            {
                printf("\nHay %d letras minusculas.\n", minus);
            }
            
            if (minus == 0 && mayus == 0)
            {
                printf("\nNo hay letras ingresadas\n");

            }
            break;
        }
        
        default:
            printf("\nValor ingresado incorrecto...");
            break;
        }
        

    } while (flag == 0);
        
    liberarMemoria(&stack);
    return 0;
}
