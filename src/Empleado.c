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

	if(Empleado_setNombre(auxEmpleado,Nombre) < 0	||
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
{
	int retorno=-1;
	int i;
	for(i=0; i<len; i++)
	{
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
		auxId = Empleado_generarId();
		utn_getCadena(auxNombre, 50, "\nIngrese Nombre: ", "Error");
		utn_getCadena(auxApellido, 50, "\nIngrese Apellido: ","Error");
		utn_getCadena(auxDni, 20,"\nIngrese DNI: ", "Error");

		this[idxVacio] = Empleado_newParam(auxNombre, auxApellido, auxDni, auxId);
		printf("\nEmpleado creado");
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
int Empleado_idRandom(Empleado* this[], int len, int minimo, int maximo)
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

		retorno = nuevoId;

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



int Empleado_imprimir(Empleado* this[],int len)
{
	int retorno=-1;
	int i;
	char* pNombre;
	int flagNombre;
	char* pApellido;
	int flagApellido;
	char* pDni;
	int flagDni;
	int id;
	int flagId;

	if(this!=NULL && len>=0)
	{
		printf("\nId     Nombre       Apellido     DNI");
		for(i=0;i<len;i++)
		{
			if(this[i]!=NULL)
			{
				pNombre = Empleado_getNombre(this[i], &flagNombre);
				pApellido = Empleado_getApellido(this[i], &flagApellido);
				pDni = Empleado_getDni(this[i], &flagDni);
				id = Empleado_getId(this[i], &flagId);

				if(!flagNombre && !flagApellido && !flagId && !flagDni)
				{
					printf("\n%d   %-10s   %-10s   %-10s",id,pNombre,pApellido,pDni);
				}

			}
		}
		retorno =0;
	}

	return retorno;
}

int Empleado_generarId(void)
{
	static int contador=0;
	contador++;
	return contador+999;
}


int Empleado_baja(Empleado* this[],int len)
{
	int retorno =-1;
	int opcionElegida;
	int idElegido;
	int indexABorrar;

	if(this!=NULL && len>=0)
	{
		utn_getNumero(&opcionElegida, 2, "\nImprimir empleados?\n[1]SI\n[2]No", "ERROr", 1, 2, 2);

		if(opcionElegida ==1)
		{
			Empleado_imprimir(this, len);
		}

		utn_getNumero(&idElegido, 5, "\nIngrese Id a borrar", "Error", 1000, 9999, 2);
		indexABorrar = Empleado_buscarPorId2(this, len, idElegido);
		if(Empleado_delete(this[indexABorrar])==0)
		{
			this[indexABorrar]=NULL;
			printf("\nEl empleado fue borrado");
		}
	}

	return retorno;
}



int Empleado_buscarPorId2(Empleado* empleados[],int len, int id)
{
	int ret=-1;
	int i;
	int flagError;
	int idItem;
	for(i=0; i<len; i++)
	{
		if(empleados[i]!=NULL)
		{
			idItem = Empleado_getId(empleados[i],&flagError);
			if(flagError==0)
			{
				if(idItem==id)
				{
					// Lo encontre!
					ret = i;
					break;
				}
			}
		}
	}
	return ret;
}


int Empleado_modificacion(Empleado* this[],int len)
{
	int retorno=-1;
	int opcionElegida;
	int idModificar;
	int indexModificar;
	char bufferNombre[50];
	char bufferApellido[50];
	char bufferDni[50];

	if(this!=NULL && len>=0)
	{
		utn_getNumero(&opcionElegida, 2, "\nImprimir empleados?\n[1]SI\n[2]No", "ERROr", 1, 2, 2);

		if(opcionElegida ==1)
		{
			Empleado_imprimir(this, len);
		}

		utn_getNumero(&idModificar, 5, "\nIngrese Id a Modificar ", "Error", 1000, 9999, 2);
		indexModificar = Empleado_buscarPorId2(this, len, idModificar);
		utn_getCadena(bufferNombre, 50, "\nIngrese Nombre: ", "Error");
		utn_getCadena(bufferApellido, 50, "\nIngrese Apellido: ", "Error");
		utn_getCadena(bufferDni, 20, "Ingrese DNi: ","Error");

		if(Empleado_setNombre(this[indexModificar],bufferNombre) ==0 &&
		   Empleado_setApellido(this[indexModificar], bufferApellido) ==0 &&
		   Empleado_setDni(this[indexModificar],bufferDni)==0               )
		{
			printf("\nEmpleado Modificado");
		}
		else
		{
			printf("\nFalla catastrofica");
		}

	}

	return retorno;
}


int Empleado_guardar(Empleado* this[],int len)
{
	int retorno=-1;
	int i;
	char* bufferNombre;
	int flagNom;
	char* bufferApellido;
	int flagApe;
	char* bufferDni;
	int flagDni;
	FILE* archivo;

	if(this !=NULL && len>=0)
	{
		for(i=0;i<len;i++)
		{
			if(this[i] != NULL)
			{
				bufferNombre = Empleado_getNombre(this[i], &flagNom);
				bufferApellido = Empleado_getApellido(this[i], &flagApe);
				bufferDni = Empleado_getDni(this[i], &flagDni);

				if(!flagNom && !flagApe && !flagDni)
				{
					archivo =fopen("/home/inoriega/git/ejercicios/src/listaEmpleados.txt","w");
					fprintf(archivo,"%s,%s,%s\n",bufferNombre,bufferApellido,bufferDni);
					fclose(archivo);
					printf("\nDatos guardados");
				}
			}
		}
	}



	return retorno;
}












