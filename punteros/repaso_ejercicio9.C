#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void imprimir_pares(int vector[]);
void imprimir_impares(int vector[]);

int main()
{
    int vector[10];
    int num = 0;
    srand(time(NULL));
    

    for (int i = 0; i < 10; i++)
    {
        num = rand() % 100 +1;
        vector[i] = num;
    }
    imprimir_impares(vector);
    imprimir_pares(vector);

    return 0;
}

void imprimir_pares(int vector[])
{
    printf("\nImprimiendo numeros pares...\n");

    for (int i = 0; i < 10; i++)
    {
        if (vector[i] % 2 == 0)
        {
            
            printf("\n%d\n", vector[i]);
        }
    }

}

void imprimir_impares(int vector[])
{
    printf("\nImprimiendo numeros impares...\n");

    for (int i = 0; i < 10; i++)
    {
        if (vector[i] % 2 != 0)
        {
            printf("\n%d\n", vector[i]);
        }
    }

}
