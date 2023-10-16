#include <stdio.h>
int main(void)
{
    double A  , B ;
    double *pA = &A ;
    double*pB = &B ;

    printf("Memoria de A: %p\n", pA);

    printf("Memoria de B: %p\n", pB);
    
    printf("Distancia en memoria: %d\n", pB-pA);
    return 0;
}