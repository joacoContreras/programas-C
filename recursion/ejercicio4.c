#include <stdlib.h>
#include <stdio.h>

int calcular(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }

    return a + calcular(a, b-1);
}



int main()
{
    int num1 = 0, num2 = 0, flag = 0;
    
    printf("\nIngrese dos numeros para obtener producto");
    printf("\nNumero 1: ");        
    scanf("%d", &num1);
    printf("Numero 2: ");        
    scanf("%d", &num2);

    int resultado = calcular(num1,num2);
    printf("%d * %d = %d\n", num1, num2,resultado);

    return 0;
}