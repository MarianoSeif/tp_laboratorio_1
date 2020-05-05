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
	int opcion, id, emptyArrayFlag;
	Employee empleados[LEN];
	emptyArrayFlag = 1;

	if(initEmployees(empleados, LEN)==0){

		opcion = menuPrincipal();
		while(opcion!=5){
			switch(opcion){
				case 1:
					if(newEmployee(empleados, LEN)==0){
						printf("\nEmpleado agregado con éxito!");
						emptyArrayFlag = 0;
					}else{
						printf("\nAlgo salió mal");
					}
					break;
				case 2:
					if(emptyArrayFlag!=1){
						if(updateEmployee(empleados, LEN)==-1){
							printf("\nNo se guardaron los cambios");
						}else{
							printf("\n\nModificación guardada con éxito!");
						}
					}
					break;
				case 3:
					if(emptyArrayFlag!=1){
						id = getInt("\nIngrese id del empleado a eliminar: ");
						if(removeEmployee(empleados, LEN, id)==-1){
							printf("\nNo se eliminó al empleado");
						}else{
							printf("\nEmpleado eliminado con éxito!");
						}
					}
					break;
				case 4:
					if(emptyArrayFlag!=1){
						printf("\n============== LISTADO DE EMPLEADOS ==============");
						sortEmployees(empleados, LEN, 1);
						printEmployees(empleados, LEN);
						calculateData(empleados, LEN);
					}
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
