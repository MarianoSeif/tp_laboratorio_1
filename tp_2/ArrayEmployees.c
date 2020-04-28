/*
 * ArrayEmployees.c
 *
 *  Created on: 24 abr. 2020
 *      Author: mfs
 */

#include "ArrayEmployees.h"
#include "funciones.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

/** \brief To indicate that all position in the array are empty,
* 			this function put the flag (isEmpty) in TRUE in all
*			position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
	if(list==NULL || len>1000){
		return -1;
	}else{
		int i;
		for(i=0;i<len;i++){
			list[i].id = i;
			list[i].isEmpty = 1;
		}
		return 0;
	}
}


/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length)
{
	int i;

	printf("\nId\tNombre\tApellido\tSalario\t\tSector");
	for(i=0;i<length;i++){
		if(list[i].isEmpty!=1) printOneEmployee(list, i);
	}
	return 0;
}

int printOneEmployee(Employee* list, int index)
{
	printf("\n%d\t%s\t%s\t%.2f\t%d", list[index].id, list[index].name, list[index].lastName, list[index].salary, list[index].sector);
	return 0;
}


int generateId(Employee* list, int len){
	int i, maxId;
	for(i=0;i<len;i++){
		if(list[i].id>maxId || i==0){
			maxId=list[i].id;
		}
	}
	return maxId+1;
}

/** \brief add in a existing list of employees the values received as parameters
*			in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
*				free space] - (0) if Ok
**/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int index;
	index = findFirstFreeIndex(list, len);
	if(index!=-1){
		list[index].id = id;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		list[index].salary = salary;
		list[index].sector = sector;
		list[index].isEmpty = 0;
	}else{
		return -1;
	}

	return 0;
}

int findFirstFreeIndex(Employee* list, int len)
{
	int i;
	for(i=0;i<len;i++){
		if(list[i].isEmpty == 1){
			return i;
		}
	}
	return -1;
}

int newEmployee(Employee* list, int len)
{
	int id, index, valorRetornoAddEmployee;
	Employee empleado;

	index = findFirstFreeIndex(list, len);
	if(index == -1){
		return -1;
	}else{
		printf("\nIngrese nombre: ");
		__fpurge(stdin);
		fgets(empleado.name, 51, stdin);
		empleado.name[strlen(empleado.name)-1] = '\0';
		printf("\nIngrese apellido: ");
		__fpurge(stdin);
		fgets(empleado.lastName, 51, stdin);
		empleado.lastName[strlen(empleado.lastName)-1] = '\0';
		printf("\nIngrese salario: ");
		scanf("%f", &empleado.salary);
		empleado.sector = getInt("\nIngrese sector: ");

		id = generateId(list, len);
		valorRetornoAddEmployee = addEmployee(list, len, id, empleado.name, empleado.lastName, empleado.salary, empleado.sector);

		if(valorRetornoAddEmployee == -1){
			return -2;
		}

		return 0;
	}
}

/** \brief find an Employee by Id and returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
	int i;
	for(i=0;i<len;i++){
		if(list[i].id == id && list[i].isEmpty != 1){
			return i;
		}
	}

	return -1;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
	int index;
	char opcion;

	index = findEmployeeById(list, len, id);

	printf("\nId\tNombre\tApellido\tSalario\t\tSector");
	printOneEmployee(list, index);

	printf("\nEstá seguro que desea eliminar al empleado?(S/N): ");
	scanf("%c", &opcion);
	if(tolower(opcion)=='s'){
		list[index].isEmpty = 1;
		return 0;
	}

	return -2;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
	int i,j;
	Employee auxEmployee;

	for(i=0;i<(len-1);i++){
		for(j=i+1;j<len;j++){
			if(order==1){
				if(strcmp(list[i].lastName, list[j].lastName) > 0 ){
					auxEmployee=list[i];
					list[i]=list[j];
					list[j]=auxEmployee;
				}else if(strcmp(list[i].lastName, list[j].lastName) == 0 ){
					if(list[i].sector > list[j].sector){
						auxEmployee=list[i];
						list[i]=list[j];
						list[j]=auxEmployee;
					}
				}
			}else if(order==0){
				if(strcmp(list[i].lastName, list[j].lastName) < 0 ){
					auxEmployee=list[i];
					list[i]=list[j];
					list[j]=auxEmployee;
				}else if(strcmp(list[i].lastName, list[j].lastName) == 0 ){
					if(list[i].sector < list[j].sector){
						auxEmployee=list[i];
						list[i]=list[j];
						list[j]=auxEmployee;
					}
				}
			}
		}
	}

	return 0;
}

int updateEmployee(Employee* empleados, int len){
	int opcion, index, id;
	char cancel;
	Employee auxEmployee;

	cancel='n';

	id = getInt("\nIngrese el id del empleado que desea modificar: ");
	index = findEmployeeById(empleados, len, id);
	if(index == -1){
		return -1;
	}else{
		auxEmployee = empleados[index];
		printf("\nId\tNombre\tApellido\tSalario\t\tSector");
		printOneEmployee(empleados, index);

		opcion = menuModificar();

		while(opcion!=6){
			switch(opcion){
				case 1:
					printf("\nIngrese nuevo nombre: ");
					__fpurge(stdin);
					fgets(empleados[index].name, 51, stdin);
					empleados[index].name[strlen(empleados[index].name)-1] = '\0';
					printf("\nId\tNombre\tApellido\tSalario\t\tSector");
					printOneEmployee(empleados, index);
					break;
				case 2:
					printf("\nIngrese apellido: ");
					__fpurge(stdin);
					fgets(empleados[index].lastName, 51, stdin);
					empleados[index].lastName[strlen(empleados[index].lastName)-1] = '\0';
					printf("\nId\tNombre\tApellido\tSalario\t\tSector");
					printOneEmployee(empleados, index);
					break;
				case 3:
					printf("\nIngrese salario: ");
					scanf("%f", &empleados[index].salary);
					printf("\nId\tNombre\tApellido\tSalario\t\tSector");
					printOneEmployee(empleados, index);
					break;
				case 4:
					empleados[index].sector = getInt("\nIngrese sector: ");
					printf("\nId\tNombre\tApellido\tSalario\t\tSector");
					printOneEmployee(empleados, index);
					break;
				case 5:
					printf("\nEstá seguro que desea cancelar la modificación?(S/N): ");
					scanf("%c", &cancel);
					if(tolower(cancel)=='s'){
						empleados[index]=auxEmployee;
						opcion=6;
					}
					printf("\nModificación cancelada");
					break;
				default:
					printf("\nIngrese una opción válida");
					break;
				}

			if(cancel!='s'){
				opcion = menuModificar();
			}
		}
		if(opcion==6 && cancel!='s'){
			printf("Modificación guardada con éxito!");
			printOneEmployee(empleados, index);
		}

		return 0;
	}
}
