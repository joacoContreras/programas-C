#include <stdio.h>
#include <string.h>

struct Cancion {
    char artista[20];
    char titulo[20];
    int duracion;
    int size;
};

int main() {
	int flag = 0;
    struct Cancion mi_cancion[3]; // Declaración de estructura para almacenar hasta 3 canciones
    int numCanciones = 0; // Contador de canciones

	flag = 1;
    do {
        printf("\nMenú de opciones:\n");
        printf("1. Agregar una nueva canción\n");
        printf("2. Mostrar todas las canciones\n");
        printf("3. Buscar una canción por título\n");
        printf("4. Salir\n");
        printf("Tu opción: ");
		flag = 0;
        int opcion;
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (numCanciones < 3) {
                    // Solicitar al usuario los datos de la nueva canción
                    printf("\nIngrese nombre del artista: ");
                    scanf(" %s", mi_cancion[numCanciones].artista);

                    printf("Ingrese nombre de la canción: ");
                    scanf(" %s", mi_cancion[numCanciones].titulo);

                    printf("Ingrese duración en segundos de la canción: ");
                    scanf("%d", &mi_cancion[numCanciones].duracion);

                    printf("Ingrese tamaño en kb de la canción: ");
                    scanf("%d", &mi_cancion[numCanciones].size);

                    numCanciones++; // Incrementar el contador de canciones
                    printf("Canción agregada con éxito.\n");
                } else {
                    printf("Ya has alcanzado el límite de canciones (3).\n");
                }
				flag = 1;
                break;

            case 2:
                if (numCanciones > 0) {
                    // Mostrar todas las canciones almacenadas
                    printf("\nListado de canciones:\n");
                    for (int i = 0; i < numCanciones; i++) {
                        printf("\nCanción %d:\n", i + 1);
                        printf("Artista: %s\n", mi_cancion[i].artista);
                        printf("Título: %s\n", mi_cancion[i].titulo);
                        printf("Duración: %d segundos\n", mi_cancion[i].duracion);
                        printf("Tamaño: %d KB\n", mi_cancion[i].size);
                    }
                } else {
                    printf("No hay canciones almacenadas.\n");
                }
				flag = 1;
                break;

            case 3:
                if (numCanciones > 0) {
                    // Buscar una canción por título
                    char tituloBuscado[20];
                    printf("\nIngrese el título de la canción a buscar: ");
                    scanf("%s", tituloBuscado);

                    int encontrada = 0;
                    for (int i = 0; i < numCanciones; i++) {
                        if (strcmp(mi_cancion[i].titulo, tituloBuscado) == 0) {
                            printf("Canción encontrada:\n");
                            printf("Artista: %s\n", mi_cancion[i].artista);
                            printf("Título: %s\n", mi_cancion[i].titulo);
                            printf("Duración: %d segundos\n", mi_cancion[i].duracion);
                            printf("Tamaño: %d KB\n", mi_cancion[i].size);
                            encontrada = 1;
                            break;
                        }
                    }

                    if (!encontrada) {
                        printf("Canción no encontrada.\n");
                    }
                } else {
                    printf("No hay canciones almacenadas.\n");
                }
				flag = 1;
                break;

            case 4:
                printf("Saliendo del programa.\n");
                return 0;

            default:
                printf("Opción inválida. Por favor, seleccione una opción válida.\n");
        }
    } while (flag == 1);

    return 0;
}
