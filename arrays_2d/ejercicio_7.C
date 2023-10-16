#include <stdlib.h>
#include <stdio.h>
#define COL 2
#define FIL 15

void rellenar(float survay[FIL][COL]);

void imprimir(float survay[FIL][COL]);


int main()
{
    float survay[FIL][COL];
   

    printf("Programa para encuestar(Para finalizar ingrese 9 como primer valor)");
    printf("\nIngrese 1 o 0 para aceptar o no el producto");
    printf("\nPor ej., el par (1,0) significa que el encuestado acepta el producto “a” pero no el “b”. ");


    rellenar(survay);
    imprimir(survay);
    
   

    return 0;
}

void rellenar(float survay[FIL][COL])
{
   

    for (int i = 0; i < FIL; i++)
    {
        printf("\nEncuestado N: %d", i +1);
        printf("\nProducto a: ");
        scanf("%f", &survay[i][0]);

        if (survay[i][0] > 1 && survay[i][0] != 9)
        {
            printf("\nnumero ingresado no valido");
            printf("\nProducto a: ");
            scanf("%f", &survay[i][0]);
            

        } else if(survay[i][0] == 0)
        
        {
            survay[i][0] = -1;
            printf("\nProducto b: ");
            scanf("%f", &survay[i][1]);

            if (survay[i][1] > 1)
             {
                printf("\numero ingresado no valido");
                printf("\nProducto b: ");
                scanf("%f", &survay[i][1]);

            } else if (survay[i][1] == 0)
            {
                survay[i][1] = -1;
            }

        } else if (survay[i][0] == 9)

        {
            break;

        } else if (survay[i][0] == 1)
        {
            printf("\nProducto b: ");
            scanf("%f", &survay[i][1]);

            if (survay[i][1] > 1)
             {
                printf("\numero ingresado no valido");
                printf("\nProducto b: ");
                scanf("%f", &survay[i][1]);

            } else if (survay[i][1] == 0)
            {
                survay[i][1] = -1;
            }
            
        }
    }
}

void imprimir(float survay[FIL][COL])
{
    float aprob_a = 0, aprob_b = 0, cont = 0;
    for (int i = 0; i < FIL; i++)
    {
        if (survay[i][0] == 1)
        {
            aprob_a+= 1;

        } else if (survay[i][1] == 1)
        {
            aprob_b+= 1;
        }

        if (survay[i][0] == 1 || survay[i][0] == -1)
        {
            cont += 1;

        } else if (survay[i][1] == 1 || survay[i][1] == -1)
        {
            cont += 1;
        }
        
            
        
        
    
    }
    
    printf("\nCantidad de encuestados: %0.2f", cont);

    printf("\nAceptacion del producto a: %.2f", (aprob_a/cont)*100);
    printf("\nAceptacion del producto b: %.2f", (aprob_b/cont)*100);

}