#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FIL 100
#define COL 20

void carga(int codigos[FIL][COL],char nombres[FIL][COL],unsigned int stock[FIL][COL], int * cant_producto);

void menu(int codigos[FIL][COL],char nombres[FIL][COL],unsigned int stock[FIL][COL], int * cant_producto);

void incrementar(int codigos[FIL][COL],char nombres[FIL][COL],unsigned int stock[FIL][COL], int * cant_producto);

void decrementar(int codigos[FIL][COL],char nombres[FIL][COL],unsigned int stock[FIL][COL], int * cant_producto);

void listado (int codigos[FIL][COL],char nombres[FIL][COL],unsigned int stock[FIL][COL], int * cant_producto);

void sin_stock(int codigos[FIL][COL], char nombres[FIL][COL], unsigned int stock[FIL][COL], int *cant_producto);

int main ()
{
    int codigos[FIL][COL], cant_productos = 0;
    char nombres[FIL][COL];
    unsigned int stock[FIL][COL];
    int * cant_producto = &cant_productos;

    carga(codigos, nombres, stock, cant_producto);
    menu(codigos, nombres, stock, cant_producto);

    return 0;
}

void carga(int codigos[FIL][COL],char nombres[FIL][COL],unsigned int stock[FIL][COL], int * cant_producto)
{

    printf("\nCarga de productos (Ingrese 0 en codigo del producto para salir)");

    for(int i = 0; i < FIL; i++)
    {
        printf("\nIngrese codigo del Producto: ");
        scanf(" %d", &codigos[i][0]);
        (*cant_producto)++;

        if (codigos[i][0] == 0)
        {
            (*cant_producto)--;
            break;
        }

        printf("\nIngrese nombre del Producto: ");
        scanf(" %s", nombres[codigos[i][0]]);    

        printf("\nIngrese stock del Producto: ");
        scanf(" %u", &stock[i][0]);
    }
}

void menu(int codigos[FIL][COL],char nombres[FIL][COL],unsigned int stock[FIL][COL], int * cant_producto)

{
    int opcion = 0;
    printf("\nIngrese la operacion a realizar");

    printf("\n(1) Permite incrementar la cantidad de productos existentes, indicando codigo del producto y cantidad");

    printf("\n(2) Permite decrementar la cantidad de productos existentes, indicando codigo del productoy cantidad");

    printf("\n(3) Imprime el listado completo de articulos ordenados por codigo de producto");

    printf("\n(4) Imprime el listado completo de articulos que NO hay en stock");

    printf("\n(5) Salir");

    printf("\nOpcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 5:
        printf("\nSaliendo...");
        exit(0);

        break;

    case 1:
        incrementar(codigos, nombres, stock, cant_producto);
        exit(0);

        break;

    case 2:
        decrementar(codigos, nombres, stock, cant_producto);
        exit(0);

        break;

    case 3:
        listado(codigos, nombres, stock, cant_producto);
        exit(0);

        break;

    case 4:
        sin_stock(codigos, nombres, stock, cant_producto);
        exit(0);

        break;

    default:

        printf("\nOpcion ingresada no valida");
        menu(codigos, nombres, stock, cant_producto);
    break;
    }
}

void incrementar(int codigos[FIL][COL],char nombres[FIL][COL],unsigned int stock[FIL][COL], int * cant_producto)
{
    int buscar = 0;

    printf("\nIngrese el codigo del producto a incrementar: ");
    scanf("%d", &buscar);

    for (int i = 0; i < *cant_producto; i++)
    {
        if (codigos[i][0] == buscar)
        {
            printf("\nProducto: %s | Stock: %d", nombres[buscar], stock[i][0]);
            printf("\nIngrese cantidad a sumar al stock existente: ");
            
            unsigned int suma;
            scanf("%u", &suma);

            stock[i][0] += suma;

            printf("\nLa operacion se ha realizado exitosamente\n");
            printf("\nProducto: %s | Stock: %d", nombres[buscar], stock[i][0]);

            menu(codigos, nombres, stock, cant_producto);
        } else
        {
            printf("\nNo se han encontrado el producto con el codigo ingresado\n");
            printf("\nVolviendo al menu...\n");
            menu(codigos, nombres, stock, cant_producto);
        }
    }

    menu(codigos, nombres, stock, cant_producto);
}

