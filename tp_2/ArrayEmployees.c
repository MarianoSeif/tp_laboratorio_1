/*
 * ArrayEmployees.c
 *
 *  Created on: 24 abr. 2020
 *      Author: Mariano Seif
 *      Curso: 1F
 *      Legajo: 110070
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
	if(list==NULL || len>1000 || len<1){
		return -1;
	}else{
		int i;
		for(i=0;i<len;i++){
			list[i].id = -1;
			list[i].isEmpty = 1;
		}
	}
	return 0;
}


/*
* \brief Impime un solo empleado
* \param list puntero a la lista de empleados
* \param len tamaño del array
* \param header - 1 imprimie un encabezado - 0 no imprime un encabezado
* \return 0
*/
int printOneEmployee(Employee* list, int index, int header)
{
	if(header){
		printf("\n%5s%15s%15s%15s%10s","Id","Nombre","Apellido","Salario","Sector");
	}
	printf("\n%5d%15s%15s%15.2f%10d", list[index].id, list[index].name, list[index].lastName, list[index].salary, list[index].sector);
	return 0;
}

/*
* \brief print the content of employees array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return 0
*
*/
int printEmployees(Employee* list, int length)
{
	int i;

	//printf("\nId\tNombre\tApellido\tSalario\t\tSector");
	printf("\n%5s%15s%15s%15s%10s","Id","Nombre","Apellido","Salario","Sector");
	for(i=0;i<length;i++){
		if(list[i].isEmpty!=1) printOneEmployee(list, i, 0);
	}
	return 0;
}

/*
* \brief Genera un id autoincremental para la lista de empleados
* \param list puntero a la lista de empleados
* \param len tamaño del array
* \return int Devuelve el valor del próximo id a ser utilizado
*/
int generateId(Employee* list, int len){
	int i, maxId;
	maxId=0;
	for(i=0;i<len;i++){
		if(list[i].id!=-1){
			if(list[i].id>maxId || i==0){
				maxId=list[i].id;
			}
		}
	}
	return maxId+1;
}

/** \brief add in a existing list of employees the values received as parameters
*			in the first empty position
* \param list Employee* Pointer to array of employees
* \param len int array lenght
* \param id int id of the employee
* \param name[] char pointer to the name of the employee
* \param lastName[] char pointer to the last name of the employee
* \param salary float salary of the employee
* \param sector int sector of the employee
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
*				free space] - (0) if Ok
**/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int index;
	if(list==NULL || len>1000 || len<1){
		return -1;
	}else{
		index = findFirstFreeIndex(list, len);
		if(index == -1){
			return -1;
		}else{
			list[index].id = id;
			strcpy(list[index].name, name);
			strcpy(list[index].lastName, lastName);
			list[index].salary = salary;
			list[index].sector = sector;
			list[index].isEmpty = 0;
		}
	}
	return 0;
}


/*
* \brief Encuentra el primer lugar libre en el array
* \param list puntero a la lista de empleados
* \param len tamaño del array
* \return int Devuelve el indice del lugar liber encontrado o -1 si no hay mas lugar
*/
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


/*
* \brief Recibe los datos del usuario para crear un nueo registro
* \param list puntero a la lista de empleados
* \param len tamaño del array
* \return int Devuelve 0 en caso de éxito y -1 en caso de error
*/
int newEmployee(Employee* list, int len)
{
	int id, index, valorRetornoAddEmployee;
	Employee empleado;

	index = findFirstFreeIndex(list, len); //Busco lugar en el array antes de pedir los datos
	if(index == -1){
		printf("\nError!. No hay lugar para almacenar mas empleados");
		return -1;
	}else{
		getString("Ingrese nombre: ", empleado.name, 51);
		getString("Ingrese apellido: ", empleado.lastName, 51);
		empleado.salary = getFloat("Ingrese salario: ");
		while(empleado.salary < 0){
			printf("\nError. Ingrese nuevamente");
			empleado.salary = getFloat("Ingrese salario: ");
		}
		empleado.sector = getInt("\nIngrese sector: ");
		while(empleado.sector < 0){
			printf("\nError. Ingrese nuevamente");
			empleado.sector = getInt("\nIngrese sector: ");
		}

		id = generateId(list, len);
		valorRetornoAddEmployee = addEmployee(list, len, id, empleado.name, empleado.lastName, empleado.salary, empleado.sector);

		if(valorRetornoAddEmployee == -1){
			printf("\nNo se pudo agregar empleado.");
			return -1;
		}
		return 0;
	}
}


/** \brief find an Employee by Id and returns the index position in array.
*
* \param list Employee* Pointer to array of employees
* \param len int array lenght
* \param id int id of the employee
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
	int i;
	if(list==NULL || len>1000 || len<1){
		printf("\nNo se encontró al empleado");
		return -1;
	}else{
		for(i=0;i<len;i++){
			if(list[i].id == id && list[i].isEmpty != 1){
				return i;
			}
		}
	}
	return -1;
}

/*
* \brief Remove a Employee by Id (put isEmpty Flag in 1)
* \param list Employee* Pointer to array of employees
* \param len int array lenght
* \param id int id of the employee
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*/
int removeEmployee(Employee* list, int len, int id)
{
	int index;
	char opcion;

	if(list==NULL || len>1000 || len<1){
		return -1;
	}else{
		index = findEmployeeById(list, len, id);
		if(index==-1){
			printf("\nNo se encontró al empleado");
			return -1;
		}else{
			printOneEmployee(list, index,1);

			printf("\nEstá seguro que desea eliminar al empleado?(S/N): ");
			__fpurge(stdin);
			scanf("%c", &opcion);
			if(tolower(opcion)=='s'){
				list[index].isEmpty = 1;
			}else{
				printf("\nOperación cancelada");
				return -1;
			}
		}
	}
	return 0;
}

