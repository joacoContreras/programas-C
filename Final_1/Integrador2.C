/*
Se pide hacer un programa que permita computar los resultados de la prueba olímpica de gimnasia en anillas. Cada uno de los atletas realiza su ejercicio y luego es puntuado por un jurado de cinco miembros. El operador ingresa el nombre del atleta, el país al que representa y la nota de los cinco jueces. Para obtener la nota final se descarta el valor más alto y el más bajo del jurado y se promedian los restantes tres. 

Al finalizar la competencia (se ingresa un atleta llamado “eof”), se imprimen los resultados de los participantes que van al podio, indicando quien ganó la medalla de oro, de plata o de bronce. No se conoce la cantidad de atletas a priori.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FIL 100
#define COL 20

void cargar(char nombres[FIL][COL], char paises[FIL][COL], float notas[FIL][COL], int * p);
void promedio(char nombres[FIL][COL], char paises[FIL][COL], float notas[FIL][COL], int * p);
void ordenar(char nombres[FIL][COL], char paises[FIL][COL], float notas[FIL][COL], int * p);
int main()
{
    char nombres[FIL][COL];
    char paises[FIL][COL];
    float notas[FIL][COL];

    int cant_participantes = 0;
    int * p = &cant_participantes;

    printf("\nProgama de competencia atletica");

    cargar(nombres, paises, notas, p);
    promedio(nombres, paises, notas, p);
    ordenar(nombres, paises, notas, p);

    printf("\nPodio de la competencia: ");

    if (*p >=3)
    {
        for (int i = 0; i < 3 ; i++)
    {
        printf("\nPuesto %dº: %s | Puntaje: %.2f | Pais: %s",i+1, nombres[i], notas[i][1], paises[i]);
    }
    } else
        {
            for (int i = 0; i < *p ; i++)
            {
                printf("\nPuesto %d: %s | Puntaje: %.2f | Pais: %s",i+1, nombres[i], notas[i][1], paises[i]);
            }
        }
    

    return 0;
}

void cargar(char nombres[FIL][COL], char paises[FIL][COL], float notas[FIL][COL], int * p)
{
    
    printf("\nIngresa eof en nombre, para finalizar la carga de concursantes");
    for (int i = 0; i < FIL; i++)
    {
        printf("\nIngresar nombre del atleta: ");
        scanf("%s", nombres[i]);
        (*p)++;

        if (stricmp(nombres[i], "eof") == 0)
        {
            (*p)--;
            break;
        }
        

        printf("\nIngresar pais del atleta: ");
        scanf("%s", paises[i]);

        for (int j = 2; j < 7; j++)
        {
            printf("\nIngresar nota %d: ", j-1);
            scanf("%f", &notas[i][j]);
        }
    }
    
}

void promedio(char nombres[FIL][COL], char paises[FIL][COL], float notas[FIL][COL], int * p)
{
    float sumatoria = 0, min = 100, max = 0;   
    for (int i = 0; i < *p; i++)
    {
        sumatoria = 0, min =100, max = 0;

        for (int j = 2; j < 7; j++)
        {
            if (notas[i][j] < min)
            {
                min = notas[i][j];

            } else if (notas[i][j] > max)
            {
                
            }
            
            sumatoria += notas[i][j];
        }
        sumatoria += min;
        sumatoria -=  max;
        notas[i][1] = sumatoria / 3;
        
    }
    

}

void ordenar(char nombres[FIL][COL], char paises[FIL][COL], float notas[FIL][COL], int * p)
{
    float aux;
    char aux_nombres[COL], aux_paises[COL];

    for (int i = 0; i < (*p -1); i++)
    {
        for (int j = 0; j < *p; j++)
        {
            if (notas[j][1] < notas[j+1][1])
            {
                aux = notas[j][1];
                strcpy(aux_nombres, nombres[j]);
                strcpy(aux_paises, paises[j]);

                notas[j][1] = notas[j+1][1];
                strcpy(nombres[j], nombres[j+1]);
                strcpy(paises[j], paises[j+1]);

                notas[j+1][1] = aux;
                strcpy(nombres[j+1], aux_nombres);
                strcpy(paises[j+1], aux_paises);
                
            }   
        }   
    }
}