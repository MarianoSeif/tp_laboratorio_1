#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int datos, retorno;
	char id[10], nombre[128], horasTrabajadas[10], sueldo[10];
	Employee* pEmployee;

	retorno=-1;

	//Leo el encabezado

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

	while(!feof(pFile)){
		if(feof(pFile)){
			break;
		}
		datos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
		if(datos==4){
			pEmployee = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
			ll_add(pArrayListEmployee, pEmployee);
			retorno=1;
		}
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	Employee* pEmployee;

	while(!feof(pFile)){
		pEmployee = employee_new();
		if(fread(pEmployee, sizeof(Employee), 1, pFile)==1){
			ll_add(pArrayListEmployee, pEmployee);
		}else{
			if(feof(pFile)){
				break;
			}else{
				printf("\nError, no se pudo leer el registro");
				retorno = -1;
				break;
			}
		}
	}
    return retorno;
}
