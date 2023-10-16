#include <stdio.h>
#include <stdlib.h>
#define FIL 5
#define COL 4

void fill_array(float (*factura)[COL], int fil, float *total);
void payment(float (*factura)[COL], int fil, float *total);
void imprimir(float (*factura)[COL], int fil);

int main()
{
    float factura[FIL][COL];
    float total = 0;

    printf("Programa para facturar\n");

    fill_array(factura, FIL, &total);
    payment(factura, FIL, &total);
    imprimir(factura, FIL);

    return 0;
}

void fill_array(float (*factura)[COL], int fil, float *total)
{
    for (int j = 0; j < fil; j++)
    {
        factura[j][0] = j;

        printf("Ingrese precio unitario: ");
        scanf("%f", &factura[j][1]);

        printf("Ingrese cantidad: ");
        scanf("%f", &factura[j][2]);

        factura[j][3] = factura[j][1] * factura[j][2];

        *total += factura[j][3];
    }
}

void payment(float (*factura)[COL], int fil, float *total)
{
    char opcion;
    float pago;

    printf("\nFormas de pago: |a-- Efectivo | b--> Debito | c--> Credito | x--> Cancelar");
    printf("\nOpción: ");
    scanf(" %c", &opcion);

    switch (opcion)
    {
    case 'a':
        printf("\nEl total es: %.2f", *total);
        printf("\nIngrese el monto con el que va a abonar: ");
        scanf("%f", &pago);

        if (pago < *total)
        {
            printf("\nError, monto ingresado menor a total");
            payment(factura, fil, total);
        }
        else
        {
            printf("\nSu vuelto es: %.2f\n", pago - *total);
        }
        break;

    case 'b':
        printf("\nEl total es: %.2f", *total);
        break;

    case 'c':

        printf("\nEl total es: %.2f", *total);
        printf("\nEl total + 5 porciento de recargo (credito) es: %.2f\n", *total + (*total * 5 / 100));
        break;

    case 'x':
        exit(0);
        break;

    default:
        printf("\nCaracter ingresado no válido");
        payment(factura, fil, total);
        break;
    }
}

void imprimir(float (*factura)[COL], int fil)
{

    for (int i = 0; i < fil; i++)
    {
    
        printf("\nCodigo: %d | Precio: %.2f | Cantidad: %.2f | Subtotal: %.2f\n", i +1 , factura[i][1], factura[i][2], factura[i][3]);

    
    }

}
