#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define COL 4
#define FIL 10

void generar_inscripciones(int inscripciones[FIL][COL]);
void verificar_cupo(int inscripciones[FIL][COL]);
void menu(int inscripciones[FIL][COL]);

int main() {
    int inscripciones[FIL][COL];

    generar_inscripciones(inscripciones);
    verificar_cupo(inscripciones);
    menu(inscripciones);

    return 0;
}

void menu(int inscripciones[FIL][COL]) {
    char opcion = 0;

    printf("\nIngresa la operación a realizar: ");
    scanf(" %c", &opcion);

    printf("\na --> Mostrar todas las inscripciones por nivel\nb --> Mostrar cantidad de alumnos por nivel\nc --> Calcular recaudación total de la academia\nx --> Salir\n");

    if (opcion == 'a') {
        for (int i = 0; i < FIL; i++) {
            printf("N. Inscripción: %d | Nivel del curso: %d | Promoción: %d | Monto Total: %d\n",
                   inscripciones[i][0], inscripciones[i][1], inscripciones[i][2], inscripciones[i][3]);
        }

        char repite[3];
        printf("\n¿Desea volver al menú? (si/no): ");
        scanf("%s", repite);
        if (strcmp(repite, "si") == 0) {
            menu(inscripciones);
        } else {
            exit(0);
        }

    } else if (opcion == 'b') {
        int cupo1 = 0, cupo2 = 0, cupo3 = 0;

        for (int i = 0; i < FIL; i++) {
            if (inscripciones[i][1] == 1) {
                cupo1++;
            } else if (inscripciones[i][1] == 2) {
                cupo2++;
            } else if (inscripciones[i][1] == 3) {
                cupo3++;
            }
        }

        printf("En el curso principiante hay %d alumnos\n", cupo1);
        printf("En el curso intermedio hay %d alumnos\n", cupo2);
        printf("En el curso avanzado hay %d alumnos\n", cupo3);

        char repite[3];
        printf("\n¿Desea volver al menú? (si/no): ");
        scanf("%s", repite);
        if (strcmp(repite, "si") == 0) {
            menu(inscripciones);
        } else {
            exit(0);
        }

    } else if (opcion == 'c') {
        int sumatoria = 0;

        for (int i = 0; i < FIL; i++) {
            if (inscripciones[i][1] != 0) {
                sumatoria += inscripciones[i][3];
            }
        }

        printf("\nLa recaudación total de la academia es de: %d\n", sumatoria);

    } else if (opcion == 'x') {
        exit(0);
    }

    char repite[3];
    printf("\n¿Desea volver al menú? (si/no): ");
    scanf("%s", repite);
    if (strcmp(repite, "si") == 0) {
        menu(inscripciones);
    } else {
        exit(0);
    }
}

void verificar_cupo(int inscripciones[FIL][COL]) {
    int cupo1 = 0, cupo2 = 0, cupo3 = 0;

    for (int i = 0; i < FIL; i++) {
        if (inscripciones[i][1] == 1) {
            if (cupo1 == 5) {
                inscripciones[i][1] = 0;
            } else {
                cupo1++;
            }
        } else if (inscripciones[i][1] == 2) {
            if (cupo2 == 5) {
                inscripciones[i][1] = 0;
            } else {
                cupo2++;
            }
        } else if (inscripciones[i][1] == 3) {
            if (cupo3 == 5) {
                inscripciones[i][1] = 0;
            } else {
                cupo3++;
            }
        }
    }
}

void generar_inscripciones(int inscripciones[FIL][COL]) {
    srand(time(NULL));

    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) {
            if (j == 0) {
                inscripciones[i][j] = i + 1;
            } else if (j == 1) {
                int numero = rand() % 3;
                inscripciones[i][j] = numero + 1;
            } else if (j == 2) {
                int numero = rand() % 2;
                inscripciones[i][j] = numero;
            } else if (j == 3) {
                int sumatoria = 0;
                if (inscripciones[i][1] == 1) {
                    sumatoria += 3000;
                } else if (inscripciones[i][1] == 2) {
                    sumatoria += 4000;
                } else if (inscripciones[i][1] == 3) {
                    sumatoria += 5000;
                }

                if (inscripciones[i][2] == 1) {
                    int descuento = sumatoria * 10 / 100;
                    sumatoria -= descuento;
                }

                inscripciones[i][j] = sumatoria;
            }
        }
    }
}
