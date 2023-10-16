#include <stdlib.h>
#include <stdio.h>

#define FIL 100
#define COL 4

void rellenar(int libros[FIL][COL]);
void imprimir(int libros[FIL][COL]);
void prestar(int libros[FIL][COL]);
void estadisticas(int libros[FIL][COL]);
int libros[FIL][COL];

char menu();

int main()
{
    
    

    printf("\nPrograma para gestionar libros\n");

    char opcion = menu();

    switch (opcion)
    {
    case 'a':

        rellenar(libros);
        break;
    
    case 'b':

        imprimir(libros);
        break;

    case 'c':

        prestar(libros);
        break;

    case 'd':

        estadisticas(libros);
        break;

    case 'x':

        printf("\nSaliendo...");
        exit(0);

    
    default:
        printf("\nCaracter no valido");
        main();
        break;
    }
  

    

    return 0;
}

char menu()
{
    char respuesta;
    printf("\na--> Cargar los datos registrados en un arreglo.");
    printf("\nb--> Mostrar los datos registrados en el arreglo.");
    printf("\nc--> Prestar un libro.");
    printf("\nd--> Mostrar el libro más solicitado y menos solicitado");
     printf("\nx--> Salir");
    printf("\nIngrese la operacion a realizar: ");

    scanf(" %c", &respuesta);
    return respuesta;
}

void rellenar(int libros[FIL][COL])
{
    printf("\nIngrese datos libro (codigo 0 para detener)");
    for (int i = 0; i < FIL; i++)
    {
        printf("\nIngrese codigo del libro %d: ", i +1);
        scanf("%d", &libros[i][0]);

        if (libros[i][0] == 0)
        {
            break;
        }
        

        printf("\nIngrese cantidad total de ejemplares: ");
        scanf("%d", &libros[i][1]);


        printf("\nIngrese cantidad de ejemplares prestados: ");
        scanf("%d", &libros[i][2]);

        if (libros[i][2] > libros[i][1])
        {
            printf("\nError (mas libros prestados que existencias). Vuuelva a ingresar libro.");
            printf("\nVolviendo al menu...");
            break;
        }
        

        libros[i][3] = libros[i][1] - libros[i][0];
    }

    main();
    
}

void imprimir(int libros[FIL][COL])
{
    for (int i = 0; i < FIL; i++)
    {
        if (libros[i][0] != 0)
        {
            for (int j = 0; j < COL; j++)
            {
                printf("\nCODIGO %d | Cant. TOTAL %d | Cant. PRESTADO %d | Cant. DISPONIBLE %d", libros[i][j],libros[i][j], libros[i][j], libros[i][j]);
            }
        }
        
    }

    main();
    
}

void prestar(int libros[FIL][COL])
{
    int eleccion = 0;
    printf("\nLista de libros disponibles");

     for (int i = 0; i < FIL; i++)
    {
       if (libros[i][3] > 0)
        {
            printf("\nCODIGO: %d | CANT. DISPONIBLE: %d",libros[i][0], libros[i][3]);

        } else if(libros[i][0] != 0)
        {
            printf("\nNo hay stock del libro: %d" ,libros[i][0]);
        }
    }

    printf("\nIngrese el codigo del libro que desea: ");
    scanf("%d", &eleccion);

    for (int i = 0; i < FIL; i++)
    {
       if (libros[i][0] == eleccion)
        {
            libros[i][3] -= 1;  // Restar 1 al valor de la celda libros[i][3]
            libros[i][2] += 1;  // Sumar 1 al valor de la celda libros[i][2]

        } 
    }

    main();
}

void estadisticas(int libros[FIL][COL])
{
    int mas_prestados = 0, menos_prestados = 0, top = 0, menos = FIL;

    for (int i = 0; i < FIL; i++)
    {
       if (libros[i][2] > top)
        {
            top = libros[i][2];
            mas_prestados = libros[i][0];

        } 
    }

    for (int i = 0; i < FIL; i++)
    {
       if (libros[i][2] != 0 && libros[i][2] < menos)
        {
            menos = libros[i][2];
            menos_prestados = libros[i][0];

        } 
    }

    printf("\nEl libro mas prestado (codigo): %d", mas_prestados);
    printf("\nEl libro menos prestado (codigo): %d", menos_prestados);

    main();
}