/*
* \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
* \param list Employee* Pointer to array of employees
* \param len int array lenght
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
	int i,j;

	if(list==NULL || len>1000 || len<1){
		return -1;
	}else{
		for(i=0;i<(len-1);i++){
			for(j=i+1;j<len;j++){
				if(order==1){
					if(strcmp(list[i].lastName, list[j].lastName) > 0 ){
						swapEmployees(list, len, i, j);
					}else if(strcmp(list[i].lastName, list[j].lastName) == 0 ){
						if(list[i].sector > list[j].sector){
							swapEmployees(list, len, i, j);
						}
					}
				}else if(order==0){
					if(strcmp(list[i].lastName, list[j].lastName) < 0 ){
						swapEmployees(list, len, i, j);
					}else if(strcmp(list[i].lastName, list[j].lastName) == 0 ){
						if(list[i].sector < list[j].sector){
							swapEmployees(list, len, i, j);
						}
					}
				}
			}
		}
	}

	return 0;
}


/*
* \brief Intercambia el orden de los registro en el array
* \param list puntero a la lista de empleados
* \param len tamaño del array
* \param i indice del primer elemento
* \param j indice del segundo elemento
* \return int Devuelve 0
*/
int swapEmployees(Employee* list, int len, int i, int j)
{
	Employee auxEmployee;
	auxEmployee=list[i];
	list[i]=list[j];
	list[j]=auxEmployee;
	return 0;
}


/*
* \brief Modifica los datos de un empleado seleccionado por el usuario
* \param list puntero a la lista de empleados
* \param len tamaño del array
* \param i indice del primer elemento
* \param j indice del segundo elemento
* \return int Devuelve 0
*/
int updateEmployee(Employee* list, int len){
	int opcion, index, id;
	char cancel;
	Employee auxEmployee;

	cancel='n';
	printEmployees(list, len);
	id = getInt("\nIngrese el id del empleado que desea modificar: ");
	index = findEmployeeById(list, len, id);
	if(index == -1){
		printf("\nError!. El empleado no existe");
		return -1;
	}else{
		auxEmployee = list[index]; //Guardo una copia del registro en caso que se cancele la modificación
		printOneEmployee(list, index,1);

		opcion = menuModificar();

		while(opcion!=6){
			switch(opcion){
				case 1:
					getString("Ingrese nombre: ", list[index].name, 51);
					printOneEmployee(list, index,1);
					break;
				case 2:
					getString("Ingrese apellido: ", list[index].lastName, 51);
					printOneEmployee(list, index,1);
					break;
				case 3:
					list[index].salary = getFloat("Ingrese salario: ");
					while(list[index].salary < 0){
						printf("\nError. Ingrese nuevamente");
						list[index].salary = getFloat("Ingrese salario: ");
					}
					printOneEmployee(list, index,1);
					break;
				case 4:
					list[index].sector = getInt("\nIngrese sector: ");
					while(list[index].sector < 0){
						printf("\nError. Ingrese nuevamente");
						list[index].sector = getInt("\nIngrese sector: ");
					}
					printOneEmployee(list, index,1);
					break;
				case 5:
					printf("\nEstá seguro que desea cancelar la modificación?(S/N): ");
					__fpurge(stdin);
					scanf("%c", &cancel);
					if(tolower(cancel)=='s'){
						list[index]=auxEmployee;
						opcion=6;
					}
					printf("\nModificación cancelada");
					return -1;
					break;
			}
			opcion = menuModificar();
		}
	}
	printOneEmployee(list, index,0);
	return 0;
}


/*
* \brief Calcula los datos para el informe
* \param list puntero a la lista de empleados
* \param len tamaño del array
* \return int Devuelve 0
*/
int calculateData(Employee* list, int len){
	int i, contadorEmpleados, empleadosConSalarioMayorAlPromedio;
	float acumuladorSalario, salarioPromedio;
	acumuladorSalario=0;
	contadorEmpleados=0;
	empleadosConSalarioMayorAlPromedio=0;

	//Total y promedio de los salarios
	for(i=0;i<len;i++){
		if(list[i].isEmpty!=1){
			acumuladorSalario+=list[i].salary;
			contadorEmpleados++;
		}
	}
	salarioPromedio=acumuladorSalario/contadorEmpleados;

	//Cantidad de empleados que superan el salario promedio
	for(i=0;i<len;i++){
		if(list[i].isEmpty != 1 && list[i].salary>salarioPromedio){
			empleadosConSalarioMayorAlPromedio++;
		}
	}

	printf("\n\n--> El total de los salarios es: %.2f", acumuladorSalario);
	printf("\n--> EL salario promedio es: %.2f", salarioPromedio);
	printf("\n--> La cantidad de empleados con salario mayor al promedio es: %d", empleadosConSalarioMayorAlPromedio);
	return 0;
}


