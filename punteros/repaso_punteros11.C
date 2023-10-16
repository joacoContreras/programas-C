#include <stdio.h>
#include <stdlib.h>

#define NUM 10

void menu(int vector[], int *puntero, int contador);

int main() {
    int vector[NUM];
    int *puntero;
    int contador = 0;

    puntero = vector;

    for (int i = 0; i < NUM; i++) {
        printf("\nIngrese numero: ");
        scanf("%d", &*(puntero + i));
        if (*(puntero + i) <= 0) {
            break;
        }
        contador++;
    }

    menu(vector, puntero, contador);

    return 0;
}

void menu(int vector[], int *puntero, int contador) {
    printf("\nmenu: ");
    printf("\na.Cantidad de saldos generados");
    printf("\nb.Promedio de Saldos");
    printf("\nc.Cantidad de saldos menores al promedio");
    printf("\nd.Cantidad de saldos mayores al promedio");
    printf("\ne.Calcular cuanto fue lo recaudado en el mes");
    printf("\nx.Salir");
    printf("\nTu opcion: ");
    
    char opcion = '0';
    scanf(" %c", &opcion);

    int sumatoria = 0;
    float promedio = 0;

    for (int i = 0; i < contador; i++) {
        sumatoria += *(puntero + i);
    }

    if (contador > 0) {
        promedio = (float)sumatoria / contador;
    }

    switch (opcion) {
        case 'a':
            printf("\nLa cantidad de saldos generados fue de: %d", contador);
            break;

        case 'b':
            printf("\nPromedio de saldos: %.2f", promedio);
            break;

        case 'c':
            int contMenores = 0;
            for (int i = 0; i < contador; i++) {
                if (*(puntero + i) < promedio) {
                    contMenores++;
                }
            }
            printf("\nHay %d saldos menores al promedio", contMenores);
            printf("\n");
            break;
    
        case 'd':
            int contMayores = 0;
            for (int i = 0; i < contador; i++) {
                if (*(puntero + i) > promedio) {
                    contMayores++;
                }
            }
            printf("\nHay %d saldos mayores al promedio", contMayores);
            break;

        case 'e':
            printf("\nTotal de saldos recaudados: %d", sumatoria);
            break;

        case 'x':
            exit(0);
            break;

        default:
            printf("\nCaracter ingresado invalido, volviendo al menu...");
            break;
    }

    if (opcion != 'x') {
        printf("\n");
        menu(vector, puntero, contador);
    }
}
