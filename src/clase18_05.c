/*
 ============================================================================
 Name        : clase18_05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "arr.h"
#include "Empleado.h"


#define CANT_EMPLEADOS 100

int main(void)
{
	Empleado* empleados[CANT_EMPLEADOS];
	FILE* archivo;
	char bufferNombre[256];
	char bufferApellido[256];
	char bufferDni[256];
	int rS;
	int continuar;
	int opcionElegida;

	int idxVacio;
	int auxId;



	Empleado_initArray(empleados, CANT_EMPLEADOS);

	archivo =fopen("/home/inaki/eclipse-workspace/clase18_05/src/listaEmpleados.txt","r");

	do
	{
		rS =fscanf(archivo,"%[^,],%[^,],%[^\n]\n",bufferNombre,bufferApellido,bufferDni);
		if(rS==3)
		{	printf("\n1");
			idxVacio = Empleado_buscarIndiceVacio(empleados, CANT_EMPLEADOS);
			printf("\n1.1");
			auxId = Empleado_idRandom(empleados, CANT_EMPLEADOS, 1000, 9999);
			printf("\n1.2");
			empleados[idxVacio] = Empleado_newParam(bufferNombre, bufferApellido, bufferDni, auxId);

		}

	}while(rS==3);


	do
	{
		continuar=1;

		printf("\nMenu");
		printf("\n[1]Alta");
		printf("\n[2]Baja");
		printf("\n[3]Modificacion");
		printf("\n[4]Guardar");
		printf("\n[5]Imprimir");
		printf("\n[6]Salir");

		utn_getNumero(&opcionElegida, 2, "\nIngrese: ", "Error", 1, 5, 2);

		switch(opcionElegida)
		{
			case 1:
				Empleado_Alta(empleados, CANT_EMPLEADOS);
				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:
				Empleado_imprimir(empleados, CANT_EMPLEADOS);
				break;
			case 6:
				continuar =0;
				break;
		}

	}while(continuar==1);













	return EXIT_SUCCESS;
}

























