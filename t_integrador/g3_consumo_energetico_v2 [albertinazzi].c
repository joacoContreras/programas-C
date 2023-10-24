#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct data
{
	int anio;
	int mes;
	int dia;
	int hora;
	int minuto;
	int segundo;
	float consumo;
	char tipoDispositivo[20];
	float tempAmbiente;
	float potencia;
	float costo;
};

int contarLineas(FILE *archivo){
	if (archivo == NULL)
	{
		printf("No se pudo abrir el archivo.\n");
		return 1;
	}
	
	int contador = 0;
	char caracter;
	
	while ((caracter = fgetc(archivo)) != EOF)
	{
		if (caracter == '\n')
		{
			contador++;
		}
	}
	
	// Rebobinar el archivo al comienzo
	rewind(archivo);
	
	return contador;
}
	
	void leer(FILE *archivo, struct data **datos, int p){
		// Verificar si el archivo se abrió correctamente
		if (archivo == NULL)
		{
			printf("\nNo se pudo abrir el archivo");
			exit(1);
		}
		//reseva de la memoria
		*datos = (struct data *)malloc(p * sizeof(struct data));
		if (*datos == NULL)
		{
			printf("Error al asignar memoria.\n");
			exit(1);
		}
		
		
		for (int i = 0; i < p; i++)
		{
			/*%[^,] se utiliza en las funciones de lectura de archivos en C (como fscanf o sscanf) para leer una secuencia de caracteres hasta encontrar una coma (,). */
			
			fscanf(archivo, "%d-%d-%d %d:%d:%d,%f,%19[^,],%f,%f,%f\n", &(*datos)[i].anio, &(*datos)[i].mes, &(*datos)[i].dia, &(*datos)[i].hora, &(*datos)[i].minuto, &(*datos)[i].segundo, &(*datos)[i].consumo, (*datos)[i].tipoDispositivo, &(*datos)[i].tempAmbiente, &(*datos)[i].potencia, &(*datos)[i].costo);
		}
	}
		
		void imprimir(struct data *datos, int p){
			printf("\nFecha | Hora | Consumo | Tipo de Dispositivo | Temp. Ambiente | Potencia del E. | Costo ");
			for (int i = 0; i < p; i++)
			{
				printf("\n %d-%d-%d   |   %d:%d:%d   |   %.2f (kWh)   |   %s   |   %.2f   |   %.2f(W)   |   %.2f$", datos[i].anio, datos[i].mes, datos[i].dia, datos[i].hora, datos[i].minuto, datos[i].segundo, datos[i].consumo, datos[i].tipoDispositivo, datos[i].tempAmbiente, datos[i].potencia, datos[i].costo);
			}
		}
			
			float calcularCostoMes(struct data *datos, int p, int mesSeleccionado){
				float costoTotal = 0.0;
				
				for (int i = 0; i < p; i++)
				{
					if (datos[i].mes == mesSeleccionado){
						costoTotal += datos[i].costo;
					}
				}
				
				return costoTotal;
			}
				
				int main()
				{
					FILE *archivo;
					struct data *datos;
					
					archivo = fopen("dataset.txt", "r");
					if (archivo == NULL)
					{
						printf("No se pudo abrir el archivo.\n");
						return 1;
					}
					
					int lineas = contarLineas(archivo);
					int p = lineas;
					
					int flag = 0;
					
					do
					{
						printf("\nMenu: ");
						printf("\n0. Salir");
						printf("\n1. Imprimir datos del archivo");
						printf("\n4. Calcular el costo total de un mes");
						
						int opcion = 0;
						printf("\nTu opcion: ");
						scanf("%d", &opcion);
						
						switch (opcion)
						{
						case 1:
							if (datos != NULL) {
								free(datos);  // Liberar la memoria antes de volver a asignarla
							}
							leer(archivo, &datos, p);
							imprimir(datos, p);
							break;
							
						case 4:
						{
							int mesSeleccionado;
							printf("Ingresa el mes para calcular el costo total: ");
							scanf("%d", &mesSeleccionado);
							printf ("Mes seleccionado:%d.\n", mesSeleccionado);
							float costoTotal = calcularCostoMes(datos, p, mesSeleccionado);
							printf("El costo total del mes es: %.2f$\n", costoTotal);
							break;
						}
						
						case 0:
							printf("\nSaliendo...\n");
							flag = 1;
							exit(1);
							
						default:
							printf("\nError...");
							break;
						}
					} while (flag == 0);
					
					fclose(archivo);
					free(datos);
					
					return 0;
				}
				
