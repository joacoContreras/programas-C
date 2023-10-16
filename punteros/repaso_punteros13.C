#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int vector[3][4];
    int (* puntero)[4] = vector;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            vector[i][j] = rand () % 100;
        }
    }

    printf("\nValores del arreglo: ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("\n%d", *(*(puntero + j) + i));
        }
    }
    

    return 0;
}