#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct activity
{
    char name[20];
    int space = 0;
    int days = 0;
    float time = 0;
    int cant_i = 0;
};

void print_gym(struct activity *p);
void search(struct activity *p);
void f_space(struct activity *p);

int main ()
{
    srand(time(NULL));
    struct activity gym[20];

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            gym[i].name[j] = 'A' + (rand() % 26);
        }
        gym[i].name[19] = '\0';
        gym[i].space = rand() % 20;
        gym[i].days = rand() % 7;
        gym[i].time = rand() % 24;
        gym[i].cant_i = rand() % 20;
    }
    

    int flag = 1;
    do
    {
        printf("\nMenú de opciones:\n");
        printf("1. Mostrar planilla\n");
        printf("2. Buscar por nombre\n");
        printf("3. Buscar actividades libres\n");
        printf("4. Salir\n");
        printf("Tu opción: ");
        flag = 0;
        int opcion = 0;
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            print_gym(gym);
            flag=1;
            break;

        case 2:
            search(gym);
            flag=1;
            break;

        case 3:
            f_space(gym);
            flag=1;
            break;
        case 4:
            exit(1);
            break;    
        
        default:
            break;
        }
    } while (flag == 1);
    


    return 0;
}

void print_gym(struct activity *p)
{
    for (int i = 0; i < 20; i++)
    {
        printf("\nNombre: %s", p[i].name);
        printf("\nEspacio disponible: %d", p[i].space);
        printf("\nDias: %d", p[i].days);
        printf("\nHora: %.2f", p[i].time);
        printf("\nCantidad inscriptos %d", p[i].cant_i);
    }
    
}

void search(struct activity *p)
{
    int cont = 0;
    char lname[20];
    printf("\nIngrese el nombre de la actividad a buscar\n");
    scanf("%s", lname);

    for (int i = 0; i < 20; i++)
    {
        if (strcmp(lname, p[i].name) == 0)
        {
            printf("\nNombre: %s", p[i].name);
            printf("\nEspacio disponible: %d", p[i].space);
            printf("\nDias: %d", p[i].days);
            printf("\nHora: %.2f", p[i].time);
            printf("\nCantidad inscriptos %d", p[i].cant_i);
            cont++;
        }
    }
    if (cont == 0)
    {
        printf("\nNo se han encontrado actividades con ese nombre");
    }
    
}

void f_space(struct activity *p)
{
    printf("\nActividades con cupos: \n");
    for (int i = 0; i < 20; i++)
    {
        if (p[i].space < 19)
        {
            printf("\nNombre: %s", p[i].name);
            printf("\nEspacio disponible: %d\n", 20-p[i].space);
        }
        
    }
    
}