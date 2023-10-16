#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct employee
{
    int n_l;
    char charge[20];
    float salary;
    int e_years;
};

int main()
{
    struct employee e[3];
    int flag = 1;
    int cont = 0;

    do
    {
        printf("\nMenú de opciones:\n");
        printf("1. Agregar un nuevo empleado\n");
        printf("2. Mostrar todos los empleados\n");
        printf("3. Buscar un empleado por legajo\n");
        printf("4. Actualizar sueldo\n");
        printf("5. Ordenar por sueldo\n");
        printf("6. Ordenar por antigüedad\n");
        printf("7. Salir\n");
        printf("Tu opción: ");
        flag = 0;
        int opcion = 0;
        scanf("%d", &opcion);

        // Limpiar el búfer después de leer el número entero.
        while (getchar() != '\n');

        switch (opcion)
        {
        case 1:
            printf("\nIngrese numero de legajo: ");
            scanf("%d", &e[cont].n_l);

            printf("\nIngrese cargo del empleado: ");
            scanf("%19s", e[cont].charge);

            printf("\nIngrese salario: ");
            scanf("%f", &e[cont].salary);

            printf("\nIngrese antigüedad: ");
            scanf("%d", &e[cont].e_years);

            printf("\nEmpleado agregado exitosamente...");
            cont++;
            flag = 1;
            break;

        case 2:
            if (cont > 0)
            {
                for (int i = 0; i < cont; i++)
                {
                    printf("\nNumero de legajo: %d", e[i].n_l);
                    printf("\nCargo: %s", e[i].charge);
                    printf("\nSalario: %.2f", e[i].salary);
                    printf("\nAntigüedad: %d\n", e[i].e_years);
                }
            }
            else
            {
                printf("\nNo hay empleados cargados");
            }
            flag = 1;
            break;

        case 3:
            if (cont > 0)
            {
                printf("\nIngresar numero de legajo a buscar: ");
                int search = 0;
                scanf("%d", &search);

                for (int i = 0; i < cont; i++)
                {
                    if (e[i].n_l == search)
                    {
                        printf("\nNumero de legajo: %d", e[i].n_l);
                        printf("\nCargo: %s", e[i].charge);
                        printf("\nSalario: %.2f", e[i].salary);
                        printf("\nAntigüedad: %d\n", e[i].e_years);
                    }
                }
            }
            else
            {
                printf("\nNo hay empleados cargados");
            }
            flag = 1;
            break;

        case 4:
            if (cont > 0)
            {
                printf("\nIngresar numero de legajo a buscar: ");
                int search = 0;
                scanf("%d", &search);

                for (int i = 0; i < cont; i++)
                {
                    if (e[i].n_l == search)
                    {
                        printf("\nIngrese nuevo salario: ");
                        float new_salary = 0;
                        scanf("%f", &new_salary);
                        e[i].salary = new_salary;
                        printf("\nSalario actualizado exitosamente");
                    }
                }
            }
            else
            {
                printf("\nNo hay empleados cargados");
            }
            flag = 1;
            break;

        case 5:
            float temp = 0;
            float swap = 0;
            for (int i = 0; i < cont - 1; i++) // Asegúrate de no exceder el límite del arreglo
            {
                if (e[i + 1].salary > e[i].salary)
                {
                    temp = e[i].salary;
                    e[i].salary = e[i + 1].salary;
                    e[i + 1].salary = temp;
                    swap++;
                }
            }
            if (swap > 0)
            {
                printf("\nSe han actualizado los salarios de mayor a menor: ");
            }
            else
            {
                printf("\nNo hubo modificaciones en el orden de los salarios");
            }
            for (int i = 0; i < cont; i++)
            {
                printf("\nNumero de legajo: %d", e[i].n_l);
                printf("\nSalario: %.2f", e[i].salary);
            }
            flag = 1;
            break;

        case 6:
            float temp1 = 0;
            float swap1 = 0;
            for (int i = 0; i < cont - 1; i++) // Asegúrate de no exceder el límite del arreglo
            {
                if (e[i].e_years > e[i+1].e_years)
                {
                    temp1 = e[i].salary;
                    e[i].salary = e[i + 1].salary;
                    e[i + 1].salary = temp1;
                    swap1++;
                }
            }
            if (swap1 > 0)
            {
                printf("\nSe han actualizado el orden por antiguedad: ");
            }
            else
            {
                printf("\nNo hubo modificaciones en el orden de antiguedad");
            }
            for (int i = 0; i < cont; i++)
            {
                printf("\nNumero de legajo: %d", e[i].n_l);
                printf("\nAntiguedad: %d", e[i].e_years);
            }
            flag = 1;
            break;

        case 7:
            exit(1);
            break;

        default:
            printf("\nCaracter ingresado no valido");
            flag = 1;
        }
    } while (flag == 1);

    return 0;
}
