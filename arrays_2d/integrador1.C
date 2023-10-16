/*1) Se desea hacer un programa que gestione un torneo entre no más de 40 participantes de un juego que se define de a dos jugadores en una ronda individual (por ejemplo, piedra, papel o tijera o Mortal Kombat).

Para ello, primero se ingresan los nombres de los jugadores en cualquier orden, terminando la carga con un nombre de jugador llamado “fin” (por supuesto, este jugador no se carga).

Luego, el programa ordena los nombres alfabéticamente y comienza a llamar a los jugadores de a pares. Éstos definen quién es el ganador y lo ingresan al programa. El llamado se repite hasta que todos los jugadores se han llamado, dándose por finalizada la ronda. A continuación, se repite la misma operatoria hasta que se determina un único ganador.

Finalmente, el programa indica quién es el ganador y de forma separada el resto de los jugadores por puntaje en orden decreciente (se considera un punto por partido ganado y cero puntos por partido perdido).*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define FIL 40
#define COL 20

int cargar(char planilla[FIL][COL]);
void ordenar(char planilla[FIL][COL], int filas);
void print(char planilla[FIL][COL], int filas);

int main()
{
    int filas = 0;
    char planilla[FIL][COL];   
    printf("\nPrograma para organizar torneo");
    printf("\nIngrese FIN o fin para detener la carga de los nombres de los participantes");

    filas = cargar(planilla);
    print(planilla, filas);
    ordenar(planilla, filas);

    return 0;
}

void print(char planilla[FIL][COL], int filas)
{
    for (int i = 0; i < filas; i++)
    {
        printf("\n%s", planilla[i]);
    }
    
}

int cargar(char planilla[FIL][COL])
{ 
    int cant_p = 0;

    for (int i = 0; i < cant_p; i++)
    {
        printf("\nIngrese nombre de participante: ");
        scanf(" %s", &planilla[i][COL]);

        if (strcmp(planilla[i], "fin") == 0 && strcmp(planilla[i], "FIN") == 0)
        {
            break;
        }  else
        {
            cant_p++;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    return cant_p;
}

void ordenar(char planilla[FIL][COL], int filas)
{
    char aux[COL];

    for (int i = 0; i < filas; i++)
    {
        if (strcmp(planilla[i], planilla[i+1]) > 0)
        {
            strcpy(aux, planilla[i]);
            strcpy(planilla[i], planilla[i+1]);
            strcpy(planilla[i+1], aux);
        }     
    }
}