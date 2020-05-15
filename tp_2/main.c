/*
 * main.c
 *
 *  Created on: 24 abr. 2020
 *      Author: Mariano Seif
 *      Curso: 1F
 *      Legajo: 110070
 */
#include "funciones.h"
#include "ArrayEmployees.h"
#include <stdio.h>

#define LEN 1000 //largo del array de empleados

int main(){
	int opcion, id, loadedArrayFlag;
	Employee empleados[LEN];
	loadedArrayFlag = 0;

	if(initEmployees(empleados, LEN)==0){

		opcion = menuPrincipal();
		while(opcion!=5){
			switch(opcion){
				case 1:
					printf("\n================ CARGAR EMPLEADO =================");
					if(newEmployee(empleados, LEN)==0){
						printf("\n\t-->Empleado agregado con éxito!");
						loadedArrayFlag = 1;
					}else{
						printf("\n\t-->Algo salió mal");
					}
					break;
				case 2:
					if(loadedArrayFlag){
						printf("\n=============== MODIFICAR EMPLEADO ===============");
						if(updateEmployee(empleados, LEN)==-1){
							printf("\n\t-->No se guardaron los cambios");
						}else{
							printf("\n\n\t-->Modificación guardada con éxito!");
						}
					}else{
						printf("\n\t-->No hay empleados cargados");
					}
					break;
				case 3:
					if(loadedArrayFlag){
						printf("\n=============== ELIMINAR EMPLEADO ===============");
						printEmployees(empleados, LEN);
						id = getInt("\nIngrese id del empleado a eliminar: ");
						if(removeEmployee(empleados, LEN, id)==-1){
							printf("\n\t-->No se eliminó al empleado");
						}else{
							printf("\n\t-->Empleado eliminado con éxito!");
						}
					}else{
						printf("\n\t-->No hay empleados cargados");
					}
					break;
				case 4:
					if(loadedArrayFlag){
						printf("\n============== LISTADO DE EMPLEADOS ==============");
						sortEmployees(empleados, LEN, 1);
						printEmployees(empleados, LEN);
						calculateData(empleados, LEN);
					}else{
						printf("\n\t-->No hay empleados cargados");
					}
					break;
			}
			opcion = menuPrincipal();
		}
		printf("\n\t-->Saliendo...");

	}else{
		printf("\n\t-->Error de inicialización de datos");
	}

	return 0;
}
