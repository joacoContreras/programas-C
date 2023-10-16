#include <stdlib.h>
#include <stdio.h>

#define FIL 50
#define COL 1

void rellenar(float tramos[FIL][COL]);
void imprimir(float tramos[FIL][COL]);

int main()
{
    float tramos[FIL][COL];

    printf("Programa para calcular duracion de un viaje por tramos\n");
    printf("El programa deja de pedir tiempos de viaje cuando se ingresa un 0.\n");

    rellenar(tramos);
    imprimir(tramos);

    return 0;
}

void rellenar(float tramos[FIL][COL])
{
    int flag = 1;

    while (flag == 1)
    {
        for (int i = 0; i < FIL && flag == 1; i++)
        {
            printf("\nIngrese duracion tramo %d en minutos: ", i + 1);
            scanf("%f", &tramos[i][0]);

            if (tramos[i][0] == 0)
            {
                flag = 0;
            }
        }
    }
}

void imprimir(float tramos[FIL][COL])
{
    float t_total = 0, minutos, horas = 0;

    for (int i = 0; i < FIL; i++)
    {
        if (tramos[i][0] != 0)
        {
            t_total += tramos[i][0];
        }
        else
        {
            break;
        }
    }

    int t_total_entero = (int)t_total; // Convertir a entero

    if (t_total_entero >= 60)
    {
        horas = t_total_entero / 60;
        minutos = t_total_entero % 60;
        printf("\nEl tiempo total del viaje fue de %.0f:%02.0f horas", horas, minutos);
    }
    else
    {
        minutos = t_total_entero;
        printf("\nEl tiempo total del viaje fue de %.2f minutos", minutos);
    }
}