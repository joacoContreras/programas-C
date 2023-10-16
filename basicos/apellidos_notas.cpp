#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int grade=0;
	char name='0';
	printf("Ingrese la primera letra de su apellido en mayuscula\n");
	scanf("%c", &name);
	printf("Ingrese la nota obtenida \n");
	scanf("%d", &grade);
	if( name='A' ||name='C'||name='B'||name='D'||name='E'||name='F'||name='G'||name='H'||name='I'||name='J'||name='K'||name='L'||name='M' && grade >=7) {
		printf("Perteneces al grupo A");
	} else if( name='N' ||name='L'||name='O'||name='P'||name='Q'||name='R'||name='S'||name='T'||name='Y'||name='Z'||name='V'||name='W'||name='Ñ' && grade>=7){
		printf("Perteneces al grupo B");} 
	else if( name='A' ||name='C'||name='B'||name='D'||name='E'||name='F'||name='G'||name='H'||name='I'||name='J'||name='K'||name='L'||name='M' && grade<=7){
			printf("Perteneces al grupo C");} else if( name='N' ||name='L'||name='O'||name='P'||name='Q'||name='R'||name='S'||name='T'||name='Y'||name='Z'||name='V'||name='W'||name='Ñ' && grade<=7){
				printf("Perteneces al grupo D");}
	return 0;
}

