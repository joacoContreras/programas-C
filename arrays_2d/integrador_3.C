#include <stdio.h>
#include <stdlib.h>
#define NUM 5

void cargar_array(float *mediciones, int num);
void promedio_ph(float *mediciones, int num, float ph_max);

int main()
{
    int signal = 0;
    float mediciones[NUM];
    float ph_max;
    printf("Programa para medir pH\n");

    printf("Ingrese el pH máximo: ");
    scanf("%f", &ph_max);

    do {
        cargar_array(mediciones, NUM);
        promedio_ph(mediciones, NUM, ph_max);
        signal = 1;
    } while (signal == 1);

    return 0;
}

void cargar_array(float *mediciones, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("Ingrese medición (0 para salir): ");
        scanf("%f", &mediciones[i]);

        if (mediciones[i] == 0)
        {
            exit(0);
        }
    }
}

void promedio_ph(float *mediciones, int num, float ph_max)
{
    float prom = 0;

    for (int i = 0; i < num; i++)
    {
        prom += mediciones[i];
    }

    prom = prom / num;

    if (prom > ph_max)
    {
        printf("\nAlarma, pH máximo superado");
        printf("\nPromedio: %.2f | pH máximo: %.2f\n", prom, ph_max);
        exit(0);
    }
    else
    {
        printf("\npH promedio OK");
        printf("\nPromedio: %.2f | pH máximo: %.2f\n", prom, ph_max);
    }
}