void decrementar(int codigos[FIL][COL],char nombres[FIL][COL],unsigned int stock[FIL][COL], int * cant_producto)
{
    int buscar = 0;

    printf("\nIngrese el codigo del producto a decrementar: ");
    scanf("%d", &buscar);

    for (int i = 0; i < *cant_producto; i++)
    {
        if (codigos[i][0] == buscar)
        {
            printf("\nProducto: %s | Stock: %d", nombres[buscar], stock[i][0]);
            printf("\nIngrese cantidad a restar al stock existente: ");
            
            unsigned int suma;
            scanf("%u", &suma);

            if (suma > stock[i][0])
            {
                printf("\nERROR (la cantidad ingresada es superior al stock)");
                printf("\nVolviendo al menu...");
                menu(codigos, nombres, stock, cant_producto);
            } else
            {
                stock[i][0] -= suma;

                printf("\nLa operacion se ha realizado exitosamente\n");
                printf("\nProducto: %s | Stock: %d", nombres[buscar], stock[i][0]);

                menu(codigos, nombres, stock, cant_producto);
            }
        } else
        {
            printf("\nNo se han encontrado el producto con el codigo ingresado\n");
            printf("\nVolviendo al menu...\n");
            menu(codigos, nombres, stock, cant_producto);
        }
    }

    menu(codigos, nombres, stock, cant_producto);
}

void listado(int codigos[FIL][COL], char nombres[FIL][COL], unsigned int stock[FIL][COL], int *cant_producto)
{
    char respuesta[COL], aux_char[COL];
    int aux_num;
    unsigned int aux_u;

    for (int i = 0; i < *cant_producto; i++)
    {
        for (int j = 0; j < *cant_producto-1; j++)
        {
            if (codigos[j][0] > codigos[j+1][0])
            {
                aux_num = codigos[j][0];
                strcpy(aux_char, nombres[j]);
                aux_u = stock[j][0];

                codigos[j][0] = codigos[j+1][0];
                strcpy(nombres[j], nombres[j+1]);
                stock[j][0] = stock[j+1][0];

                codigos[j+1][0] = aux_num;
                strcpy(nombres[j+1],aux_char);
                stock[j+1][0] = aux_u;          
                
            }
            
        }
        
    } 

    for (int i = 0; i < *cant_producto; i++)
    {
        if (codigos[i][0] != 0)
        {
            printf("\nCodigo: %d | Producto: %s | Stock: %u\n", codigos[i][0], nombres[i], stock[i][0]);
        }
    }

    printf("Ingresa M para volver al menu o X para salir: ");
    scanf(" %s", respuesta);

    if (strcmp(respuesta, "M") == 0)
    {
        printf("\nVolviendo al menu...\n");
        menu(codigos, nombres, stock, cant_producto);
    }
    else if (strcmp(respuesta, "X") == 0)
    {
        printf("\nSaliendo...\n");
        exit(0);
    }
}

void sin_stock(int codigos[FIL][COL], char nombres[FIL][COL], unsigned int stock[FIL][COL], int *cant_producto)
{
    char respuesta[COL];
    printf("\nListado de productos sin stock: ");
    for (int i = 0; i < *cant_producto; i++)
    {
        if (stock[i][0] == 0)
        {
            
            printf("\nCodigo: %d | Producto: %s | Stock: %u\n", codigos[i][0], nombres[i], stock[i][0]);
        }
    }

    printf("Ingresa M para volver al menu o X para salir: ");
    scanf(" %s", respuesta);

    if (strcmp(respuesta, "M") == 0)
    {
        printf("\nVolviendo al menu...\n");
        menu(codigos, nombres, stock, cant_producto);
    }
    else if (strcmp(respuesta, "X") == 0)
    {
        printf("\nSaliendo...\n");
        exit(0);
    }
}