/*
 * Empleado.h
 *
 *  Created on: 18 may. 2021
 *      Author: inaki
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

typedef struct
{
	char  Nombre[50];
	char  Apellido[50];
	char  Dni[20];
	int Id;
}Empleado;

Empleado* Empleado_new(void);

Empleado* Empleado_newParam(char* Nombre,char* Apellido,char* Dni,int idEmpleado);

int Empleado_delete(Empleado* this);

int Empleado_initArray(Empleado* this[],int len);

int Empleado_buscarIndiceVacio(Empleado* this[],int len);

int Empleado_setNombre(Empleado* this,char* Nombre);
char* Empleado_getNombre(Empleado* this,int* flagError);
int Empleado_isValidNombre(char* Nombre);

int Empleado_setApellido(Empleado* this,char* Apellido);
char* Empleado_getApellido(Empleado* this,int* flagError);
int Empleado_isValidApellido(char* Apellido);

int Empleado_setDni(Empleado* this,char* Dni);
char* Empleado_getDni(Empleado* this,int* flagError);
int Empleado_isValidDni(char* Dni);

int Empleado_setId(Empleado* this,int Id);
int	Empleado_getId(Empleado* this,int* flagError);
int Empleado_isValidId(int Id);


/**
 *\brief recibe un indice de la lista y genera un id random
 *\param Employee* list recibe la lista
 *\param int len recibe el limite de la lista
 *\param int indice recibe la posicion a modificar
 *\param int minimo recibe el minimo del id
 *\param int maximo recibe el maximo del id
 *\return retorno nuevo id y -1 si no pudo validar
 */
int Empleado_idRandom(Empleado* this[], int len, int minimo, int maximo);

int Empleado_imprimir(Empleado* this[],int len);

int Empleado_generarId(void);

int Empleado_buscarPorId2(Empleado* empleados[],int len, int id);

int Empleado_modificacion(Empleado* this[],int len);

int Empleado_guardar(Empleado* this[],int len);

#endif /* EMPLEADO_H_ */
