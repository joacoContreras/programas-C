#include <stdlib.h>
#include <stdio.h>
#include <ctime>

#define COL 5
#define FIL 4

void rellenar(float datos[FIL][COL]);
void calcular(float datos[FIL][COL]);
void imprimir(float datos[FIL][COL]);
void mejor_combustible(float datos[FIL][COL]);


int main()
{
    float datos[FIL][COL];

    rellenar(datos);
    calcular(datos);
    imprimir(datos);
    mejor_combustible(datos);
   

    return 0;
}

void rellenar(float datos[FIL][COL])
{
    for (int i = 0; i < FIL; i++)
    {
        datos[i][0] = i;

        printf("\nIngrese precio x litro %d: ", i + 1);
        scanf("%f", &datos[i][1]);

        printf("\nIngrese km recorridos %d: ", i + 1);
        scanf("%f", &datos[i][2]);

        printf("\nIngrese los litros utilizados %d: ",i + 1);
        scanf("%f", &datos[i][3]);
    }
}

void calcular(float datos[FIL][COL])
{
    float km_litros = 0;

    for (int i = 0; i < FIL; i++)
    {
      
        
        km_litros = datos[i][2]/  datos[i][3];
        datos[i][4] = km_litros;

    }
}

void imprimir(float datos[FIL][COL])
{
    printf("\nTipo de combustible | precio x litro | km recorridos | Litros utilizados | km * litro");

    for (int i = 0; i < FIL; i++)
    {
        printf("\n%d | %.2f | %.2f | %.2f| %.2f", i + 1,datos[i][1], datos[i][2], datos[i][3], datos[i][4]);
    }
}

void mejor_combustible(float datos[FIL][COL])
{
    float mejor = 0;
    int combustible = 0;

    for (int i = 0; i < FIL; i++)
    {
        if (datos[i][4] > mejor)
    {
        mejor = datos[i][4];
        combustible = i + 1;
    }
    }

    printf("\nEl mejor combustible es el %d, tiene una relacion de: %.2f (km/litro)", combustible, mejor);
    
    
}