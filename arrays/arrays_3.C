#include <iostream>
#include <stdlib.h>	
#include <time.h>

int arreglo[10];
void fill_array();

int main(void)
{
  
    fill_array();
    

    return 0;
}

//funcion para rellenar array
void fill_array () {
	
	
	srand(time(NULL));
	
	
	for(int i =0; i < 10; i++) {
		
		
		int numero_aleatorio = (rand() % 101) ;
		arreglo[i] = numero_aleatorio;
		
		
		
		printf("%d\n", arreglo[i]);
		
	} 

    printf("\nLos numeros pares de esos 10 numeros son: \n");

    for( int i = 0; i < 10; i++)
    {
        
        if( arreglo[i] % 2 == 0)
        {
            printf("%d\n", arreglo[i]);
        }
    }
}