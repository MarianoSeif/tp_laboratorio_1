#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno;
	FILE* pFile;

	pFile=fopen(path, "r");

	if(pFile==NULL){
    	retorno = -1;
    }else{
    	if(parser_EmployeeFromText(pFile, pArrayListEmployee)==-1){
			printf("\nError. El archivo está vacio");
		}

		fclose(pFile);
		retorno = 1;
    }

	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;
	retorno = 1;
	pFile = fopen(path, "rb");

	if(pFile==NULL){
		retorno = -1;
	}else{
		if(parser_EmployeeFromBinary(pFile, pArrayListEmployee)==-1){
			printf("\nError. El archivo está vacio");
		}
		fclose(pFile);
	}

	return retorno;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i, len, retorno;
    retorno = 1;
    Employee* pEmployee;
    //Employee* pAuxEmployee = (Employee*) malloc(sizeof(Employee));

    len = ll_len(pArrayListEmployee);

    if(ll_isEmpty(pArrayListEmployee)){
    	printf("\nNo hay empleados para mostrar");
    	retorno = -1;
    }else{
    	printf("\nListar Empleados\n========================================");
		printf("\n%5s%15s%25s%15s","Id","Nombre","Horas Trabajadas","Sueldo");

		for(i=0;i<len;i++){
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			employee_listOneEmployee(pEmployee, 0);
		}
    }

	return retorno;
}



/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int len, id, horasTrabajadas, sueldo;
	Employee* pEmployee;
	char nombre[128];

	printf("\nAgregar Empleado\n========================================");
	getString("Ingrese nombre: ", nombre, 128);
	horasTrabajadas = getInt("Ingrese cantidad de horas trabajadas: ");
	sueldo = getInt("Ingrese sueldo: ");

	len = ll_len(pArrayListEmployee);

	id = employee_generateId(pArrayListEmployee, len);

	pEmployee = employee_newParametrosFormats(id, nombre, horasTrabajadas, sueldo);
	ll_add(pArrayListEmployee, pEmployee);
	return 1;

}




/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int id, index, retorno;
	Employee* pEmployee;
	retorno = 1;
	printf("\nEliminar Empleado\n========================================");
	controller_ListEmployee(pArrayListEmployee);
	id = getInt("Ingrese el ID del empleado a eliminar: ");
	index = employee_findEmployeeById(pArrayListEmployee, id);
	if(index==-1){
		printf("\nNo se encontró al empleado");
		retorno = -1;
	}else{
		pEmployee=(Employee*) ll_get(pArrayListEmployee, index);
		employee_listOneEmployee(pEmployee, 1);
		printf("\nEstá a puntos de eliminar al empleado");
		if(fcontinuar()){
			if(ll_remove(pArrayListEmployee, index)!=0){
				retorno = -1;
			}
		}else{
			retorno = -1;
		}
	}
	return retorno;
}




/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int id, index, retorno;
	retorno = 1;
	printf("\nModificar Empleado\n========================================");
	controller_ListEmployee(pArrayListEmployee);
	id = getInt("Ingrese el ID del empleado a modificar: ");
	index = employee_findEmployeeById(pArrayListEmployee, id);
	if(employee_editEmployee(pArrayListEmployee, index)==-1){
		retorno = -1;
	}
	return retorno;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno, opcion;
    retorno = 1;
    opcion = menuOrdenar();
    printf("\nOrdenando...");
    printf("\n");

    switch(opcion){
    	case 1:
    		if(ll_sort(pArrayListEmployee, employee_compareById, 1)!=0){
    			retorno = -1;
    		}
    		break;
    	case 2:
    		if(ll_sort(pArrayListEmployee, employee_compareById, 0)!=0){
				retorno = -1;
			}
			break;
    	case 3:
    		if(ll_sort(pArrayListEmployee, employee_compareByName, 1)!=0){
				retorno = -1;
			}
			break;
    	case 4:
    		if(ll_sort(pArrayListEmployee, employee_compareByName, 0)!=0){
				retorno = -1;
			}
			break;
    	case 5:
    		if(ll_sort(pArrayListEmployee, employee_compareByHorasTrabajadas, 1)!=0){
				retorno = -1;
			}
			break;
    	case 6:
    		if(ll_sort(pArrayListEmployee, employee_compareByHorasTrabajadas, 0)!=0){
				retorno = -1;
			}
			break;
    	case 7:
    		if(ll_sort(pArrayListEmployee, employee_compareBySueldo, 1)!=0){
				retorno = -1;
			}
			break;
    	case 8:
    		if(ll_sort(pArrayListEmployee, employee_compareBySueldo, 0)!=0){
				retorno = -1;
			}
			break;
    }

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int retorno, len, i, id, horasTrabajadas, sueldo;
	char nombre[128];
	Employee* pEmployee;

	retorno = 1;

	len = ll_len(pArrayListEmployee);
	pFile=fopen(path, "w");

	if(pFile==NULL){
		retorno = -1;
	}else{
		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
		for(i=0;i<len;i++){
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(pEmployee, &id);
			employee_getNombre(pEmployee, nombre);
			employee_getHorasTrabajadas(pEmployee, &horasTrabajadas);
			employee_getSueldo(pEmployee, &sueldo);

			fprintf(pFile, "%d,%s,%d,%d\n", id,nombre,horasTrabajadas,sueldo);
		}
		fclose(pFile);
	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int retorno, len, i;
	Employee* pEmployee;

	retorno = 1;

	len = ll_len(pArrayListEmployee);
	pFile=fopen(path, "wb");

	if(pFile==NULL){
		retorno = -1;
	}else{
		for(i=0;i<len;i++){
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

			if(fwrite(pEmployee, sizeof(Employee), 1, pFile)!=1){
				retorno=-1;
				break;
			}
		}
		fclose(pFile);
	}

	return retorno;
}

