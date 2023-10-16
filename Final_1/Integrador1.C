#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define COL 50
#define FIL 40

void cargar(char nombres[FIL][COL], int * p, int puntos[FIL][2], int *cont_aux);
void ordenar_jugadores(char nombres[FIL][COL], int * p, int puntos[FIL][2]);
void ordenar_puntos(char nombres[FIL][COL], int * p, int puntos[FIL][2]);
void llamar(char nombres[FIL][COL], int * p, int puntos[FIL][2]);
void fin(char nombres[FIL][COL], int puntos[FIL][2], int *cont_aux);

int main()
{
    char nombres[FIL][COL];
    int participantes = 0;
    int puntos[FIL][2];
    memset(puntos, 0, sizeof(puntos));

    int *cant_participantes = &participantes;
    int participantes_total = 0;
    int *cont_aux = &participantes_total;

    cargar(nombres, cant_participantes, puntos, cont_aux);

    ordenar_jugadores(nombres, cant_participantes, puntos);

    llamar(nombres, cant_participantes, puntos);
    
    fin(nombres, puntos, cont_aux);

    return 0;
}

void cargar(char nombres[FIL][COL], int * cant_participantes, int puntos[FIL][2], int *cont_aux)
{
    for (int i = 0; i < FIL; i++)
    {
        printf("\nIngrese nombre de participante (fin para terminar): ");
        scanf("%s", nombres[i]);
        puntos[i][0] = i;
        (*cant_participantes)++;

        if (strcmp(nombres[i], "fin") == 0 && *cant_participantes % 2 != 0)
        {
            (*cant_participantes)--;
            break;

        } else if (strcmp(nombres[i], "fin") == 0 && *cant_participantes % 2 == 0)
        {
            printf("\nSe necesita un participante mas");
            printf("\nIngrese nombre de participante (fin para terminar): ");
            scanf("%s", nombres[i]);
            puntos[i][0] = i;
        
            break;
        }
        
        
    }
    *cont_aux = *cant_participantes;
}

void ordenar_jugadores(char nombres[FIL][COL], int * cant_participantes, int puntos[FIL][2])
{
    char aux[COL];
    int aux_puntos = 0;
    for (int i = 0; i < *cant_participantes; i++)
    {
        for (int j = 0; j < (*cant_participantes - 1); j++)
        {
            if (strcmp(nombres[j], nombres[j+1]) > 0)
            {
                strcpy(aux, nombres[j]);
                aux_puntos = puntos[j][0];

                strcpy(nombres[j], nombres[j+1]);
                puntos[j][0] = puntos[j+1][0];

                strcpy(nombres[j+1], aux);
                puntos[j+1][0] = aux_puntos;
            }   
        }   
    }
}

void llamar(char nombres[FIL][COL], int * cant_participantes, int puntos[FIL][2])
{
    int aux, ronda = 0, contador = 0;

    ronda = (*cant_participantes / 2) + 1;

    do
    {
        for (int i = 0; i < ronda; i = i + 2)
        {
            contador++;
            printf("\nRonda %d", contador);
            printf("\njugador 1: %s", nombres[i]);
            printf("\njugador 2: %s", nombres[i+1]);
            printf("\nIntroduce ganador(1 o 2): ");
            scanf("%d", &aux);

            if (aux == 1)
            {
                puntos[i][1]++; 
            } else if (aux ==2)
            {
                puntos[i+1][1]++; 
            }
        
        }

    ordenar_puntos(nombres, cant_participantes, puntos);
    ronda /= 2;

    } while (ronda > 0);
    
}

void ordenar_puntos(char nombres[FIL][COL], int *cant_participantes, int puntos[FIL][2])
{
    char aux[COL];
    int aux_puntos = 0;
    for (int i = 0; i < *cant_participantes; i++)
    {
        for (int j = 0; j < (*cant_participantes); j++)
        {
            if (puntos[j][1] < puntos[j+1][1])
            {
                
                strcpy(aux, nombres[j]);
                aux_puntos = puntos[j][1];

                strcpy(nombres[j], nombres[j+1]);
                puntos[j][1] = puntos[j+1][1];

                strcpy(nombres[j+1], aux);
                puntos[j+1][1] = aux_puntos;
            }   
        }   
    }
}

void fin(char nombres[FIL][COL], int puntos[FIL][2], int *cont_aux)
{
    char aux[COL];
    int aux_puntos = 0;

    for (int i = *cont_aux - 1; i > 0; i--)
    {
        for (int j = 0; j < *cont_aux - 1; j++)
        {
            if (puntos[j][1] < puntos[j+1][1])
            {
                aux_puntos = puntos[j][1];
                puntos[j][1] = puntos[j+1][1];
                puntos[j+1][1] = aux_puntos;

                strcpy(aux, nombres[j]);
                strcpy(nombres[j], nombres[j+1]);
                strcpy(nombres[j+1], aux);
            }
        }
    }

    printf("\nEl ganador del torneo es: %s | Puntaje: %d", nombres[0], puntos[0][1]);

    for (int i = *cont_aux - 1; i > 0; i--)
    {
        for (int j = 0; j < *cont_aux - 1; j++)
        {
            if (puntos[j][1] > puntos[j+1][1])
            {
                aux_puntos = puntos[j][1];
                puntos[j][1] = puntos[j+1][1];
                puntos[j+1][1] = aux_puntos;

                strcpy(aux, nombres[j]);
                strcpy(nombres[j], nombres[j+1]);
                strcpy(nombres[j+1], aux);
            }
        }
    }

    for (int i = 0; i < *cont_aux -1; i++)
    {
        if (strcmp(nombres[i], "fin") != 0)
        {
            printf("\nParticipante: %s | Puntaje: %d", nombres[i], puntos[i][1]);
        }
    }
}
