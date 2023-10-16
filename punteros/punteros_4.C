#include <stdio.h>
#include <stdlib.h>



void swap (int * a, int * b)
{
    int memory;

    memory= *a;

    *a = *b;
    *b = memory;

    printf("\nValor de las variables despues del swap: ");
   printf("\nVariable x = %d | Varable y = %d", *a, *b);

  
}

int main(void) {
   
   int x = 10, y = 1;
   
    printf("Valor de las variables antes del swap: ");
    printf("\nVariable x = %d | Varable y = %d", x, y);

    swap(&x, &y);
   



    return 0;
}
