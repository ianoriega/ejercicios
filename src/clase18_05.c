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
	int continuar;
	int opcionElegida;
	int i;
	int idxVacio=22;
	int auxId;

	/*Empleado_initArray(empleados, CANT_EMPLEADOS);
	archivo =fopen("/home/inoriega/git/ejercicios/src/listaEmpleados.txt","r");

	for(i=0;i<5;i++)
	{
		fscanf(archivo,"%[^,],%[^,],%[^\n]\n",bufferNombre,bufferApellido,bufferDni);

		idxVacio = Empleado_buscarIndiceVacio(empleados, CANT_EMPLEADOS);
		auxId = Empleado_generarId();
		empleados[idxVacio]= Empleado_newParam(bufferNombre, bufferApellido, bufferDni, auxId);
	}
	fclose(archivo);*/

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

		utn_getNumero(&opcionElegida, 2, "\nIngrese: ", "Error", 1, 6, 2);

		switch(opcionElegida)
		{
			case 1:
				Empleado_Alta(empleados, CANT_EMPLEADOS);
				break;
			case 2:
				Empleado_baja(empleados, CANT_EMPLEADOS);
				break;
			case 3:
				Empleado_modificacion(empleados, CANT_EMPLEADOS);
				break;
			case 4:
				Empleado_guardar(empleados, CANT_EMPLEADOS);
				break;
			case 5:
				Empleado_imprimir(empleados, CANT_EMPLEADOS);
				break;
			case 6:
				continuar =0;
				break;
		}

	}while(continuar==1);

	printf("Gracias por utilizar la aplicacion!!!");











	return EXIT_SUCCESS;
}

























