#include <iostream>
#include <stdio.h>

using namespace std;
/*Crear un programa que pida los siguientes datos de una canci�n: 
Artista, T�tulo, Duraci�n (en segundos),Tama�o del archivo (en KB). 
Crear una estructura que almacene datos de la canci�n y luego los muestre 
por pantalla.
*/
struct cancion
	{
		char artista[20];
		char titulo[20];
		int duracion = 0;
		int size = 0;
	};

int main(int argc, char *argv[]) {
	
	struct cancion mi_cancion; /*declaracion estructura*/
	
	/*solicitar datos al usuario*/
	printf("\nIngrese nombre del artista: ");
	scanf("%s", mi_cancion.artista);
	
	printf("\nIngrese nombre de la cancion: ");
	scanf("%s", mi_cancion.titulo);
	
	printf("\nIngrese duracion en segundos de la cancion: ");
	scanf("%d", &mi_cancion.duracion);
	
	printf("\nIngrese tama�o en kb de la cancion: ");
	scanf("%d", &mi_cancion.size);
	
	//Imprimir estructura
	printf("\nNombre del artista: %s", mi_cancion.artista);
	printf("\nTitulo de la cancion: %s", mi_cancion.titulo);
	printf("\nDuracion de la cancion en segundos: %d", mi_cancion.duracion);
	printf("\nTama�o en kb de la cancion: %d", mi_cancion.size);
	return 0;
}

