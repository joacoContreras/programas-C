#include <iostream>
#include <stdlib.h>	
#include <time.h>
#include <cstring>

#define MAX_GRADES 20
#define INT_MAX 100
int grades[MAX_GRADES];

void fill_array();
void menu();

int main(void)
{
    printf("\nPorgrama para cargar notas, en caso de que el alumno esté ausente se colocará como nota igual a cero)\n");

    fill_array ();

    menu();


    return 0;
}

//funcion para rellenar array
void fill_array () 
{
    memset(grades, 0, sizeof(grades)); // inicializar la matriz con ceros
    int i = 0, grade = 0;
    do
    {
       if (i >= MAX_GRADES) {
            printf("No puedes ingresar más de %d notas\n", MAX_GRADES);
            break;
       }

     printf("\nIngrese nota (o -1 para salir)\n ");
        scanf("%d", &grade);

        if (grade == 0) {
            grades[i] = -5;
            i++;
        }
        if (grade != -1) {
            grades[i] = grade;
            i++;
        }

    } while (grade != -1);

}   

void menu()
{
    int cant_ausentes = 0;
    int cant_notas = 0;  // Contador de notas ingresadas
   
    int prev = 0, menor = INT_MAX, mayor = 0, aprobados = 0, no_aprob = 0;
    char option;

    printf("\nMenu: \na--> Nota mayor y nota menor\nb--> Cantidad de notas ingresadas\nc--> Cantidad de aprobados, desaprobados y ausentes.\nx--> Salir\n");

    scanf(" %c", &option);

    switch (option)
    {
    case 'a':

       for (int i = 0; i <= MAX_GRADES; i++)
       {
            if(grades[i] > mayor)
            {
                mayor = grades[i];

            } else if (grades[i] != -5 && grades[i] < prev)
            {
                menor = grades[i];
                prev = grades[i];
            
            }

        prev = grades[i];
        
       }

        printf("\nLa nota menor fue: %d", menor);
        printf("\nLa nota mayor fue: %d", mayor);

        menu();
        break;

    case 'b':
    
    for ( int i = 0; i<= MAX_GRADES; i++)
    {
        if (grades[i] > 0)
        {
            cant_notas++;
        }
    }
     printf("\nLa cantidad de nota ingresadas es: %d", cant_notas);

        menu();
        break;

  case 'c':

   
  
    for (int i = 0; i <= MAX_GRADES; i++)  // Utilizar MAX_GRADES como límite
    {
        if (grades[i] > 5)
        {
            aprobados++;
        } 
        else if (grades[i] < 6 && grades[i] >= 1)
        {
            no_aprob++;
        } else if (grades[i] == -5)
        {
           cant_ausentes++;
        } 
    }

    

  

    printf("\nLa cantidad de ausentes es: %d", cant_ausentes);
    printf("\nLa cantidad de aprobados es: %d", aprobados);
    printf("\nLa cantidad de reprobados es: %d", no_aprob);

    menu();
    break;
    case 'x':

    exit(0);
    
    default:

        printf("\nCaracter ingresado no valido");
      
        break;
    }



}