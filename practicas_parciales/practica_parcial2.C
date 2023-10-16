
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void add(struct student **si, int *pc_e);
void save(struct student **si, int *pc_e);
void search(struct student **si, int *pc_e);

struct student
{
    int id = 0;
    char name[25];
    float grades[20];
    float prom = 0;
};

int main()
{
    int c_e = 0;
    int *pc_e = &c_e;
    struct student *si;
    int flag = 1;

    do
    {
        printf("\nMenu: ");
        printf("\n1. Registrar un nuevo estudiante");
        printf("\n2. Buscar y motrar los datos de un estudiante por id");
        printf("\n3. Salir");
        printf("\nTu opcion: ");
        flag = 0;
        int opcion = 0;
        scanf("%d", &opcion);

        switch (opcion)
        {

        case 1:
            add(&si, pc_e);
            save(&si, pc_e);
            flag = 1;
            break;

        case 2:
            search(&si, pc_e);
            flag = 1;
            break;

        case 3:
            printf("\nSaliendo...\n");
            exit(1);
            break;
        
        default:
            printf("\nCaracter ingresado no valido");
            flag = 1;
            break;
        }



    } while (flag == 1);
    
    free(si);
    return 0;
}

void add(struct student **si, int *pc_e)
{
    printf("\nIngrese la cantidad de estudiantes a registrar: ");
    scanf("%d", &*pc_e);

    *si = (struct student *) malloc (*pc_e * sizeof (struct student));

    for (int i = 0; i < *pc_e;i++)
    {
        printf("\nIngrese nombre del estudiante: ");
        scanf("%s", (*si)[i].name);
        printf("\nIngrese id del estudiante: ");
        scanf("%d", &(*si)[i].id);

        float cont_g = 0, total = 0;

        for (int j = 0; j < 3; j++)
        {
            printf("\nIngrese nota del estudiante: ");
            float grade = 0;
            scanf("%f", &grade);
            (*si)[i].grades[j] = grade;
            cont_g++;
            total+= grade;
            
        }

        (*si)[i].prom = total/cont_g;
    }
}

void save(struct student **si, int *pc_e)
{
    FILE *archivo = fopen("/home/joaquin/Escritorio/IUA/Informática/programas_C/practicas_parciales/p2.txt", "w");

    if (archivo == NULL)
    {
        printf("\nError al abrir archivo");
        exit(1);
    } else
    {
        printf("\nArchivo abierto exitosamente para escritura\n");
    }

    for (int i = 0; i < *pc_e; i++)
    {
        fprintf(archivo, "%d, %s, %.2f, %.2f, %.2f, %.2f\n",(*si)[i].id,(*si)[i].name, (*si)[i].grades[0], (*si)[i].grades[1], (*si)[i].grades[2], (*si)[i].prom);
    }
    
    fclose(archivo);
    printf("\nDatos escritos en el archivo exitosamente");
}

void search(struct student **si, int *pc_e)
{
    printf("\nIngrese id a buscar: ");
    int s = 0;
    scanf("%d", &s);

    for (int i = 0; i < *pc_e; i++)
    {
        if ((*si)[i].id == s)
        {
            printf("\nEstudiante %d encontrado: ", (*si)[i].id);
            printf("\nNombre: %s", (*si)[i].name);
            printf("\nNotas: ");
            for (int j = 0; j < 3; j++)
            {
                printf(" %.2f ",(*si)[i].grades[j]);
            }
            printf("\nPromedio: %.2f", (*si)[i].prom);
            
        } else
        {
            printf("\nNo se han encontrado estudiantes con el id ingresado");
        }
        
    }
}