#include <stdio.h>

//Declaracion de la funcion
void incrementar ( int * p);


int main(void)
{
    //declaracion variables
  int variable = 5;
  printf("\nvariable= %d", variable);

//Se llama a la funcion
  incrementar(&variable);

  printf("\nvariable = %d", variable);

    return 0;
}

void incrementar (int * p) 
{
    *p = *p+1;

}