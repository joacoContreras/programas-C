#include <stdio.h>
#include <stdlib.h>

void menu();
float suma(float * a, float * b);
float resta(float * a, float * b);
float multiplicacion(float * a, float * b);
float division(float * a, float * b);

int main(void) {

    menu();
 
    


    return 0;
}

void menu()
{
    float num1 = 0, num2 = 0;
    char opcion = '0';

    printf("\nSimulacion de calculadora\n");

    printf("\nIngrese primer numero: ");
    scanf("%f", &num1);
    printf("\nIngrese segundo numero: ");
    scanf("%f", &num2);

    printf("\nMenu: Seleccione operacion a realizar: ");
    printf("\na--> Suma\nb--> Resta\nc--> Multplicacion\nd--> Division\nx--> Salir\n");

    printf("\nopcion: ");
    scanf(" %c", &opcion);


    
    switch (opcion)
    {
    case 'a':
        suma(&num1, &num2);
        break;

     case 'b':
        resta(&num1, &num2);
        break;


     case 'c':
        multiplicacion(&num1, &num2);
        break;

    case 'd':
    
        if(num2 == 0)
        {
            printf("\nNo se puede dividir por cero");
            menu();
        }
         else
        {
            division(&num1, &num2);

        }
        
        break;

     case 'x':
        exit(0);



    default:
    printf("\nCaracter ingresado no valido");
    menu();
        break;
    }
}

float suma(float * a, float * b)
{
    char repetir = 0;
    float z = 0;
    z = *a + *b;

    printf("El resultado de la suma es: %f", z);
    
    printf("\nDesea hacer otra operacion? (s/n)\n");
    scanf(" %c", &repetir);
    if(repetir == 's')
    {
        
        menu();

    } else
    {
        exit(0);
    }
    return(0);
}

float resta(float * a, float * b)
{
    char repetir = 0;
    float z = 0;
    z = *a - *b;

    printf("El resultado de la resta es: %f", z);
    
    printf("\nDesea hacer otra operacion? (s/n)\n");
    scanf(" %c", &repetir);
    if(repetir == 's')
    {
        menu();

    } else
    {
        exit(0);
    }
    return(0);
}

float multiplicacion(float * a, float * b)
{
    float z = 0;
    char repetir = 0;
    z = *a * *b;

    printf("El resultado de la multiplicacion es: %f", z);
    
    printf("\nDesea hacer otra operacion? (s/n)\n");
    scanf(" %c", &repetir);

    if(repetir == 's')
    {
        menu();

    } else
    {
        exit(0);
    }
  
    return(0);
}

float division(float * a, float * b)
{
    char repetir = 0;
    float z = 0;
    z = *a / *b;

    printf("El resultado de la multiplicacion es: %0.2f", z);
    
    printf("\nDesea hacer otra operacion? (s/n)\n");
    scanf(" %c", &repetir);
    if(repetir == 's')
    {
        menu();

    } else
    {
        exit(0);
    }
    return(0);
}