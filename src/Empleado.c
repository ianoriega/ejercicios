#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "arr.h"
#include "Empleado.h"

Empleado* Empleado_new(void)
{
	return (Empleado*) malloc(sizeof(Empleado));
}

Empleado* Empleado_newParam(char* Nombre,char* Apellido,char* Dni,int idEmpleado)
{
	Empleado* auxEmpleado = Empleado_new();

	if(Empleado_setNombre(auxEmpleado,Nombre) < 0 	||
		Empleado_setApellido(auxEmpleado,Apellido) < 0 	||
		Empleado_setDni(auxEmpleado,Dni) < 0 ||
		Empleado_setId(auxEmpleado,idEmpleado) < 0)
	{
		Empleado_delete(auxEmpleado);
		auxEmpleado = NULL;
	}
	return auxEmpleado;
}


int Empleado_delete(Empleado* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int Empleado_setNombre(Empleado* this,char* Nombre)
{
	int retorno = -1;
	if(this != NULL && Nombre != NULL && Empleado_isValidNombre(Nombre))
	{
		strcpy(this->Nombre,Nombre);
		retorno =0;
	}
	return retorno;
}

char* Empleado_getNombre(Empleado* this,int* flagError)
{
	*flagError = -1;
	char* auxNombre = NULL;
	if(this != NULL && flagError != NULL)
	{
		auxNombre = this->Nombre;
		*flagError = 0;
	}
	return auxNombre;
}

int Empleado_isValidNombre(char* Nombre)
{
	return 1;
}


int Empleado_setApellido(Empleado* this,char* Apellido)
{
	int retorno = -1;
	if(this != NULL && Apellido != NULL && Empleado_isValidApellido(Apellido))
	{
		strcpy(this->Apellido,Apellido);
		retorno =0;
	}
	return retorno;
}

char* Empleado_getApellido(Empleado* this,int* flagError)
{
	*flagError = -1;
	char* auxApellido = NULL;
	if(this != NULL && flagError != NULL)
	{
		auxApellido = this->Apellido;
		*flagError = 0;
	}
	return auxApellido;
}

int Empleado_isValidApellido(char* Apellido)
{
	return 1;
}


int Empleado_setDni(Empleado* this,char* Dni)
{
	int retorno = -1;
	if(this != NULL && Dni != NULL && Empleado_isValidDni(Dni))
	{
		strcpy(this->Dni,Dni);
		retorno =0;
	}
	return retorno;
}

char* Empleado_getDni(Empleado* this,int* flagError)
{
	*flagError = -1;
	char* auxDni = NULL;
	if(this != NULL && flagError != NULL)
	{
		auxDni = this->Dni;
		*flagError = 0;
	}
	return auxDni;
}

int Empleado_isValidDni(char* Dni)
{
	return 1;
}


int Empleado_buscarIndiceVacio(Empleado* this[],int len)
{	printf("\n1a");
	int retorno=-1;
	int i;
	for(i=0; i<len; i++)
	{printf("\n1.b");
		if(this[i]==NULL)
		{
			retorno =  i;
			break;
		}

	}
	return retorno;
}


int Empleado_initArray(Empleado* this[],int len)
{
	int i;
	int retorno =-1;

	if(this !=NULL && len>=0)
	{
		retorno =0;
		for(i=0; i<len; i++)
		{
			this[i] = NULL;
		}
	}

	return retorno;
}


int Empleado_Alta(Empleado* this[],int len)
{
	int retorno=-1;
	char auxNombre[50];
	char auxApellido[50];
	char auxDni[20];
	int auxId;
	int idxVacio;

	if(this!=NULL && len>=0)
	{
		idxVacio = Empleado_buscarIndiceVacio(this, len);
		auxId = Empleado_idRandom(this, len, 1000, 9999);
		utn_getCadena(auxNombre, 50, "\nIngrese Nombre", "Error");
		utn_getCadena(auxApellido, 50, "\nIngrese Apellido","Error");
		utn_getCadena(auxDni, 20,"\nIngrese DNI", "Error");

		this[idxVacio] = Empleado_newParam(auxNombre, auxApellido, auxDni, auxId);
		retorno=0;

	}

	return retorno;
}

/**
 *\brief recibe un indice de la lista y genera un id random
 *\param Employee* list recibe la lista
 *\param int len recibe el limite de la lista
 *\param int minimo recibe el minimo del id
 *\param int maximo recibe el maximo del id
 *\return retorno nuevo id y -1 si no pudo validar
 */
int Empleado_idRandom(Empleado* this[],int len, int minimo,int maximo)
{
	int retorno =-1;
	int flagIdRepetido;
	int nuevoId;
	int i;

	if(this!=NULL && len>=0 && minimo<maximo)
	{
		do
		{
			flagIdRepetido =1;

			do
			{
				srand(time(NULL));
				nuevoId = minimo + (rand() % maximo +1 - minimo);

			}while(nuevoId < minimo || nuevoId > maximo);

			for(i=0;i<len;i++)
			{
				if(this[i]->Id== nuevoId)
				{
					break;
				}

				flagIdRepetido =0;
			}

		}while(flagIdRepetido);

		retorno =nuevoId;

	}
	else
	{
		printf("error");
	}

	return retorno;
}





int Empleado_setId(Empleado* this,int Id)
{
	int retorno = -1;
	if(this != NULL && Empleado_isValidId(Id))
	{
		this->Id = Id;
		retorno =0;
	}
	return retorno;
}

int Empleado_getId(Empleado* this,int* flagError)
{
	*flagError = -1;
	int auxId = -1;
	if(this != NULL && flagError != NULL)
	{
		auxId = this->Id;
		*flagError = 0;
	}
	return auxId;
}

int Empleado_isValidId(int Id)
{
	return 1;
}



int Empleado_imprimir(Empleado* *this,int len)
{
	int retorno=-1;
	int i;

	if(this!=NULL && len>=0)
	{
		printf("Id - Nombre - Apellido - DNI");
		for(i=0;i<len;i++)
		{
			if(this[i]!=NULL)
			{
				printf("%d   %10s   %10s   %10s",this[i]->Id,this[i]->Nombre,this[i]->Apellido,this[i]->Dni);
			}
		}
	}

	return retorno;
}


























