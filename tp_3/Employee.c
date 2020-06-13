#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "funciones.h"

/*
* \brief Genera espacio en memoria para almacenar una estructura de datos del tipo Employee
* \return devuelve la direccion de memoria donde se almacenará la estructura
*/
Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}

/*
* \brief Crea una nueva estructura del tipo Employee
* \param id - id del empleado
* \param nombreStr - nombre del empleado
* \param horasTrabajadas - horas trabajadas por el empleado
* \param sueldo - sueldo del empleado
* \return devuelve la direccion de memoria de la nueva estructura
*/
Employee* employee_newParametrosFormats(int id,char* nombreStr,int horasTrabajadasStr,int sueldoStr)
{
	Employee* pEmployee = employee_new();

	employee_setId(pEmployee, id);
	employee_setNombre(pEmployee, nombreStr);
	employee_setHorasTrabajadas(pEmployee, horasTrabajadasStr);
	employee_setSueldo(pEmployee, sueldoStr);

	return pEmployee;
}

/*
* \brief Crea una nueva estructura del tipo Employee con parametros de cadena de caracteres
* \param idStr - id del empleado
* \param nombreStr - nombre del empleado
* \param horasTrabajadasStr - horas trabajadas por el empleado
* \param sueldoStr - sueldo del empleado
* \return devuelve la direccion de memoria de la nueva estructura
*/
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pEmployee = employee_new();

	employee_setId(pEmployee, atoi(idStr));
	employee_setNombre(pEmployee, nombreStr);
	employee_setHorasTrabajadas(pEmployee, atoi(horasTrabajadasStr));
	employee_setSueldo(pEmployee, atoi(sueldoStr));

	return pEmployee;
}

/*
* \brief Muestra un solo empleado
* \param this - direccion de memoria del empleado
* \param header - 1 muestra un encabezado - 0 no muestra encabezado
* \return devuelve 1 ok,  -1 error
*/
int employee_listOneEmployee(Employee* this, int header)
{
	int retorno,id, horasTrabajadas, sueldo;
	char nombre[128];
	retorno=1;

	if(this==NULL){
		retorno=-1;
	}else{
		employee_getId(this,&id);
		employee_getNombre(this,nombre);
		employee_getHorasTrabajadas(this,&horasTrabajadas);
		employee_getSueldo(this,&sueldo);

		if(header){
			printf("\n%5s%15s%25s%15s","Id","Nombre","Horas Trabajadas","Sueldo");
		}

		printf("\n%5d%15s%25d%15d", id, nombre, horasTrabajadas, sueldo);
	}
	return retorno;
}


/*
* \brief Guarda un dato en la estructura
* \param this - direccion de memoria del empleado
* \param id - id del empleado
* \return devuelve 1 ok,  -1 error
*/
int employee_setId(Employee* this,int id)
{
	int retorno;
	retorno=1;

	if(this==NULL || id<0){
		retorno = -1;
	}else{
		this->id = id;
	}

	return retorno;
}


/*
* \brief Obtiene una copia de un dato de la estructura
* \param this - direccion de memoria del empleado
* \param id - id del empleado
* \return devuelve 1 ok,  -1 error
*/
int employee_getId(Employee* this,int* id)
{
	int retorno;
	retorno = 1;
	if(this==NULL){
		retorno = -1;
	}else{
		*id = this->id;
	}

	return retorno;
}

/*
* \brief Guarda un dato en la estructura
* \param this - direccion de memoria del empleado
* \param nombre - nombre del empleado
* \return devuelve 1 ok,  -1 error
*/
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno=1;

	if(this==NULL || strlen(nombre)<1){
		retorno = -1;
	}else{
		strcpy(this->nombre, nombre);
	}

	return retorno;

}

/*
* \brief Obtiene una copia de un dato de la estructura
* \param this - direccion de memoria del empleado
* \param nombre - nombre del empleado
* \return devuelve 1 ok,  -1 error
*/
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno=1;

	if(this==NULL){
		retorno = -1;
	}else{
		strcpy(nombre,this->nombre);
	}

	return retorno;
}


