#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int numeros[5] = {10, 8, 6 ,4 ,2};

    for (int i=1; i <= 5; i++) 
    {
        if(i % 2 != 0) 
        {
            printf("Numero en posicion %d, es: %d\n", i, numeros[i-1]);
        }



    }


    return 0;
}