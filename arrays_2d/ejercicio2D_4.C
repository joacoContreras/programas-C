#include <stdlib.h>
#include <stdio.h>
#include <ctime>

#define NUM 5

void fill(int array[][NUM], int num);
char menu(int array[][NUM], int num);
void imprimir(int array[][NUM], int num);
void promedio(int array[][NUM], int num);
void buscar(int array[][NUM], int num);
void pares(int array[][NUM], int num);
void sumar_impares(int array[][NUM], int num);
void nuevo_array(int array[][NUM], int num);

int main ()
{
     // Establecer la semilla utilizando la función time
    srand(time(NULL));

 

    int array[NUM][NUM];

    fill(array, NUM);
    menu(array, NUM);

   


    return 0;
}

void fill(int array[][NUM], int num)
{
   
    for (int i = 0; i < num ; i++) {
       
       for (int j = 0; j < num; j++)
       {

            int numeroAleatorio = rand() % 25 + 1;
            array[i][j] =  numeroAleatorio;
       }    
    }
}

char menu(int array[][NUM], int num)
{
    
    char opcion;
    printf("\na--> Imprimir\nb--> Promedio de todos los valores del array\nc--> Buscar repeticion de un numero\nd--> Imprimir valores pares\ne--> Sumar valores impares\nf--> Crear un arreglo de 25x2 e inicializar a cero (0), para guardar la frecuencia con que aparece un número en el arreglo 5x5. Luego mostrar la lista de frecuencia de los números\nx--> Salir\n");

    scanf(" %c", &opcion);
    
    
    if (opcion == 'a')
    {
        imprimir(array, NUM);
    }

    if (opcion == 'b')
    {
        promedio(array, NUM);
    }

    if (opcion == 'c')
    {
        buscar(array, NUM);
    }

    if (opcion == 'e')
    {
        sumar_impares(array, NUM);
    }

    if (opcion == 'd')
    {
        pares(array, NUM);
    }

    if (opcion == 'f')
    {
        nuevo_array(array, NUM);
    }

    if (opcion == 'x')
    {
        printf("\nSaliendo...");
        exit(0);
    }
    
}

void imprimir(int array[][NUM], int num)
{
    
    
        for (int i = 0; i < num ; i++) 
        {
       
            for (int j = 0; j < num; j++)
            {

                printf("\n%d", array[i][j]);
            }    
        }
    
    menu(array, NUM);
}

void promedio(int array[][NUM], int num)
{
    int sumatoria = 0;

     for (int i = 0; i < num ; i++) 
        {
       
            for (int j = 0; j < num; j++)
            {

                sumatoria += array[i][j];
            }    
        }
    
    printf("\nEl promedio total de los numeros en el array es: %d", sumatoria/25);
    menu(array, NUM);

}

void buscar(int array[][NUM], int num)
{
    int contador = 0;
    int numero = 0;

    printf("\nIngrese un numero del 1 al 25 para buscarlo en el arreglo: ");
    scanf("%d", &numero);

    for (int i = 0; i < num ; i++) 
        {
       
            for (int j = 0; j < num; j++)
            {

                if (numero == array[i][j])
                {
                    contador++;
                }
                
            }    
        }
    
    printf("\nEl numero %d se encontro un total de: %d veces", numero, contador);
    menu(array, NUM);
}

void pares(int array[][NUM], int num)
{
     for (int i = 0; i < num ; i++) 
        {
       
            for (int j = 0; j < num; j++)
            {
                if (array[i][j] % 2 == 0)
                {
                    printf("\n%d", array[i][j]);
                }

                
            }    
        }
    
    menu(array, NUM);

}

void sumar_impares(int array[][NUM], int num)
{
    int sumatoria = 0;
     for (int i = 0; i < num ; i++) 
        {
       
            for (int j = 0; j < num; j++)
            {
                if (array[i][j] % 2 != 0)
                {
                    sumatoria += array[i][j];
                }

                
            }    
        }
    
    printf("\nLa sumatoria total de los numeros impares es: %d", sumatoria);
    menu(array, NUM);

}

void nuevo_array(int array[][NUM], int num)
{
    int new_array[25][2];

    for (int i = 0; i < 25; i++)
    {
        new_array[i][0] = i;
        new_array[i][1] = 0;

        for (int j = 0; j < num; j++)
        {
            for (int k = 0; k < num; k++)
            {
                if (array[j][k] == new_array[i][0])
                {
                    new_array[i][1]++;
                }
            }
        }
    }

    printf("\nNumero | Frecuencia");
    for (int i = 0; i < 25; i++)
    {
        printf("\n%d      | %d", new_array[i][0], new_array[i][1]);
    }
    
    menu(array, NUM);



}
