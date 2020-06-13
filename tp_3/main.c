#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"

#include <string.h>
/*
 * main.c
 *
 *  Created on: 1 jun. 2020
 *      Author: Mariano Seif
 *      Curso: 1F
 *      Legajo: 110070
 */


int main()
{
	int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        option = menuPrincipal();

    	switch(option)
        {
            case 1:
                if(!ll_isEmpty(listaEmpleados)){
                	printf("\nYa hay datos cargados en el listado, si procede los datos serán eliminados");

                	if(fcontinuar()==0){
                		break;
                	}else{
                		if(ll_clear(listaEmpleados)!=0){
                			printf("\nNo se pudo eliminar la lista");
                		}
                	}
                }
                if(controller_loadFromText("data.csv",listaEmpleados)==-1){
					printf("\nError al abrir el archivo o el archivo no existe");
				}else{
					printf("\nArchivo cargado con éxito!");
				}
                break;
            case 2:
            	if(!ll_isEmpty(listaEmpleados)){
					printf("\nYa hay datos cargados en el listado, si procede los datos serán eliminados");

					if(fcontinuar()==0){
						break;
					}else{
						if(ll_clear(listaEmpleados)!=0){
							printf("\nNo se pudo eliminar la lista");
						}
					}
				}
				if(controller_loadFromBinary("data.bin", listaEmpleados)==-1){
					printf("\nError al abrir el archivo o el archivo no existe");
				}else{
					printf("\nArchivo cargado con éxito!");
				}
				break;

            case 3:
				if(controller_addEmployee(listaEmpleados)==-1){
					printf("\nError. No se pudo agregar al empleado");
				}else{
					printf("\nEl empleado fue agregado con éxito!");
				}
				break;
            case 4:
            	if(ll_isEmpty(listaEmpleados)){
					printf("\nNo hay empleados para modificar. La lista está vacia");
            	}else{
					if(controller_editEmployee(listaEmpleados)==-1){
						printf("\nNo se modificó al empleado.");
					}else{
						printf("\nEmpleado modificado con éxito!");
					}
            	}
				break;
            case 5:
            	if(ll_isEmpty(listaEmpleados)){
					printf("\nNo hay empleados para eliminar. La lista está vacia");
				}else{
					if(controller_removeEmployee(listaEmpleados)==-1){
						printf("\nNo se eliminó al empleado.");
					}else{
						printf("\nEmpleado eliminado con éxito!");
					}
				}
				break;
            case 6:
            	if(ll_isEmpty(listaEmpleados)){
					printf("\nNo hay empleados para mostrar. La lista está vacia");
				}else{
					if(controller_ListEmployee(listaEmpleados)==-1){
						printf("\nOcurrió un error. No se puede mostrar la lista de empleados");
					}
				}
            	break;
            case 7:
            	if(ll_isEmpty(listaEmpleados)){
					printf("\nNo hay empleados para ordenar. La lista está vacia");
				}else{
					if(controller_sortEmployee(listaEmpleados)==-1){
						printf("\nOcurrió un error. No se pudo ordenar la lista de empleados");
					}else{
						printf("\nLa lista se ordenó");
					}
				}
				break;
            case 8:
            	if(ll_isEmpty(listaEmpleados)){
					printf("\nNo hay empleados para guardar. La lista está vacia");
				}else{
					printf("\nEstá a punto de sobreescribir el archivo");
					if(fcontinuar()){
						if(controller_saveAsText("data.csv", listaEmpleados)==-1){
							printf("\nOcurrió un error. No se pudo guardar en el archivo");
						}else{
							printf("\nArchivo guardado con éxito!");
						}
					}
				}
				break;
            case 9:
            	if(ll_isEmpty(listaEmpleados)){
					printf("\nNo hay empleados para guardar. La lista está vacia");
				}else{
					printf("\nEstá a punto de sobreescribir el archivo");
					if(fcontinuar()){
						if(controller_saveAsBinary("data.bin", listaEmpleados)==-1){
							printf("\nOcurrió un error. No se pudo guardar en el archivo");
						}else{
							printf("\nArchivo guardado con éxito!");
						}
					}
				}
				break;
        }

    }while(option != 10);

    ll_deleteLinkedList(listaEmpleados);
    return 0;
}