/*
* \brief Guarda un dato en la estructura
* \param this - direccion de memoria del empleado
* \param horasTrabajadas - horas trabajadas por el empleado
* \return devuelve 1 ok,  -1 error
*/
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno;
	retorno=1;

	if(this==NULL || horasTrabajadas<1){
		retorno = -1;
	}else{
		this->horasTrabajadas = horasTrabajadas;
	}

	return retorno;
}

/*
* \brief Obtiene una copia de un dato de la estructura
* \param this - direccion de memoria del empleado
* \param horasTrabajadas - horas trabajadas por el empleado
* \return devuelve 1 ok,  -1 error
*/
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno;
	retorno=1;

	if(this==NULL){
		retorno = -1;
	}else{
		*horasTrabajadas = this->horasTrabajadas;
	}

	return retorno;
}


/*
* \brief Guarda un dato en la estructura
* \param this - direccion de memoria del empleado
* \param sueldo - sueldo del empleado
* \return devuelve 1 ok,  -1 error
*/
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno;
	retorno=1;

	if(this==NULL || sueldo<1){
		retorno = -1;
	}else{
		this->sueldo = sueldo;
	}

	return retorno;
}


/*
* \brief Obtiene una copia de un dato de la estructura
* \param this - direccion de memoria del empleado
* \param sueldo - sueldo del empleado
* \return devuelve 1 ok,  -1 error
*/
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno;
	retorno=1;

	if(this==NULL){
		retorno = -1;
	}else{
		*sueldo = this->sueldo;
	}

	return retorno;
}

void employee_delete(void)
{
	//
}

/*
* \brief Genera un id autoincremental para la lista de empleados
* \param pArrayListEmployee puntero a la lista de empleados
* \param len tamaño de la lista
* \return int Devuelve el valor del próximo id a ser utilizado
*/
int employee_generateId(LinkedList* pArrayListEmployee, int len)
{
	int i, maxId, currentId;
	Employee* pEmployee;
	maxId=0;

	if(!ll_isEmpty(pArrayListEmployee)){
		for(i=0;i<len;i++){
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmployee, &currentId);
			if(currentId>maxId || i==0){
				maxId=currentId;
			}
		}
	}
	return maxId+1;
}


/*
* \brief Modifica los datos de un empleado seleccionado por el usuario
* \param pArrayListEmployee puntero a la lista de empleados
* \param index - indice del empleado a modificar
* \return devuelve 1 ok,  -1 error
*/
int employee_editEmployee(LinkedList* pArrayListEmployee, int index)
{
	int opcion, horasTrabajadas, sueldo, retorno;
	char nombre[128];
	Employee* pAuxEmployee = (Employee*) malloc(sizeof(Employee));
	Employee* pEmployee;

	retorno = 1;

	pEmployee = ll_get(pArrayListEmployee, index);
	//Guardo una copia del registro en caso que se cancele la modificación
	employee_getId(pEmployee, &pAuxEmployee->id);
	employee_getNombre(pEmployee, pAuxEmployee->nombre);
	employee_getHorasTrabajadas(pEmployee, &pAuxEmployee->horasTrabajadas);
	employee_getSueldo(pEmployee, &pAuxEmployee->sueldo);

	employee_listOneEmployee(pEmployee, 1);

	opcion = menuModificar();

	while(opcion!=5){
		switch(opcion){
			case 1:
				getString("Ingrese nombre: ", nombre, 128);
				employee_setNombre(pEmployee, nombre);
				employee_listOneEmployee(pEmployee, 1);
				break;
			case 2:
				horasTrabajadas = getInt("Ingrese cantidad de horas trabajadas: ");
				employee_setHorasTrabajadas(pEmployee, horasTrabajadas);
				employee_listOneEmployee(pEmployee, 1);
				break;
			case 3:
				sueldo = getInt("Ingrese sueldo: ");
				employee_setSueldo(pEmployee, sueldo);
				employee_listOneEmployee(pEmployee, 1);
				break;
			case 4:
				printf("\nEstá a punto de cancelar la modificación");
				if(fcontinuar()){
					employee_setNombre(pEmployee, pAuxEmployee->nombre);
					employee_setHorasTrabajadas(pEmployee, pAuxEmployee->horasTrabajadas);
					employee_setSueldo(pEmployee, pAuxEmployee->sueldo);
					printf("\nModificación cancelada");
					return -1;
				}
				break;
		}

		opcion = menuModificar();

	}

	employee_listOneEmployee(pEmployee, 1);
	free(pAuxEmployee);

	return retorno;
}



