#include <stdlib.h>
#include <stdio.h>
#include <ctime>

#define COL 4
#define FIL 5

void generar(int tabla[FIL][COL]);
void preguntar(int tabla[FIL][COL]);
void estadisticass(int tabla[FIL][COL]);
void imprimir(int tabla[FIL][COL]);


int main()
{
    

    int tabla[FIL][COL];

    // Establecer la semilla utilizando la función time
    srand(time(NULL));

    printf("Programa para practicar tablas de multiplicar");

    generar(tabla);
    preguntar(tabla);
    imprimir(tabla);
    estadisticass(tabla);




    return 0;
}

void generar(int tabla[FIL][COL])
{
    for (int i = 0; i < FIL; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            tabla[i][j] = rand() % 8 + 1;
        }

        tabla[i][3] =  tabla[i][0] *  tabla[i][1];
        
    }
  
}

void preguntar(int tabla[FIL][COL])
{
    for( int i = 0; i< FIL; i++)
    { 
    
        printf("\n¿Cuanto es %d * %d? Tu respuesta: ", tabla[i][0], tabla[i][1]);
        scanf("%d", &tabla[i][2]);
    
    }
    

}

void imprimir(int tabla[FIL][COL])
{
    for (int i = 0; i < FIL; i++)
    {
        printf("\n(%d) %d * %d = %d | Tu respuesta: %d ",i+1, tabla[i][0], tabla[i][1], tabla[i][3], tabla[i][2]);
    }
}

void estadisticass(int tabla[FIL][COL])
{
    int bien = 0, mal = 0;

    for (int i = 0; i < FIL; i++)
    {
        if (tabla[i][3] == tabla[i][2])
        {
            bien++;
        } else
        {
            mal++;
        }
        
    }

    if (bien == 5)
    {
        printf("\n5 respuestas correctas. ¡Felicitaciones!");

    } else if (bien == 3 || bien == 4)
    {
       printf("\nEntre 3 y 4 respuestas correctas. ¡Bien!, Vas por buen camino.");
    } else
    {
        printf("\n2 o menos respuestas correctas. Hay que practicar más.");
    }
    
    
    
       
}