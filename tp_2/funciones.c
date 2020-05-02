/*
 * funciones.c
 *
 *  Created on: 24 abr. 2020
 *      Author: mfs
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int getInt(char mensaje[]){
	int i, fail;
	char numero[6];

	fail=0;

	do{
		if(fail==1){
			printf("\nError!");
			fail=0;
		}
		printf("\n%s", mensaje);

		do{
			__fpurge(stdin);
			fgets(numero, 7, stdin);
		}while(numero[0]=='\n' || numero[0]=='\0');

		if(numero[0]=='-' || numero[0]=='+'){
			numero[strlen(numero)] = '\0';
			for(i=1;i<(strlen(numero)-1);i++)
			{
				if(numero[i]<'0' || numero[i]>'9'){
					fail = 1;
				}
			}
		}else{
			numero[strlen(numero)-1] = '\0';
			for(i=0;i<(strlen(numero));i++)
			{
				if(numero[i]<'0' || numero[i]>'9'){
					fail = 1;
				}
			}
		}

	}while(fail==1);

	return atoi(numero);
}

int menuPrincipal(){
	int opcion;

	do{
		printf("\n\nMenu:");
		printf("\n==================================================");
		printf("\n1- ALTAS - Ingresar un nuevo empleado");
		printf("\n2- MODIFICAR - Cambiar datos de un empleado");
		printf("\n3- BAJA - Eliminar empleado");
		printf("\n4- INFORMAR - Mostrar la información disponible");
		printf("\n5- Salir\n");

		opcion = getInt("Ingrese opcion: ");

		if (opcion<1 || opcion>5)
		{
			printf("\nOpcion incorrecta. Ingrese nuevamente: ");
			opcion = getInt("Ingrese opcion: ");
		}
	}while(opcion<1 || opcion>5);

	return opcion;
}

int menuModificar(){
	int opcion;

	do{
		printf("\n\nModificar empleado:");
		printf("\n==================================");
		printf("\n1- Modificar nombre");
		printf("\n2- Modificar apellido");
		printf("\n3- Modificar salario");
		printf("\n4- Modificar sector");
		printf("\n5- Cancelar modificación");
		printf("\n6- Guardar y salir");

		opcion = getInt("Ingrese opcion: ");

		if (opcion<1 || opcion>6)
		{
			printf("\nOpcion incorrecta. Ingrese nuevamente: ");
			opcion = getInt("Ingrese opcion: ");
		}
	}while(opcion<1 || opcion>6);

	return opcion;
}