/** \brief find an Employee by Id and returns the index position in list.
*
* \param pArrayListEmployee LinkedList* Pointer to the list of employees
* \param id int id of the employee
* \return Return employee index position or (-1) if [NULL pointer received or employee not found]
*/
int employee_findEmployeeById(LinkedList* pArrayListEmployee, int id)
{
	int len, index, i, currentId;
	Employee* pEmployee;
	index=-1;

	if(pArrayListEmployee==NULL){
		printf("\nError. No se encuentra la lista");
	}else{
		len=ll_len(pArrayListEmployee);

		for(i=0;i<len;i++){
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmployee, &currentId);
			if(currentId==id){
				index=i;
				break;
			}
		}
	}

	return index;
}

/*
* \brief Compara dos empleados por nombre
* \param employee1 puntero a empleado
* \param employee2 puntero a empleado
* \return devuelve -1, 0, 1 dependiendo del resultado de la comparacion (menor, mayor o igual)
*/
int employee_compareByName(void* employee1, void* employee2)
{
	int retorno;
	retorno=0;
	char nombre1[128];
	char nombre2[128];

	Employee* e1 = (Employee*) employee1;
	Employee* e2 = (Employee*) employee2;

	employee_getNombre(e1, nombre1);
	employee_getNombre(e2, nombre2);

	if(strcmp(nombre1, nombre2)>0){
		retorno=1;
	}else if(strcmp(nombre1, nombre2)<0){
		retorno=-1;
	}else{
		retorno=0;
	}

	return retorno;
}

/*
* \brief Compara dos empleados por id
* \param employee1 puntero a empleado
* \param employee2 puntero a empleado
* \return devuelve -1, 0, 1 dependiendo del resultado de la comparacion (menor, mayor o igual)
*/
int employee_compareById(void* employee1, void* employee2)
{
	int retorno, id1, id2;
	retorno=0;

	Employee* e1 = (Employee*) employee1;
	Employee* e2 = (Employee*) employee2;

	employee_getId(e1, &id1);
	employee_getId(e2, &id2);

	if(id1 > id2){
		retorno=1;
	}else if(id1 < id2){
		retorno=-1;
	}else{
		retorno=0;
	}

	return retorno;
}


/*
* \brief Compara dos empleados por cantidad de horas trabajadas
* \param employee1 puntero a empleado
* \param employee2 puntero a empleado
* \return devuelve -1, 0, 1 dependiendo del resultado de la comparacion (menor, mayor o igual)
*/
int employee_compareByHorasTrabajadas(void* employee1, void* employee2)
{
	int retorno, horasTrabajadas1, horasTrabajadas2;
	retorno=0;

	Employee* e1 = (Employee*) employee1;
	Employee* e2 = (Employee*) employee2;

	employee_getHorasTrabajadas(e1, &horasTrabajadas1);
	employee_getHorasTrabajadas(e2, &horasTrabajadas2);

	if(horasTrabajadas1 > horasTrabajadas2){
		retorno=1;
	}else if(horasTrabajadas1 < horasTrabajadas2){
		retorno=-1;
	}else{
		retorno=0;
	}

	return retorno;
}


/*
* \brief Compara dos empleados por sueldo
* \param employee1 puntero a empleado
* \param employee2 puntero a empleado
* \return devuelve -1, 0, 1 dependiendo del resultado de la comparacion (menor, mayor o igual)
*/
int employee_compareBySueldo(void* employee1, void* employee2)
{
	int retorno, sueldo1, sueldo2;
	retorno=0;

	Employee* e1 = (Employee*) employee1;
	Employee* e2 = (Employee*) employee2;

	employee_getSueldo(e1, &sueldo1);
	employee_getSueldo(e2, &sueldo2);

	if(sueldo1 > sueldo2){
		retorno=1;
	}else if(sueldo1 < sueldo2){
		retorno=-1;
	}else{
		retorno=0;
	}

	return retorno;
}
