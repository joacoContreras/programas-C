#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define umbral 8
#define COL 2
#define FIL 100

void medir(float mediciones[FIL][COL]);

int main()
{
    float mediciones[FIL][COL];

    medir(mediciones);


    return 0;
}

void medir(float mediciones[FIL][COL])
{
    int sumatoria = 0;

    for (int i = 1; i < FIL; i++)
    {
        printf("\nIngrese medicion (0 para salir): ");
        scanf("%f", &mediciones[i][1]);

        if (mediciones[i][1] == 0)
        {
            break;
        }

        sumatoria += mediciones[i][1];

        if (i % 5 == 0)
        {
            sumatoria = sumatoria / 5;
            if (sumatoria >= umbral)
            {
                printf("\nAlarma Activada: el Ph a superado el umbral\n");
            } else 
            {
                printf("\nPromedio de Ph: Okey\n");
            }

            sumatoria = 0;
        }
    }
}