#include <stdio.h>
#include <stdlib.h>



int main(void) {
    int *puntero_int, var_int = 0;
    float *puntero_float, var_float = 0.0;
    char *puntero_char, var_char = '0';
    double *puntero_double, var_double = 0.0;

    puntero_int = &var_int;
    puntero_char = &var_char;
    puntero_float = &var_float;
    puntero_double = &var_double;

    printf("El valor que almacena la variable int: %d\n", var_int);
    printf("El valor del puntero int: %d\n", *puntero_int);
    printf("La direccion de memoria de la variable int: %p\n", (void *)puntero_int);
    printf("El valor al que apunta el puntero int: %d\n", *puntero_int);

    printf("El valor que almacena la variable char: %c\n", var_char);
    printf("El valor del puntero char: %c\n", *puntero_char);
    printf("La direccion de memoria de la variable char: %p\n", (void *)puntero_char);
    printf("El valor al que apunta el puntero char: %c\n", *puntero_char);

    printf("El valor que almacena la variable float: %0.2f\n", var_float);
    printf("El valor del puntero float: %f\n", *puntero_float);
    printf("La direccion de memoria de la variable float: %p\n", (void *)puntero_float);
    printf("El valor al que apunta el puntero float: %f\n", *puntero_float);

    printf("El valor que almacena la variable double: %f\n", var_double);
    printf("El valor del puntero double: %f\n", *puntero_double);
    printf("La direccion de memoria de la variable double: %p\n", (void *)puntero_double);
    printf("El valor al que apunta el puntero double: %f\n", *puntero_double);

    return 0;
}
