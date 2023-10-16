/*Se pide hacer un programa que permita computar los resultados de la prueba olímpica de gimnasia en anillas. Cada uno de los atletas realiza su ejercicio y luego es puntuado por un jurado de cinco miembros. El operador ingresa el nombre del atleta, el país al que representa y la nota de los cinco jueces. Para obtener la nota final se descarta el valor más alto y el más bajo del jurado y se promedian los restantes tres. 

Al finalizar la competencia (se ingresa un atleta llamado “eof”), se imprimen los resultados de los participantes que van al podio, indicando quien ganó la medalla de oro, de plata o de bronce. No se conoce la cantidad de atletas a priori.*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define FIL 50
#define COL 30

void carga(char lista_prev[FIL][COL], int puntaje[FIL][5], int cont_players = 0);

int main()
{
    char lista_prev[FIL][COL];

    int puntaje[FIL][5];
    int cont_players = 0;

    carga(lista_prev, puntaje, cont_players);




    return 0;
}

void carga(char lista_prev[FIL][COL], int puntaje[FIL][5], int cont_players = 0)
{
    int sumatoria = 0;
    for (int i = 0; i < FIL; i++)
    {
        printf("\nIngrese nombre de atleta: ");
        scanf(" %s", &lista_prev[i][COL]);

        if (lista_prev[i][COL] == 'eof')
        {
            break;
        }
        cont_players++;

        printf("\nIngrese pais que representa: ");
        scanf(" %s", &lista_prev[i+1][COL]);

        for (int j = 0; j < 5; j++)
        {
            
            printf("\nIngrese puntaje: ");
            scanf("%d", &puntaje[i][j+1]);
            sumatoria += puntaje[i][j+1]; 
            
        }
        puntaje[i][1] = sumatoria;
        i++;
    }
}