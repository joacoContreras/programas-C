#include <stdio.h>
#include <stdbool.h>

// Función para verificar si un número es primo
bool esPrimo(int numero) {
    if (numero <= 1) {
        return false; // Los números menores o iguales a 1 no son primos
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false; // Si es divisible por algún número, no es primo
        }
    }
    return true; // Si no es divisible por ningún número, es primo
}

int main() {
    printf("Números primos del 1 al 100:\n");

    for (int i = 1; i <= 100; i++) {
        if (esPrimo(i)) {
            printf("%d", i);
            if (i < 100) {
                printf("-");
            }
        }
    }

    printf("\n");
    return 0;
}
