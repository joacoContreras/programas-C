#include <stdio.h>

/*
El algoritmo de Euclides es un método para calcular el Máximo Común Divisor (MCD) de dos números enteros de manera eficiente. Se basa en el principio de que el MCD de dos números no cambia si restamos el número menor del número mayor. El proceso se repite hasta que uno de los números sea igual a cero, en cuyo caso el otro número será el MCD.
*/

int calcularMCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return calcularMCD(b, a % b);
    }
}

int main() {
    int num1, num2;

    printf("Ingrese dos números para calcular el MCD:\n");
    printf("Número 1: ");
    scanf("%d", &num1);
    printf("Número 2: ");
    scanf("%d", &num2);

    int mayor = num1,  menor = num2, temp = 0;
    if (mayor < menor)
    {
        temp = menor;
        menor = mayor;
        mayor = temp;
    }
    
    int resultado = calcularMCD(mayor, menor);

    printf("El Máximo Común Divisor (MCD) de %d y %d es: %d\n", num1, num2, resultado);

    return 0;
}
