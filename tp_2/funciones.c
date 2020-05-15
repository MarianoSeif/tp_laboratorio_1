/*
 * funciones.c
 *
 *  Created on: 24 abr. 2020
 *      Author: Mariano Seif
 *      Curso: 1F
 *      Legajo: 110070
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>


/*
* \brief Obtiene y valida un entero
* \param mensaje - mensaje a mostrar al usuario
* \return devuelve el valor ingresado en el caso que sea válido
*/
int getInt(char mensaje[])
{
	int i, sizeBuffer, fail;
	sizeBuffer = 10;
	char buffer[sizeBuffer];

	fail=0;

	do{
		if(fail==1){
			printf("\nError!");
			fail=0;
		}
		printf("\n%s", mensaje);

		__fpurge(stdin);
		fgets(buffer, sizeBuffer+1, stdin);

		if(strlen(buffer)==1){
		    fail=1;
		}else{
		    buffer[strlen(buffer)-1] = '\0';
            if(buffer[0]=='-' || buffer[0]=='+'){
    		    i=1;
    		}else{
    		    i=0;
    		}

    		for(;i<strlen(buffer);i++){
    			if(buffer[i]<'0' || buffer[i]>'9'){
    				fail = 1;
    			}
    		}
		}

	}while(fail==1);

	return atoi(buffer);
}


/*
* \brief Obtiene y valida un numero en punto flotante
* \param mensaje - el mensaje a mostrar al usuario
* \return devuelve el valor ingresado en caso que sea válido
*/

float getFloat(char mensaje[]){

	int i, sizeBuffer, fail, puntos;
	sizeBuffer = 10;
	char buffer[sizeBuffer];

	fail=0;
	puntos=0;

	do{
		if(fail==1){
			printf("\nError!");
			fail=0;
			puntos=0;
		}
		printf("\n%s", mensaje);

		__fpurge(stdin);
		fgets(buffer, sizeBuffer+1, stdin);

		if(strlen(buffer)==1){
		    fail=1;
		}else{
            buffer[strlen(buffer)-1] = '\0';
        	if(buffer[0]=='-' || buffer[0]=='+'){
    		    i=1;
    		}else{
    		    i=0;
    		}

    		for(;i<strlen(buffer);i++)
    		{
    			if(buffer[i]<'0' || buffer[i]>'9'){
    			    if(buffer[i]=='.' && puntos==0){
    			        puntos++;
    			    }else{
    				    fail = 1;
    			    }
    			}
    		}
		}

	}while(fail==1);

	return atof(buffer);
}


/*
* \brief Obtiene un conjunto de palabras
* \param mensaje: el mensaje a mostrar al usuario
* \param string: puntero a cadena donde se almacenará el string ingresado
* \param size: tamaño del string
* \return 0 en caso de éxito
*/
int getString(char mensaje[], char string[], int size)
{
	int i, fail;

	fail=0;

	do{
		if(fail==1){
			printf("\nError!");
			fail=0;
		}
		printf("\n%s", mensaje);

		__fpurge(stdin);
		fgets(string, size+1, stdin);

		if(strlen(string)==1){
		    fail=1;
		}else{
            string[strlen(string)-1] = '\0';
            for(i=0;i<strlen(string);i++){
    		    if(!((string[i]>='a' && string[i]<='z') || (string[i]>='A' && string[i]<='Z') || string[i]==' ')) {
    			    fail = 1;
    		    }
    		}
    	}

	}while(fail==1);

	return 0;
}

/*
* \brief Muestra un menu en pantalla y lee la opción elegida por el usuario
* \return Devuelve una opción válida elegida por el usuario
*/
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

/*
* \brief Muestra un menu para modifcar empleado y lee la opción elegida por el usuario
* \return Devuelve una opción válida elegida por el usuario
*/
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
