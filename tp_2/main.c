/*
 * main.c
 *
 *  Created on: 24 abr. 2020
 *      Author: mfs
 */
#include "funciones.h"
#include "ArrayEmployees.h"
#include <stdio.h>


int main(){
	int opcion, id, returnValue;
	Employee empleados[LEN];

	if(initEmployees(empleados, LEN)==0){

		opcion = menuPrincipal();
		while(opcion!=5){
			switch(opcion){
				case 1:
					if(newEmployee(empleados, LEN)==0){
						printf("\nEmpleado agregado con éxito!");
					}else{
						printf("\nAlgo salió mal");
					}
					break;
				case 2:
					updateEmployee(empleados, LEN);
					break;
				case 3:
					id = getInt("\nIngrese id del empleado a eliminar: ");
					returnValue = removeEmployee(empleados, LEN, id);
					switch(returnValue){
						case -2:
							printf("\nNo se eliminó al empleado. Operacion cancelada por el usuario");
							break;
						case -1:
							printf("\nNo se eliminó al empleado. Operacion cancelada por el usuario");
							break;
						case 0:
							printf("\nEmpleado eliminado con éxito!");
					}
					break;
				case 4:
					sortEmployees(empleados, LEN, 1);
					printEmployees(empleados, LEN);
					break;
			}

			opcion = menuPrincipal();
		}

		printf("\n Saliendo...");

	}else{
		printf("\nError de inicializacion de datos");
	}

	return 0;
}
